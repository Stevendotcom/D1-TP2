#include "Game.h"
#include "Ball.h"
#include "Brick.h"
#include "Player.h"
#include "Structures.h"
#include "Wrapper.h"

#include <sl.h>


void Game::Play()
{
    const bool const endMatch = false;
    bool const playerWon = false;

    Structures::Player player{};
    Structures::Ball ball{};
    Structures::Brick bricks[Brick::MAX_BRICKS];

    Init(player, ball, bricks);
    Draw();
    do
    {
        Input(player);
        Game::Update(player, ball);
        Draw();
    }
    while (!Wrapper::ShouldWindowClose() && !endMatch);
}

void Game::Init(Structures::Player &player, Structures::Ball &ball, Structures::Brick bricks[])
{
    //todo move all textures to a single file, so it only gets called once
    const Wrapper::Texture playerSprite = Wrapper::LoadTexture(ASSETS_DIR + "pathtoplayer");
    const Wrapper::Texture ballSprite = Wrapper::LoadTexture(ASSETS_DIR + "pathtoplayer");

    Player::Spawn(player, playerSprite);
    Ball::Spawn(ball, ballSprite);
    Brick::Generate(bricks);
}

void Game::Input(Structures::Player &player)
{
    if (Wrapper::IsKeyDown(SL_KEY_LEFT))
    {
        Player::MoveLeft(player);
    }
    else if (Wrapper::IsKeyDown(SL_KEY_RIGHT))
    {
        Player::MoveRight(player);
    }
    //other input
}

void Game::Update(Structures::Player &player, Structures::Ball &ball)
{
    Player::Update(player);
    Ball::Update(player, ball);
    //Brick::Update(bricks)
}

void Game::Draw()
{
    //todo
}
