#include <sl.h>

#include "Game.h"
#include "Ball.h"
#include "Brick.h"
#include "Fonts.h"
#include "Player.h"
#include "Structures.h"
#include "Input.h"
#include "GameManager.h"
#include "SceneManager.h"



void Game::Play()
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
        Update(player, ball, bricks);
        Draw(player, ball, bricks);
    }
    while (!GameManager::ShouldWindowClose() && !endMatch);

    if (playerWon)
    {
        //SceneManager::ChangeScene(SceneManager::Scenes::PlayerWon);
    }
    else
    {
        //SceneManager::ChangeScene(SceneManager::Scenes::PlayerLost);
    }

    ChangeScene(SceneManager::Scenes::MainMenu);
}



void Game::Init(Structures::Player &player, Structures::Ball &ball, Structures::Brick bricks[])
{
    Player::Spawn(player, sprites.Player);
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
    if(Input::IsKeyDown(SL_KEY_ESCAPE))
    {
        //ChangeScene(SceneManager::Scenes::Pause);
    }
}



void Game::Update(Structures::Player &player, Structures::Ball &ball, Structures::Brick bricks[])
{
    Player::Update(player);
    Ball::Update(player, ball);
    Brick::Update(bricks, ball);
}



void Game::Draw(Structures::Player &player, Structures::Ball &ball, Structures::Brick bricks[])
{

    /*
     * Player::Draw(player);
     * Ball::Draw(ball);
     * Brick::Draw(bricks)
     *
     */
    DrawUI(player);
    GameManager::Render();
}



void Game::DrawUI(const Structures::Player &player)
{
    const float MARGIN = 20.0F;
    const float WIDTH = 30.0F;
    const float HEIGHT = 15.0F;
    const float PADDING = 3.0F;
    const int FONT_SIZE = 30;

    Sprites::LoadSprite(
        sprites.HeartsBorder,
        {SCREEN_HEIGHT - MARGIN, MARGIN},
        {WIDTH, HEIGHT}
        );
    for (int heart = 0; heart < player.Hearts; heart++)
    {
        Sprites::LoadSprite(
                sprites.Heart,
                {MARGIN + WIDTH * heart + PADDING * (heart + 1), SCREEN_HEIGHT - MARGIN},
                {WIDTH, HEIGHT}
                );
    }

    Fonts::SetFont(fonts.Button);
    Fonts::ChangeFontSize(FONT_SIZE);
    Fonts::TextPrint({static_cast<float>(SCREEN_WIDTH - FONT_SIZE), SCREEN_HEIGHT - MARGIN}, std::to_string(player.Score));
}
