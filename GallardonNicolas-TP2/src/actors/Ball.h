#pragma once
#include "Wrapper.h"
#include "Player.h"
#include "VectorMath.h"

namespace Ball
{

	const int SPEED = Player::SPEED * 1.2; // 20% speed increase
    const float SPAWN_Y_HEIGTH = SCREEN_HEIGHT / 2.0f - 40.0f; 
    const float RADIUS = 15.0f;

    struct Ball
    {
        VectorMath::Vector2 Position;
        VectorMath::Vector2 FuturePosition;
        VectorMath::Vector2 Direction;
        Wrapper::Texture Sprite;
        float Radius;
        float Speed;
    };

    void Spawn(Ball &ball, Wrapper::Texture sprite);
    void Update(Player::Player &p1, Ball &ball);
    bool DoesCollide(Player::Player &player, Ball &ball, Player::WhereCollides &collisionPlace);
    bool DoesCollideWalls(const Ball &ball, Player::WhereCollides &collisionPlace);
    void CollisionResult(Player::Player &player, Ball &ball, Player::WhereCollides collisionPlace);
    void ChangeDirectionAfterCollision(Ball &ball, const Player::Player &player, Player::WhereCollides whereCollides);
    float GetWidthCollision(const Ball &ball, const Player::Player &player);
};
