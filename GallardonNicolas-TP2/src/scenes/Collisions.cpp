#include "Collisions.h"

#include "GameManager.h"
#include "Structures.h"


bool Collisions::DoesWallPlayer(const Structures::Player &player)
{
    return player.FuturePosition.X - player.Width/2.0F  <= LEFT ||
        player.FuturePosition.X + player.Width/2.0F  >= RIGHT ;
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

bool Collisions::DoesAABB(const VectorMath::Vector2 &position, const VectorMath::Vector2 &size,
                                const Structures::Ball &ball,
                                WhereCollides &collisionPlace)
{

    float minDistance = 0;
    float distance = 0;

    float width = size.X / 2.0F;
    float height = size.Y / 2.0F;

    float rEdge = position.X + width;
    float lEdge = position.X - width;
    float uEdge = position.Y + height;
    float dEdge = position.Y - height;

    // if it touches up/down and within x bounds
    if (!(lEdge < ball.Position.X && rEdge < ball.Position.X) && !(lEdge > ball.Position.X && rEdge > ball.Position.X))
    {
        if (uEdge < ball.FuturePosition.Y)
        {
            collisionPlace = WhereCollides::Up;
            minDistance = ball.Radius;
            distance = ball.FuturePosition.Y - (position.Y + height);
        }
        else if(dEdge > ball.FuturePosition.Y)
        {
            collisionPlace = WhereCollides::Down;
            minDistance = ball.Radius;
            distance = (position.Y - height) - ball.FuturePosition.Y;
        }
        return minDistance > distance;
    }
    // if it touches right/left and within y bounds
    if (!(uEdge < ball.Position.Y && dEdge < ball.Position.Y) && !(uEdge > ball.Position.Y && dEdge > ball.Position.Y))
    {
        if (rEdge < ball.FuturePosition.X)
        {
            collisionPlace = WhereCollides::Right;
            minDistance = ball.Radius + width;
            distance = ball.FuturePosition.X - position.X;
        }

        else if (lEdge > ball.FuturePosition.X)
        {
            collisionPlace = WhereCollides::Left;
            minDistance = ball.Radius + width;
            distance = position.X - ball.FuturePosition.X;
        }
        return minDistance > distance;
    }
    return false;

}

void Collisions::AvoidsCrushing(const Structures::Ball &ball, Structures::Player &player)
{
    float width = player.Width / 2.0F;
    float height = player.Height / 2.0F;

    if (player.Position.Y + height > ball.Position.Y - ball.Radius && player.Position.Y - height < ball.Position.Y + ball.Radius)
    {
        if (player.Position.X + width> RIGHT - ball.Radius * 2.0F )
        {
            player.Position.X = RIGHT - ball.Radius * 2.0F - width - 1.0F;
        }
        if (player.Position.X - width < LEFT + ball.Radius * 2.0F)
        {
            player.Position.X = LEFT + ball.Radius * 2.0F + width + 1.0F;
        }
    }
}