#include "Brick.h"
#include "Structures.h"

void Brick::Generate(Structures::Brick bricks[MAX_BRICKS])
{
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


bool Brick::DoesBrickBall(Structures::Brick bricks[Brick::MAX_BRICKS], Structures::Ball &ball )
{
    //todo think of a way to not check all bricks every frame

    for (int i = 0; i < Brick::MAX_BRICKS; i++)
    {
        if (bricks[i].IsVisible)
        {

        }
    }

    return false;
}
