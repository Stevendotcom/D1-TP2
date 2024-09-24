#pragma once
#include "Structures.h"

namespace Collisions
{
    const int MARGIN = 50;
    const float LEFT = MARGIN;
    const float RIGHT = SCREEN_WIDTH - MARGIN;
    const float UP = SCREEN_HEIGHT - MARGIN;

    enum class WhereCollides
    {
        Up,
        Down,
        Left,
        Right,
        None
    };


    bool DoesWallPlayer(const Structures::Player &player);
    bool DoesWallBall(const Structures::Ball &ball, WhereCollides &collisionPlace);
    bool DoesAABB(const VectorMath::Vector2 &position, const VectorMath::Vector2 &size,
                        const Structures::Ball &ball, WhereCollides &collisionPlace);
    void AvoidsCrushing(const Structures::Ball &ball, Structures::Player &player);
};
