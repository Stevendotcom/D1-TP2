#pragma once
#include "Collisions.h"

namespace Ball
{

    const int SPEED = 680;
    const float SPAWN_Y_HEIGTH = SCREEN_HEIGHT / 2.0f - 40.0f;
    const float RADIUS = 15.0f;

    void Spawn(Structures::Ball &ball, Wrapper::Texture sprite);
    void Update(Structures::Player &player, Structures::Ball &ball);
    void CollisionResult(Structures::Player &player, Structures::Ball &ball, Collisions::WhereCollides collisionPlace);
    void ChangeDirectionAfterCollision(Structures::Ball &ball, const Structures::Player &player,
                                       Collisions::WhereCollides whereCollides);
    float GetWidthCollision(const Structures::Ball &ball, const Structures::Player &player);
};
