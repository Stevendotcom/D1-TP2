﻿#include "Collisions.h"

#include "Structures.h"

using namespace Structures;

bool Collisions::DoesWallPlayer(const PlayerType &player)
{
    return player.FuturePosition.X - player.Width / 2.0F <= LEFT ||
        player.FuturePosition.X + player.Width / 2.0F >= RIGHT;
}


bool Collisions::DoesWallBall(const BallType &ball, WhereCollides &collisionPlace)
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

bool Collisions::DoesAABB(const VectorMath::Vector2 &position, const VectorMath::Vector2 &size,
                          const BallType &ball,
                          WhereCollides &collisionPlace)
{

    float minDistance = 0;
    float distance = 0;

    const float width = size.X / 2.0F;
    const float height = size.Y / 2.0F;

    const float rEdge = position.X + width;
    const float lEdge = position.X - width;
    const float uEdge = position.Y + height;
    const float dEdge = position.Y - height;

    // if it touches up/down and within x bounds
    if (!(lEdge < ball.Position.X && rEdge < ball.Position.X) && !(lEdge > ball.Position.X && rEdge > ball.Position.X))
    {
        minDistance = ball.Radius + height;
        if (uEdge < ball.FuturePosition.Y)
        {
            collisionPlace = WhereCollides::Up;
            distance = ball.FuturePosition.Y - position.Y;
        }
        else if (dEdge > ball.FuturePosition.Y)
        {
            collisionPlace = WhereCollides::Down;
            distance = position.Y - ball.FuturePosition.Y;
        }
        return minDistance > distance;
    }
    // if it touches right/left and within y bounds
    if (!(uEdge < ball.Position.Y && dEdge < ball.Position.Y) && !(uEdge > ball.Position.Y && dEdge > ball.Position.Y))
    {
        minDistance = ball.Radius + width;
        if (rEdge < ball.FuturePosition.X)
        {
            collisionPlace = WhereCollides::Right;
            distance = ball.FuturePosition.X - position.X;
        }

        else if (lEdge > ball.FuturePosition.X)
        {
            collisionPlace = WhereCollides::Left;
            distance = position.X - ball.FuturePosition.X;
        }
        return minDistance > distance;
    }
    return false;

}

void Collisions::AvoidsCrushing(const BallType &ball, PlayerType &player)
{
    const float width = player.Width / 2.0F;
    const float height = player.Height / 2.0F;

    if (player.Position.Y + height > ball.Position.Y &&
        player.Position.Y - height < ball.Position.Y)
    {
        if (player.Position.X + width > RIGHT - ball.Radius * 2.0F)
        {
            player.Position.X = RIGHT - ball.Radius * 2.0F - width - 1.0F;
        }
        if (player.Position.X - width < LEFT + ball.Radius * 2.0F)
        {
            player.Position.X = LEFT + ball.Radius * 2.0F + width + 1.0F;
        }
    }
}
