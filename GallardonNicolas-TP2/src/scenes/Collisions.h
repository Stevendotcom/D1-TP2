#pragma once
#include "Structures.h"

namespace Collisions
{
    enum class WhereCollides
    {
        Up,
        Left,
        Right,
        None
    };


    bool DoesWallPlayer(const Structures::Player &player);
    bool DoesWallBall(const Structures::Ball &ball, WhereCollides &collisionPlace);
    bool DoesRectCircle(const VectorMath::Vector2 &position, const VectorMath::Vector2 &size,
                        const Structures::Ball &ball, WhereCollides &collisionPlace);
    bool DoesRectCircle(const VectorMath::Vector2 &position, const VectorMath::Vector2 &size,
                        const Structures::Ball &ball);
};
