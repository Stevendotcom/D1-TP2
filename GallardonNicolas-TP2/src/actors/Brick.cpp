#include "Brick.h"
#include "Structures.h"

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
            bricks[i].Sprite = Sprites::LoadTexture(ASSETS_DIR + "pathtofilename");
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


void Brick::Update(Structures::Brick bricks[MAX_BRICKS], Structures::Ball &ball)
{
    //todo think of a way to not check all bricks every frame

    for (int i = 0; i < MAX_BRICKS; i++)
    {
        if (bricks[i].IsVisible && Collisions::DoesRectCircle(bricks[i].Position, bricks[i].Size, ball))
        {
            ToggleVisible(bricks[i]);
            ActivatePower(bricks[i]);
        }
    }

}

void Brick::ActivatePower(Structures::Brick &brick)
{
    //todo
}
