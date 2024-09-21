#include "Brick.h"

#include "Collisions.h"



void Brick::Generate(Structures::Brick bricks[MAX_BRICKS])
{
    const float margin = 30.0F;
    const float width = 16.0F;
    const float heigth = 16.0F;
    for (int i = 0; i < MAX_BRICKS; i++)
    {
        bricks[i] =
        {
            Structures::Powers::None,
            true,
            {margin + width / 2.0F + width * i, margin + heigth / 2.0F + heigth * i },
            {width, heigth},
        };
        switch (bricks[i].Power)
        {
        case Structures::Powers::None:
            bricks[i].Sprite = sprites.Grass;
            break;
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
            if(Collisions::DoesRectCircle(bricks[i].Position, bricks[i].Size, ball))
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
