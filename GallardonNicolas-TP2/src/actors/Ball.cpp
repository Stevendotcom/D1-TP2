#include "Ball.h"

#include <cmath>
#include "Collisions.h"
#include "GameManager.h"
#include "Structures.h"
#include "VectorMath.h"


const float BOUNCE = 0.4F;


void Ball::Update(Structures::Player &player, Structures::Ball &ball)
{
    Collisions::WhereCollides collisionPlaceP1 = Collisions::WhereCollides::None;
    Collisions::WhereCollides collisionPlaceBall = Collisions::WhereCollides::None;

    // ball update
    ball.FuturePosition.X = ball.Position.X + (ball.Direction.X * ball.Speed * GameManager::GetFrameTime());
    ball.FuturePosition.Y = ball.Position.Y + (ball.Direction.Y * ball.Speed * GameManager::GetFrameTime());


    if (Collisions::DoesWallBall(ball, collisionPlaceBall))
    {
        if (collisionPlaceBall == Collisions::WhereCollides::Up)
        {
            ball.FuturePosition.Y = SCREEN_HEIGHT - ball.Radius - 1.0F;
            ball.Direction.Y *= -1;
        }
        else if (collisionPlaceBall == Collisions::WhereCollides::Left)
        {
            ball.FuturePosition.X = ball.Radius + 1.0F;
            ball.Direction.X *= -1;
        }
        else if (collisionPlaceBall == Collisions::WhereCollides::Right)
        {
            ball.FuturePosition.X = SCREEN_WIDTH - ball.Radius - 1.0F;
            ball.Direction.X *= -1;
        }
    }

    if (Collisions::DoesRectCircle(player.Position,
                                   {static_cast<float>(player.Width), static_cast<float>(player.Height)}, ball,
                                   collisionPlaceP1))
    {
        CollisionResult(player, ball, collisionPlaceP1);
    }


    ball.Position = ball.FuturePosition;
    ball.FuturePosition = ball.Position;
}

void Ball::CollisionResult(Structures::Player &player, Structures::Ball &ball,
                           const Collisions::WhereCollides collisionPlace)
{
    switch (collisionPlace)
    {
    case Collisions::WhereCollides::Left:
        // if it is pushing the ball rather than repelling it
        if (ball.Direction.X < 0)
        {
            ball.Direction.X -= BOUNCE;
        }
        else
        {
            ball.Direction.X *= -1;
        }

        if (player.Position.X < ball.Radius * 2 + 1.0F)
        {
            player.Position.X = ball.FuturePosition.X + ball.Radius;
        }

        ball.FuturePosition.X = player.Position.X - (ball.Radius + 1.0F); // moves to the border

        break;
    case Collisions::WhereCollides::Right:

        // if it is pushing the ball rather than repelling it
        if (ball.Direction.X > 0)
        {
            ball.Direction.X += BOUNCE;
        }
        else
        {
            ball.Direction.X *= -1;
        }

        if (player.Position.X + player.Width > SCREEN_WIDTH - ball.Radius * 2)
        {
            player.Position.X = ball.Position.X - ball.Radius - 1.0F;
        }

        ball.FuturePosition.X = player.Position.X + player.Width + ball.Radius + 1.0F; // moves to the border
        break;

    case Collisions::WhereCollides::Up:
        ChangeDirectionAfterCollision(ball, player, collisionPlace);
        ball.FuturePosition.Y = SCREEN_HEIGHT - ball.Radius - 1.0F;

        break;
    case Collisions::WhereCollides::None:
        break;
    }
}


void Ball::ChangeDirectionAfterCollision(Structures::Ball &ball, const Structures::Player &player,
                                         const Collisions::WhereCollides /*whereCollides*/)
{

    ball.Direction.X = ((static_cast<float>(player.Width) / 2.0F) - GetWidthCollision(ball, player)) /
        (static_cast<float>(player.Width) / 2.0F); // returns a value between 1 and -1

    VectorMath::Normalize(ball.Direction);

}

auto Ball::GetWidthCollision(const Structures::Ball &ball, const Structures::Player &player) -> float
{
    return static_cast<float>(player.Width) + player.Position.X - ball.Position.X;
}

void Ball::Spawn(Structures::Ball &ball, const Texture sprite)
{
    float angle = NAN;
    float x = NAN;
    float y = NAN;
    const bool isRight = GameManager::GetRandom(0, 1);

    ball.Speed = SPEED;
    ball.Radius = RADIUS;
    ball.Sprite = sprite;

    if (isRight)
    {
        ball.Position.X = ball.Radius;
        angle = static_cast<float>(GameManager::GetRandom(290, 340));
    }
    else
    {
        ball.Position.X = SCREEN_WIDTH - ball.Radius;
        angle = static_cast<float>(GameManager::GetRandom(200, 250));
    }
    ball.Position.Y = SPAWN_Y_HEIGTH;

    x = cos((PI * angle) / 180); // hypotenuse = 1
    y = sin((PI * angle) / 180);

    ball.Direction = {x, y};
}
