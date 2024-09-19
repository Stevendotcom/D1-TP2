#pragma once
#include "Structures.h"
#include "Wrapper.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

namespace Player
{
    const int MARGIN = 10;
    const int SPEED = 600;
    const int WIDTH = 25;
    const int HEIGHT = 150;


    void MoveRight(Structures::Player &player);
    void MoveLeft(Structures::Player &player);
    void Update(Structures::Player &p1);
    void Spawn(Structures::Player &player, Wrapper::Texture sprite);
}
