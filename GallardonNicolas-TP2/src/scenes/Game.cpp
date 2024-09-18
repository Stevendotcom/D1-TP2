#include "Game.h"

#include <sl.h>

#include "Wrapper.h"
#include "Player.h"
#include "Ball.h"
#include "Brick.h"

void Game::Play()
{
    bool endMatch = false;
    bool playerWon = false;

    Player::Player player;
    Ball::Ball ball;
    Brick::Brick bricks[Brick::MAX_BRICKS];

    Init(player, ball, bricks);
    Draw();
    do
    {
        Input(player);
        Update(player, ball);
        Draw();
    }
    while (!Wrapper::ShouldWindowClose() & !endMatch);
}

void Game::Init(Player::Player& player, Ball::Ball& ball, Brick::Brick bricks[])
{
    //todo move all textures to a single file, so it only gets called once
    Wrapper::Texture playerSprite = Wrapper::LoadTexture(ASSETS_DIR + "pathtoplayer");
    Wrapper::Texture ballSprite = Wrapper::LoadTexture(ASSETS_DIR + "pathtoplayer");

    Player::Spawn(player, playerSprite);
    Ball::Spawn(ball, ballSprite);
    Brick::Generate(bricks);
}

void Game::Input(Player::Player& player)
{
    if(Wrapper::IsKeyDown(SL_KEY_LEFT))
    {
        Player::MoveLeft(player);
    }
    else if(Wrapper::IsKeyDown(SL_KEY_RIGHT))
    {
        Player::MoveRight(player);
    }
    //other input
}

void Game::Update(Player::Player& player, Ball::Ball& ball)
{
    Player::Update(player);
    Ball::Update(player, ball);
    //Brick::Update(bricks)
}

void Game::Draw()
{
    //todo
}
