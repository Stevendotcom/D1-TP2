#pragma once
#include "Collisions.h"

namespace Game
{
    void Play();
    void Init(Structures::Player &player, Structures::Ball &ball, Structures::Brick bricks[]);
    void Input(Structures::Player &player);
    void Update(Structures::Player &player, Structures::Ball &ball, Structures::Brick bricks[]);
    void Draw();
} // namespace Game
