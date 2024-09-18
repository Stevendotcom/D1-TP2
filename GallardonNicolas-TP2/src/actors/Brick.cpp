#include "Brick.h"

void Brick::Draw(Brick bricks[MAX_BRICKS])
{
    for (int i = 0; i < MAX_BRICKS; i++)
    {
        if(bricks[i].IsVisible)
        {
            Wrapper::LoadSprite(bricks[i].Sprite, bricks[i].Position, bricks[i].Size);
        }
    }
}

void Brick::ToggleVisible(Brick& brick)
{
    brick.IsVisible = !brick.IsVisible;
}
