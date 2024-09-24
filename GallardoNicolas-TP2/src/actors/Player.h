#pragma once
#include "Structures.h"


namespace Player
{
    constexpr int MARGIN = 10;
    constexpr int SPEED = 600;
    constexpr int HEIGHT = 100;
    constexpr int WIDTH = HEIGHT * 1.3;
    constexpr int HEARTS = 3;

    void MoveRight(Structures::PlayerType &player);
    void MoveLeft(Structures::PlayerType &player);
    void Update(Structures::PlayerType &player, const Structures::BallType &ball);
    void Spawn(Structures::PlayerType &player, Texture sprite);
    void Draw(Structures::PlayerType &player);
}
