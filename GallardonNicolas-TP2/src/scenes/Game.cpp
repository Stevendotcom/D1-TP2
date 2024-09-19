#include "Game.h"
#include "Ball.h"
#include "Brick.h"
#include "Player.h"
#include "Structures.h"

#include <sl.h>

#include "Input.h"
#include "Management.h"

extern Sprites::Sprites sprites;

void Game::Play()
{
    bool endMatch = false;
    bool playerWon = false;

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
    while (!Management::ShouldWindowClose() && !endMatch);
}

void Game::Init(Structures::Player &player, Structures::Ball &ball, Structures::Brick bricks[])
{


    Player::Spawn(player, sprites.Player);
    Ball::Spawn(ball,  sprites.Ball);
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
