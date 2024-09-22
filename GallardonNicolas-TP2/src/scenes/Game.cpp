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


bool Game::Play()
{
    bool endMatch = false;
    bool playerWon = false;

    Structures::Player player;
    Structures::Ball ball;
    Structures::Brick bricks[Brick::MAX_BRICKS];

    Init(player, ball, bricks);
    Draw(player, ball, bricks);
    do
    {
        Input(player);
        Update(player, ball, bricks, playerWon, endMatch);
        Draw(player, ball, bricks);
    }
    while (!GameManager::ShouldWindowClose() && !endMatch);

    ChangeScene(SceneManager::Scenes::AfterGame);
    return playerWon;
}


void Game::Init(Structures::Player &player, Structures::Ball &ball, Structures::Brick bricks[])
{
    Player::Spawn(player, sprites.PlayerLeft);
    Ball::Spawn(ball, sprites.Ball);
    Brick::Generate(bricks);
}


void Game::Input(Structures::Player &player)
{
    if (Input::IsKeyDown(SL_KEY_LEFT))
    {
        Player::MoveLeft(player);
    }
    else if (Input::IsKeyDown(SL_KEY_RIGHT))
    {
        Player::MoveRight(player);
    }
    if (Input::IsKeyDown('P'))
    {
        Pause::Pause();
    }
}


void Game::Update(Structures::Player &player, Structures::Ball &ball, Structures::Brick bricks[], bool &playerWon,
                  bool &endMatch)
{
    Player::Update(player);
    Ball::Update(player, ball);
    int activeBricks = Brick::Update(bricks, ball);
    int score = UpdateScore(player, GameManager::GetTime(), activeBricks);

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
}


void Game::Draw(Structures::Player &player, Structures::Ball &ball, Structures::Brick bricks[])
{
    Background::Draw();
    Player::Draw(player, Player::Direction::Left);
    Ball::Draw(ball);
    Brick::Draw(bricks);
    DrawUI(player);
#ifdef _DEBUG
    slSetForeColor(1,0,0,1);
    slRectangleOutline(player.Position.X, player.Position.Y, player.Width, player.Height);
    slRectangleOutline(ball.Position.X, ball.Position.Y, ball.Radius, ball.Radius);
    slSetForeColor(1,1,1,1);
#endif
    GameManager::Render();
}


int Game::UpdateScore(Structures::Player &player, const float time, const int activeBricks)
{
    int score = 40;

    const float MIN_TIME = 60.0F;
    const int MAX_SCORE_PER_BLOCK = 100;
    if (time > MIN_TIME)
    {
        score = MAX_SCORE_PER_BLOCK - time;
    }

    player.Score = (Brick::MAX_BRICKS - activeBricks) * score;

    return score;
}


void Game::DrawUI(const Structures::Player &player)
{
    const float MARGIN = 20.0F;
    const float WIDTH = 30.0F;
    const float HEIGHT = 30.0F;
    const float PADDING = 5.0F;
    const float BORDER_PADDING = 9.5F;
    const int FONT_SIZE = 60;

    SetForeColor(Color::white, 1.0);

    for (int heart = 0; heart < Player::HEARTS; heart++)
    {
        Sprites::LoadSprite(
            sprites.HeartsBorder,
            {MARGIN + (WIDTH * heart) + BORDER_PADDING * (heart + 1) / 2.0F, SCREEN_HEIGHT - MARGIN},
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
