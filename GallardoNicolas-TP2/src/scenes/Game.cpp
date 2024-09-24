#include "Game.h"

#include <sl.h>

#include "Background.h"
#include "Ball.h"
#include "Brick.h"
#include "Fonts.h"
#include "Player.h"
#include "Structures.h"
#include "Input.h"
#include "GameManager.h"
#include "Pause.h"
#include "SceneManager.h"

using namespace Structures;
using namespace Sprites;

float timeAtStart;
float timer;

bool Game::Play()
{

    bool endMatch = false;
    bool returnMain = false;
    bool rotated = false;
    int activeBricks = Brick::MAX_BRICKS;

    PlayerType player;
    BallType ball;
    BrickType bricks[Brick::MAX_BRICKS];

    timeAtStart = GameManager::GetTime();

    Init(player, ball, bricks);
    Draw(player, ball, bricks, rotated);
    do
    {
        Input(player, returnMain);
        Update(player, ball, bricks, player.Won, endMatch, activeBricks);

        if (returnMain)
            continue;

        Draw(player, ball, bricks, rotated);

    }
    while (!GameManager::ShouldWindowClose() && !endMatch && !returnMain);

    if (!returnMain)
    {
        ChangeScene(SceneManager::Scenes::AfterGame);
    }

    if (rotated)
    {
        Translate({static_cast<float>(SCREEN_WIDTH), static_cast<float>(SCREEN_HEIGHT)});
        Rotate(180);
        rotated = false;
    }

    return player.Won;
}


void Game::Init(PlayerType &player, BallType &ball, BrickType bricks[])
{
    Player::Spawn(player, sprites.PlayerIdle);
    player.Score = 0;
    player.Won = false;

    Ball::Spawn(ball, sprites.Ball);

    Brick::Generate(bricks);
    Brick::SetActivePower(SpecialBricks::None);
    timer = 0;
}


void Game::Input(PlayerType &player, bool &returnMain)
{
    using namespace Input;

    constexpr float INVERT_TIME = 3.0F;

    if (Brick::GetActivePower() == SpecialBricks::InvertControls)
    {
        if (timer >= 0 && timer < INVERT_TIME)
        {
            if (IsKeyDown(SL_KEY_RIGHT))
            {
                Player::MoveLeft(player);
            }
            else if (IsKeyDown(SL_KEY_LEFT))
            {
                Player::MoveRight(player);
            }
        }
        else
        {
            Brick::SetActivePower(SpecialBricks::None);
            timer = 0;
        }
    }
    else
    {
        if (IsKeyDown(SL_KEY_LEFT))
        {
            Player::MoveLeft(player);
        }
        else if (IsKeyDown(SL_KEY_RIGHT))
        {
            Player::MoveRight(player);
        }
    }
    if (IsKeyDown('P'))
    {
        Pause::Pause(returnMain);
    }
}


void Game::Update(PlayerType &player, BallType &ball, BrickType bricks[], bool &playerWon,
                  bool &endMatch, int &activeBricks)
{

    Player::Update(player, ball);
    Ball::Update(player, ball);

    if (Brick::Update(bricks, ball, activeBricks))
    {
        UpdateScore(player, GameManager::GetTime());
    }
    ball.Position = ball.FuturePosition;
    ball.FuturePosition = ball.Position;

    if (ball.Position.Y < 0)
    {
        player.Hearts--;
        Ball::Spawn(ball, sprites.Ball);
    }
    if (player.Hearts == 0)
    {
        playerWon = false;
        endMatch = true;
    }
    else if (activeBricks == 0)
    {
        playerWon = true;
        endMatch = true;
    }

    switch (Brick::GetActivePower())
    {
    case SpecialBricks::RotateScreen:
        __fallthrough
    case SpecialBricks::InvertControls:
        timer += GameManager::GetFrameTime();
        break;
    case SpecialBricks::OneUp:
        if (player.Hearts < Player::HEARTS)
        {
            player.Hearts++;
        }
        Brick::SetActivePower(SpecialBricks::None);
        break;
    case SpecialBricks::FasterPlayer:
        player.Speed += 180;
        Brick::SetActivePower(SpecialBricks::None);
        break;
    }
}


void Game::Draw(PlayerType &player, BallType &ball, BrickType bricks[], bool &rotated)
{
    constexpr float ROTATE_TIME = 5.0f;
    if (Brick::GetActivePower() == SpecialBricks::RotateScreen)
    {
        if (timer > ROTATE_TIME)
        {
            Translate({static_cast<float>(SCREEN_WIDTH), static_cast<float>(SCREEN_HEIGHT)});
            Rotate(180);
            timer = 0;
            Brick::SetActivePower(SpecialBricks::None);
            rotated = false;
        }
        else if (!rotated)
        {
            Translate({static_cast<float>(SCREEN_WIDTH), static_cast<float>(SCREEN_HEIGHT)});
            Rotate(180);
            rotated = true;
        }
    }

    Background::Draw();
    Player::Draw(player);
    Ball::Draw(ball);
    Brick::Draw(bricks);
    DrawUI(player);

#ifdef _DEBUG
    slSetForeColor(1, 0, 0, 1);
    slRectangleOutline(player.Position.X, player.Position.Y, player.Width, player.Height);
    slRectangleOutline(ball.Position.X, ball.Position.Y, ball.Radius, ball.Radius);
    for (int i = 0; i < Brick::MAX_BRICKS; i++)
    {
        slRectangleOutline(bricks[i].Position.X, bricks[i].Position.Y, bricks[i].Size.X, bricks[i].Size.Y);
    }
    Fonts::TextPrint({20.0f, SCREEN_HEIGHT - 50.0f}, std::to_string(player.Speed));
    slSetForeColor(1, 1, 1, 1);
#endif

    GameManager::Render();
}


void Game::UpdateScore(PlayerType &player, const float currentTime)
{
    int score = 40;

    constexpr float MIN_TIME = 60.0F;
    constexpr int MAX_SCORE_PER_BLOCK = 100;
    if (currentTime - timeAtStart < MIN_TIME)
    {
        score = MAX_SCORE_PER_BLOCK - (currentTime - timeAtStart);
    }

    player.Score += score;

}


void Game::DrawUI(const PlayerType &player)
{
    using namespace Sprites;

    constexpr float MARGIN = 20.0F;
    constexpr float WIDTH = 40.0F;
    constexpr float HEIGHT = 40.0F;
    constexpr float PADDING = 5.0F;
    constexpr float BORDER_PADDING = 9.5F;
    constexpr float FONT_SIZE = 60;
    constexpr VectorMath::Vector2 BANNER_SIZE = {150, 120};

    SetForeColor(Color::WHITE, 1.0);

    for (int heart = 0; heart < Player::HEARTS; heart++)
    {
        LoadSprite(
            sprites.HeartsBorder,
            {MARGIN + WIDTH * heart + BORDER_PADDING * (heart + 1) / 2.0F, SCREEN_HEIGHT - MARGIN},
            {WIDTH, HEIGHT}
            );
    }

    for (int heart = 0; heart < player.Hearts; heart++)
    {
        LoadSprite(
            sprites.Heart,
            {MARGIN + WIDTH * heart + PADDING * (heart + 1), SCREEN_HEIGHT - MARGIN},
            {WIDTH, HEIGHT}
            );

    }


    SetForeColor(Color::WHITE, 1.0);
    Fonts::SetFont(fonts.Body);
    Fonts::ChangeFontSize(FONT_SIZE);
    LoadSprite(
        sprites.ScoreBack,
        {SCREEN_WIDTH - FONT_SIZE, SCREEN_HEIGHT - FONT_SIZE},
        BANNER_SIZE
        );
    Fonts::TextPrint({(SCREEN_WIDTH - FONT_SIZE), SCREEN_HEIGHT - MARGIN - FONT_SIZE},
                     std::to_string(player.Score));
}
