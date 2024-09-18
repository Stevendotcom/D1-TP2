#include "Ball.h"

#include <cmath>

const float BOUNCE = 0.4f;


void Ball::Update(Player::Player &p1, Ball &ball)
{
    Player::WhereCollides collisionPlaceP1 = Player::WhereCollides::None;
    Player::WhereCollides collisionPlaceBall = Player::WhereCollides::None;

    // ball update
    ball.FuturePosition.X = ball.Position.X + (ball.Direction.X * ball.Speed * Wrapper::GetFrameTime());
    ball.FuturePosition.Y = ball.Position.Y + (ball.Direction.Y * ball.Speed * Wrapper::GetFrameTime());


    if (DoesCollideWalls(ball, collisionPlaceBall))
    {
        if (collisionPlaceBall == Player::WhereCollides::Up)
        {
            ball.FuturePosition.Y = SCREEN_HEIGHT - ball.Radius - 1.0f;
            ball.Direction.Y *= -1;
        }
        else if (collisionPlaceBall == Player::WhereCollides::Left)
        {
            ball.FuturePosition.X = ball.Radius + 1.0f;
            ball.Direction.X *= -1;
        }
        else if (collisionPlaceBall == Player::WhereCollides::Right)
        {
            ball.FuturePosition.X = SCREEN_WIDTH - ball.Radius - 1.0f;
            ball.Direction.X *= -1;
        }
    }

    if (DoesCollide(p1, ball, collisionPlaceP1))
    {
        CollisionResult(p1, ball, collisionPlaceP1);
    }


    ball.Position = ball.FuturePosition;
    ball.FuturePosition = ball.Position;
}

void Ball::CollisionResult(Player::Player &player, Ball &ball, const Player::WhereCollides collisionPlace)
{
    switch (collisionPlace)
    {
    case Player::WhereCollides::Left:
        // if it is pushing the ball rather than repelling it
        if (ball.Direction.X < 0)
        {
            ball.Direction.X -= BOUNCE;
        }
        else
        {
            ball.Direction.X *= -1;
        }

        if (player.Position.X < ball.Radius * 2 + 1.0f)
        {
            player.Position.X = ball.FuturePosition.X + ball.Radius;
        }

        ball.FuturePosition.X = player.Position.X - (ball.Radius + 1.0f); // moves to the border

        break;
    case Player::WhereCollides::Right:

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
            player.Position.X = ball.Position.X - ball.Radius - 1.0f;
        }

        ball.FuturePosition.X = player.Position.X + player.Width + ball.Radius + 1.0f; // moves to the border
        break;

    case Player::WhereCollides::Up:
        ChangeDirectionAfterCollision(ball, player, collisionPlace);
        ball.FuturePosition.Y = SCREEN_HEIGHT - ball.Radius - 1.0f;

        break;
    case Player::WhereCollides::None:
        break;
    }
}


bool Ball::DoesCollideWalls(const Ball &ball, Player::WhereCollides &collisionPlace)
{
    if (ball.FuturePosition.X < ball.Radius)
    {
        collisionPlace = Player::WhereCollides::Left;
        return true;
    }
	if (ball.FuturePosition.X > SCREEN_WIDTH - ball.Radius)
    {
        collisionPlace = Player::WhereCollides::Left;
        return true;
    }
    if (ball.FuturePosition.Y > SCREEN_HEIGHT - ball.Radius)
    {
        collisionPlace = Player::WhereCollides::Up;
        return true;
    }
    return false;
}

void Ball::ChangeDirectionAfterCollision(Ball &ball, const Player::Player &player,
                                         const Player::WhereCollides whereCollides)
{

    ball.Direction.X = ((static_cast<float>(player.Width) / 2.0f) - GetWidthCollision(ball, player)) /
        (static_cast<float>(player.Width) / 2.0f); // returns a value between 1 and -1

   VectorMath::Normalize(ball.Direction);

}

float Ball::GetWidthCollision(const Ball &ball, const Player::Player &player)
{
    return static_cast<float>(player.Width) + player.Position.X - ball.Position.X;
}

void Ball::Spawn(Ball &ball, const Wrapper::Texture sprite)
{
    float angle;
    float x;
    float y;
    bool isRight = Wrapper::GetRandom(0, 1);

    ball.Speed = SPEED;
    ball.Radius = RADIUS;
    ball.Sprite = sprite;

	if (isRight)
    {
        ball.Position.X = ball.Radius;
        angle = static_cast<float>(Wrapper::GetRandom(290, 340));
    }
	else
	{
        ball.Position.X = SCREEN_WIDTH - ball.Radius;
        angle = static_cast<float>(Wrapper::GetRandom(200, 250));
	}
    ball.Position.Y = SPAWN_Y_HEIGTH;

    x = cos((PI * angle) / 180); // hypotenuse = 1
    y = sin((PI * angle) / 180);

    ball.Direction = {x, y};
}

bool Ball::DoesCollide(Player::Player &player, Ball &ball, Player::WhereCollides &collisionPlace)
{

    float minDistance = 0;
    float distance = 0;

    // if it touches up/down and within x bounds
    if (player.Position.X < ball.Position.X && player.Position.X + player.Width > ball.Position.X)
    {
        if (player.Position.Y + player.Height - (ball.Speed * Wrapper::GetFrameTime()) < ball.FuturePosition.Y)
        {
            collisionPlace = Player::WhereCollides::Up;
            minDistance = ball.Radius;
            distance = ball.FuturePosition.Y - player.Position.Y;
        }
        else
        {
            return false;
        }
        return minDistance > distance;
    }
    // if it touches right/left and within y bounds
    if (player.Position.Y + player.Height > ball.Position.Y && player.Position.Y < ball.Position.Y)
    {
        if (player.Position.X < ball.FuturePosition.X)
        {
            collisionPlace = Player::WhereCollides::Right;
            minDistance = ball.Radius + player.Width;
            distance = ball.FuturePosition.X - player.Position.X;
        }

        else
        {
            collisionPlace = Player::WhereCollides::Left;
            minDistance = ball.Radius;
            distance = player.Position.X - ball.FuturePosition.X;
        }
        return minDistance > distance;
    }
}
