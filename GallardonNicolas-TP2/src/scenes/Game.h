#pragma once
#include "Ball.h"
#include "Brick.h"
#include "Player.h"

namespace Game
{
    void Play();
    void Init(Player::Player& player, Ball::Ball& ball, Brick::Brick bricks[]);
    void Input(Player::Player& player);
    void Update(Player::Player& player, Ball::Ball& ball);
    void Draw();
}
