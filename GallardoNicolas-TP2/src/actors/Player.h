#pragma once
#include "Structures.h"


namespace Player
{
    constexpr int MARGIN = 10;
    constexpr int SPEED = 600;
    constexpr int HEIGHT = 100;
    constexpr int WIDTH = HEIGHT * 1.3;
    constexpr int HEARTS = 3;

    void MoveRight(Structures::Player &player);
    void MoveLeft(Structures::Player &player);
    void Update(Structures::Player &player, const Structures::Ball &ball);
    void Spawn(Structures::Player &player, Texture sprite);
    void Draw(Structures::Player &player);
}
