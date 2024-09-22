#include "Collisions.h"

#include "GameManager.h"
#include "Structures.h"


bool Collisions::DoesWallPlayer(const Structures::Player &player)
{
    return player.FuturePosition.X - player.Width  <= LEFT ||
        player.FuturePosition.X + player.Width  >= RIGHT ;
}


bool Collisions::DoesWallBall(const Structures::Ball &ball, WhereCollides &collisionPlace)
{
    if (ball.FuturePosition.X < ball.Radius + LEFT)
    {
        collisionPlace = WhereCollides::Left;
        return true;
    }
    if (ball.FuturePosition.X > RIGHT - ball.Radius)
    {
        collisionPlace = WhereCollides::Right;
        return true;
    }
    if (ball.FuturePosition.Y > UP - ball.Radius)
    {
        collisionPlace = WhereCollides::Up;
        return true;
    }
    return false;
}

bool Collisions::DoesRectCircle(const VectorMath::Vector2 &position, const VectorMath::Vector2 &size,
                                const Structures::Ball &ball,
                                WhereCollides &collisionPlace)
{
    // todo forgot to do down as collision place
    float minDistance = 0;
    float distance = 0;

    float width = size.X / 2.0F;
    float height = size.Y / 2.0F;

    // if it touches up/down and within x bounds
    if (position.X - width  < ball.Position.X && position.X + width > ball.Position.X)
    {
        if (position.Y + height  - (ball.Speed * GameManager::GetFrameTime()) < ball.FuturePosition.Y)
        {
            collisionPlace = WhereCollides::Up;
            minDistance = ball.Radius;
            distance = ball.FuturePosition.Y - (position.Y + height);
        }
        else
        {
            return false;
        }
        return minDistance > distance;
    }
    // if it touches right/left and within y bounds
    if (position.Y + height > ball.Position.Y && position.Y - height < ball.Position.Y)
    {
        if (position.X < ball.FuturePosition.X)
        {
            collisionPlace = WhereCollides::Right;
            minDistance = ball.Radius + width;
            distance = ball.FuturePosition.X - position.X;
        }

        else
        {
            collisionPlace = WhereCollides::Left;
            minDistance = ball.Radius + width;
            distance = position.X - ball.FuturePosition.X;
        }
        return minDistance > distance;
    }
    return false;

}

bool Collisions::DoesRectCircle(const VectorMath::Vector2 &position, const VectorMath::Vector2 &size,
                                const Structures::Ball &ball)
{

    float minDistance = 0;
    float distance = 0;

    // if it touches up/down and within x bounds
    if (position.X < ball.Position.X && position.X + size.X > ball.Position.X)
    {
        if (position.Y + size.Y - (ball.Speed * GameManager::GetFrameTime()) < ball.FuturePosition.Y)
        {
            minDistance = ball.Radius;
            distance = ball.FuturePosition.Y - position.Y;
        }
        else
        {
            return false;
        }
        return minDistance > distance;
    }
    // if it touches right/left and within y bounds
    if (position.Y + size.Y > ball.Position.Y && position.Y < ball.Position.Y)
    {
        if (position.X < ball.FuturePosition.X)
        {
            minDistance = ball.Radius + size.X;
            distance = ball.FuturePosition.X - position.X;
        }

        else
        {
            minDistance = ball.Radius;
            distance = position.X - ball.FuturePosition.X;
        }
        return minDistance > distance;
    }
    return false;
}
