#include <sl.h>

#include "Game.h"

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


float timeAtStart;
float timer;

bool Game::Play()
{
    bool endMatch = false;
    bool returnMain = false;
    bool rotated = false;
    int activeBricks = Brick::MAX_BRICKS;

    Structures::Player player;
    Structures::Ball ball;
    Structures::Brick bricks[Brick::MAX_BRICKS];

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

    if(rotated)
    {
        Sprites::Translate({static_cast<float>(SCREEN_WIDTH), static_cast<float>(SCREEN_HEIGHT)});
        Sprites::Rotate(180);
    }

    return player.Won;
}


void Game::Init(Structures::Player &player, Structures::Ball &ball, Structures::Brick bricks[])
{
    Player::Spawn(player, sprites.PlayerIdle);
    player.Score = 0;
    player.Won = false;
    Ball::Spawn(ball, sprites.Ball);
    Brick::Generate(bricks);
}


void Game::Input(Structures::Player &player, bool &returnMain)
{

    constexpr float INVERT_TIME = 3.0F;

    if (Brick::GetActivePower() == Structures::SpecialBricks::InvertControls)
    {
        if (timer >= 0 && timer < INVERT_TIME)
        {
            if (Input::IsKeyDown(SL_KEY_RIGHT))
            {
                Player::MoveLeft(player);
            }
            else if (Input::IsKeyDown(SL_KEY_LEFT))
            {
                Player::MoveRight(player);
            }
        }
        else
        {
            Brick::SetActivePower( Structures::SpecialBricks::None);
        }
    }
    else
    {
        if (Input::IsKeyDown(SL_KEY_LEFT))
        {
            Player::MoveLeft(player);
        }
        else if (Input::IsKeyDown(SL_KEY_RIGHT))
        {
            Player::MoveRight(player);
        }
    }
    if (Input::IsKeyDown('P'))
    {
        Pause::Pause(returnMain);
    }
}


void Game::Update(Structures::Player &player, Structures::Ball &ball, Structures::Brick bricks[], bool &playerWon,
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
    case Structures::SpecialBricks::RotateScreen:
        __fallthrough
    case Structures::SpecialBricks::InvertControls:
        timer += GameManager::GetFrameTime();
        break;
    case Structures::SpecialBricks::OneUp:
        if (player.Hearts < 3)
        {
            player.Hearts++;
        }
        Brick::SetActivePower(Structures::SpecialBricks::None);
        break;
    case Structures::SpecialBricks::FasterPlayer:
        player.Speed += 100;
        Brick::SetActivePower(Structures::SpecialBricks::None);
        break;
    }
}


void Game::Draw(Structures::Player &player, Structures::Ball &ball, Structures::Brick bricks[], bool& rotated)
{
    constexpr float ROTATE_TIME = 5.0f;
    if (Brick::GetActivePower() == Structures::SpecialBricks::RotateScreen)
    {
        if (timer > ROTATE_TIME)
        {
            Sprites::Translate({static_cast<float>(SCREEN_WIDTH), static_cast<float>(SCREEN_HEIGHT)});
            Sprites::Rotate(180);
            timer = 0;
            Brick::SetActivePower(Structures::SpecialBricks::None);
            rotated = false;
        }
        else if (!rotated)
        {
            Sprites::Translate({static_cast<float>(SCREEN_WIDTH), static_cast<float>(SCREEN_HEIGHT)});
            Sprites::Rotate(180);
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


void Game::UpdateScore(Structures::Player &player, const float currentTime)
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


void Game::DrawUI(const Structures::Player &player)
{
    constexpr float MARGIN = 20.0F;
    constexpr float WIDTH = 40.0F;
    constexpr float HEIGHT = 40.0F;
    constexpr float PADDING = 5.0F;
    constexpr float BORDER_PADDING = 9.5F;
    constexpr int FONT_SIZE = 60;

    SetForeColor(Color::white, 1.0);

    for (int heart = 0; heart < Player::HEARTS; heart++)
    {
        Sprites::LoadSprite(
            sprites.HeartsBorder,
            {MARGIN + WIDTH * heart + BORDER_PADDING * (heart + 1) / 2.0F, SCREEN_HEIGHT - MARGIN},
            {WIDTH, HEIGHT}
            );
    }

    for (int heart = 0; heart < player.Hearts; heart++)
    {
        Sprites::LoadSprite(
            sprites.Heart,
            {MARGIN + WIDTH * heart + PADDING * (heart + 1), SCREEN_HEIGHT - MARGIN},
            {WIDTH, HEIGHT}
            );

    }

    SetForeColor(Color::coffee, 1.0);
    Fonts::SetFont(fonts.Body);
    Fonts::ChangeFontSize(FONT_SIZE);
    Fonts::TextPrint({static_cast<float>(SCREEN_WIDTH - FONT_SIZE), SCREEN_HEIGHT - MARGIN - FONT_SIZE},
                     std::to_string(player.Score));
}
