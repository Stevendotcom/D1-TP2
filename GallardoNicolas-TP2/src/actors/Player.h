#pragma once
#include "Structures.h"


namespace Player
{
    const int MARGIN = 10;
    const int SPEED = 600;
    const int HEIGHT = 100;
    const int WIDTH = HEIGHT * 1.3;
    const int HEARTS = 3;

    void MoveRight(Structures::Player &player);
    void MoveLeft(Structures::Player &player);
    void Update(Structures::Player &player, const Structures::Ball& ball);
    void Spawn(Structures::Player &player, Texture sprite);
    void Draw(Structures::Player &player);
}
