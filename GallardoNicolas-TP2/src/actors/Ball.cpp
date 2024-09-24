#include "Ball.h"

#include <cmath>

#include "Collisions.h"
#include "GameManager.h"
#include "Structures.h"
#include "VectorMath.h"


using namespace Structures;

constexpr float BOUNCE = 0.4F;

void Ball::Update(const PlayerType &player, BallType &ball)
{
    auto collisionPlaceP1 = Collisions::WhereCollides::None;
    auto collisionPlaceBall = Collisions::WhereCollides::None;

    // ball update
    ball.FuturePosition.X = ball.Position.X + ball.Direction.X * ball.Speed * GameManager::GetFrameTime();
    ball.FuturePosition.Y = ball.Position.Y + ball.Direction.Y * ball.Speed * GameManager::GetFrameTime();


    if (DoesWallBall(ball, collisionPlaceBall))
    {
        if (collisionPlaceBall == Collisions::WhereCollides::Up)
        {
            ball.FuturePosition.Y = Collisions::UP - ball.Radius - 1.0F;
            ball.Direction.Y *= -1;
        }
        else if (collisionPlaceBall == Collisions::WhereCollides::Left)
        {
            ball.FuturePosition.X = Collisions::LEFT + ball.Radius + 1.0F;
            ball.Direction.X *= -1;
        }
        else if (collisionPlaceBall == Collisions::WhereCollides::Right)
        {
            ball.FuturePosition.X = Collisions::RIGHT - ball.Radius - 1.0F;
            ball.Direction.X *= -1;
        }
    }

    if (DoesAABB(player.Position,
                             {player.Width, player.Height}, ball,
                             collisionPlaceP1))
    {
        CollisionResult(player, ball, collisionPlaceP1);
    }
}

void Ball::CollisionResult(const PlayerType &player, BallType &ball,
                           const Collisions::WhereCollides collisionPlace)
{
    const float movement = ball.Speed * GameManager::GetFrameTime() > ball.Radius
        ? ball.Speed * GameManager::GetFrameTime()
        : ball.Radius;

    switch (collisionPlace)
    {
    case Collisions::WhereCollides::Left:
        // if it is pushing the ball rather than repelling it
        if (ball.Direction.X < 0)
        {
            ball.Direction.Y -= BOUNCE;
            ball.Direction.X -= BOUNCE;
            const float mag = sqrt(ball.Direction.X * ball.Direction.X + ball.Direction.Y * ball.Direction.Y);
            ball.Direction.X /= mag;
            ball.Direction.Y /= mag;
        }
        else
        {
            ball.Direction.X *= -1;
        }

        ball.FuturePosition.X = player.Position.X - (player.Width / 2.0F + movement); // moves to the border

        break;
    case Collisions::WhereCollides::Right:

        // if it is pushing the ball rather than repelling it
        if (ball.Direction.X > 0)
        {
            ball.Direction.Y -= BOUNCE;
            ball.Direction.X += BOUNCE;
            const float mag = sqrt(ball.Direction.X * ball.Direction.X + ball.Direction.Y * ball.Direction.Y);
            ball.Direction.X /= mag;
            ball.Direction.Y /= mag;
        }
        else
        {
            ball.Direction.X *= -1;
        }

        ball.FuturePosition.X = player.Position.X + player.Width / 2.0F + movement; // moves to the border
        break;

    case Collisions::WhereCollides::Up:
        ChangeDirectionAfterCollision(ball, player);
        ball.FuturePosition.Y = player.Position.Y + player.Height / 2.0F + movement;

        break;
    case Collisions::WhereCollides::None:
        break;
    }
}


void Ball::ChangeDirectionAfterCollision(BallType &ball, const PlayerType &player)
{

    ball.Direction.X = (static_cast<float>(player.Width) / 2.0F - GetWidthCollision(ball, player)) /
        (static_cast<float>(player.Width) / 2.0F); // returns a value between 1 and -1

    ball.Direction.Y *= -1;
    Normalize(ball.Direction);

}

float Ball::GetWidthCollision(const BallType &ball, const PlayerType &player)
{
    return static_cast<float>(player.Width) + player.Position.X - ball.Position.X;
}


void Ball::Draw(BallType &ball)
{
    using namespace Sprites;
    SetSpriteTiling({1 / 6.0F, 1});
    SetSpriteScroll({0.13F, 1});
    LoadSprite(ball.Sprite, ball.Position, {ball.Radius * 2.8F, ball.Radius * 2.0F});
    SetSpriteTiling({1, 1});
    SetSpriteScroll({1, 1});
}


void Ball::Spawn(BallType &ball, const Texture sprite)
{
    float angle;
    float x;
    float y;
    const bool isRight = GameManager::GetRandom(0, 1);

    ball.Speed = SPEED;
    ball.Radius = RADIUS;
    ball.Sprite = sprite;

    if (!isRight)
    {
        ball.Position.X = Collisions::LEFT + ball.Radius;
        angle = static_cast<float>(GameManager::GetRandom(290, 340));
    }
    else
    {
        ball.Position.X = Collisions::RIGHT - ball.Radius;
        angle = static_cast<float>(GameManager::GetRandom(200, 250));
    }
    ball.Position.Y = SPAWN_Y_HEIGTH;

    x = cos(PI * angle / 180); // hypotenuse = 1
    y = sin(PI * angle / 180);

    ball.Direction = {x, y};
}
