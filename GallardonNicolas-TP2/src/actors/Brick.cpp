#include "Brick.h"

#include "Collisions.h"


void Brick::Generate(Structures::Brick bricks[MAX_BRICKS])
{
    const int rows = 4;
    const int cols = MAX_BRICKS / rows;

    const VectorMath::Vector2 sizeEach  = { 80.0F ,80.0F};
    const VectorMath::Vector2 origin = { SCREEN_WIDTH / 2.0f - (cols * sizeEach.X) / 2.0F, static_cast<float>(SCREEN_HEIGHT) - 150.0F}; // starts by upper left corner


    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            bricks[row * cols + col] =
            {
                Structures::Powers::None,
                true,
                {origin.X + (sizeEach.X / 2.0F) + (sizeEach.X * col), origin.Y - (sizeEach.Y / 2.0F) - (sizeEach.Y * row)},
                sizeEach,
            };

            switch (bricks[row * cols + col].Power)
            {
            case Structures::Powers::None:
                bricks[row * cols + col].Sprite = sprites.Grass;
                break;
            }
        }
    }
}

void Brick::Draw(Structures::Brick bricks[MAX_BRICKS])
{
    for (int i = 0; i < MAX_BRICKS; i++)
    {
        if (bricks[i].IsVisible)
        {
            Sprites::LoadSprite(bricks[i].Sprite, bricks[i].Position, bricks[i].Size);
        }
    }
}


void Brick::ToggleVisible(Structures::Brick &brick)
{
    brick.IsVisible = !brick.IsVisible;
}


int Brick::Update(Structures::Brick bricks[MAX_BRICKS], Structures::Ball &ball)
{
    int activeBricks = 0;

    for (int i = 0; i < MAX_BRICKS; i++)
    {
        if (bricks[i].IsVisible)
        {
            if (Collisions::DoesRectCircle(bricks[i].Position, bricks[i].Size, ball))
            {
                activeBricks--;
                ToggleVisible(bricks[i]);
                ActivatePower(bricks[i]);
            }
            else
            {
                activeBricks++;
            }
        }
    }

    return activeBricks;

}

void Brick::ActivatePower(Structures::Brick &brick)
{
    //todo
}
