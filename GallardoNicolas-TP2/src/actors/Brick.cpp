#include "Brick.h"

#include "Collisions.h"
#include "GameManager.h"

using namespace Structures;
using namespace Collisions;

auto activePower = SpecialBricks::None;

void Brick::Generate(BrickType bricks[MAX_BRICKS])
{
    using namespace Structures;

    constexpr int rows = 4;
    constexpr int cols = MAX_BRICKS / rows;

    constexpr VectorMath::Vector2 sizeEach = {80.0F, 80.0F};
    const VectorMath::Vector2 origin = {SCREEN_WIDTH / 2.0f - cols * sizeEach.X / 2.0F,
                                        static_cast<float>(SCREEN_HEIGHT) - 150.0F}; // starts by upper left corner


    const int specialBrick1[] = {GameManager::GetRandom(0, rows - 1), GameManager::GetRandom(0, cols - 1)};
    const int specialBrick2[] = {GameManager::GetRandom(0, rows - 1), GameManager::GetRandom(0, cols - 1)};

    int pos = 0;

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            pos = row * cols + col;
            bricks[pos].IsVisible = true;
            bricks[pos].Position = {
                                    origin.X + sizeEach.X / 2.0F + sizeEach.X * col,
                                    origin.Y - sizeEach.Y / 2.0F - sizeEach.Y * row
                                    };

            bricks[pos].Size = sizeEach;
            if ((row == specialBrick1[0] && col == specialBrick1[1]) || (row == specialBrick2[0] &&
                col == specialBrick2[1]))
            {
                bricks[pos].Power = static_cast<SpecialBricks>(GameManager::GetRandom(0, 4));
            }
            else
            {
                bricks[pos].Power = SpecialBricks::None;
            }

            switch (bricks[pos].Power)
            {
            case SpecialBricks::None:
                bricks[pos].Sprite = sprites.Grass;
                break;
            case SpecialBricks::RotateScreen:
                bricks[pos].Sprite = sprites.Rotate;
                break;
            case SpecialBricks::InvertControls:
                bricks[pos].Sprite = sprites.Invert;
                break;
            case SpecialBricks::OneUp:
                bricks[pos].Sprite = sprites.OneUp;
                break;
            case SpecialBricks::FasterPlayer:
                bricks[pos].Sprite = sprites.Faster;
                break;
            }
        }
    }
}

void Brick::Draw(BrickType bricks[MAX_BRICKS])
{
    for (int i = 0; i < MAX_BRICKS; i++)
    {
        if (bricks[i].IsVisible)
        {
            Sprites::LoadSprite(bricks[i].Sprite, bricks[i].Position, bricks[i].Size);
        }
    }
}


void Brick::ToggleVisible(BrickType &brick)
{
    brick.IsVisible = !brick.IsVisible;
}


bool Brick::Update(BrickType bricks[MAX_BRICKS], BallType &ball, int &activeBricks)
{
    constexpr float BOUNCE = 0.4F;
    auto whereCollides = WhereCollides::None;

    for (int i = 0; i < MAX_BRICKS; i++)
    {
        if (bricks[i].IsVisible)
        {
            if (DoesAABB(bricks[i].Position, bricks[i].Size, ball, whereCollides))
            {
                activeBricks--;
                ToggleVisible(bricks[i]);
                ActivatePower(bricks[i]);

                switch (whereCollides)
                {
                case WhereCollides::Up:
                    ball.FuturePosition.Y = bricks[i].Position.Y + bricks[i].Size.Y / 2.0f + ball.Radius;
                    if (ball.Direction.Y > 0)
                    {
                        ball.Direction.Y *= -1;
                    }
                    else
                    {
                        ball.Direction.Y += BOUNCE;
                        const float mag = sqrt(
                            ball.Direction.X * ball.Direction.X + ball.Direction.Y * ball.Direction.Y);
                        ball.Direction.X /= mag;
                        ball.Direction.Y /= mag;
                    }
                    break;
                case WhereCollides::Down:
                    ball.FuturePosition.Y = bricks[i].Position.Y - bricks[i].Size.Y / 2.0f - ball.Radius;
                    if (ball.Direction.Y > 0)
                    {
                        ball.Direction.Y *= -1;
                    }
                    else
                    {
                        ball.Direction.Y -= BOUNCE;
                        const float mag = sqrt(
                            ball.Direction.X * ball.Direction.X + ball.Direction.Y * ball.Direction.Y);
                        ball.Direction.X /= mag;
                        ball.Direction.Y /= mag;
                    }
                    break;
                case WhereCollides::Left:
                    ball.FuturePosition.X = bricks[i].Position.X - bricks[i].Size.X / 2.0f - ball.Radius;
                    ball.Direction.X *= -1;
                    break;
                case WhereCollides::Right:
                    ball.FuturePosition.X = bricks[i].Position.X + bricks[i].Size.X / 2.0f + ball.Radius;
                    ball.Direction.X *= -1;
                    break;
                case WhereCollides::None:
                    break;
                }
                ball.Position = ball.FuturePosition;
                ball.FuturePosition = ball.Position;
                return true;
            }
        }
    }
    return false;

}

void Brick::ActivatePower(const BrickType &brick)
{
    using namespace Structures;

    switch (brick.Power)
    {

    case SpecialBricks::RotateScreen:
        activePower = SpecialBricks::RotateScreen;
        break;
    case SpecialBricks::InvertControls:
        activePower = SpecialBricks::InvertControls;
        break;
    case SpecialBricks::OneUp:
        activePower = SpecialBricks::OneUp;
        break;
    case SpecialBricks::FasterPlayer:
        activePower = SpecialBricks::FasterPlayer;
        break;
    }
}

SpecialBricks Brick::GetActivePower()
{
    return activePower;
}

void Brick::SetActivePower(const SpecialBricks& power)
{
    activePower = power;
}
