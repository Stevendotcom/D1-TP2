#include "Sprites.h"

#include <iostream>
#include <sl.h>

namespace Sprites
{

    Texture LoadTexture(const std::string &filename)
    {
        return slLoadTexture(filename.c_str());
    }


    void LoadSprites(Sprites &sprites)
    {

        sprites.PlayerLeft = LoadTexture(ASSETS_DIR + "Tiny-Swords/WarriorLeft.png");
        sprites.PlayerRight = LoadTexture(ASSETS_DIR + "Tiny-Swords/WarriorRight.png");
        sprites.PlayerIdle = LoadTexture(ASSETS_DIR + "Tiny-Swords/WarriorIdle.png");
        sprites.Grass = LoadTexture(ASSETS_DIR + "Tiny-Swords/Grass.png");
        sprites.Background = LoadTexture(ASSETS_DIR + "Tiny-Swords/Background.png");
        sprites.Ball = LoadTexture(ASSETS_DIR + "Tiny-Swords/Sheep.png");
        sprites.Button = LoadTexture(ASSETS_DIR + "Tiny-Swords/Ribbon.png");
        sprites.TitleBack = LoadTexture(ASSETS_DIR + "Tiny-Swords/TitleBack.png");
        sprites.Faster = LoadTexture(ASSETS_DIR + "Tiny-Swords/Faster.png");
        sprites.Invert = LoadTexture(ASSETS_DIR + "Tiny-Swords/Invert.png");
        sprites.OneUp = LoadTexture(ASSETS_DIR + "Tiny-Swords/OneUp.png");
        sprites.Rotate = LoadTexture(ASSETS_DIR + "Tiny-Swords/Rotate.png");
        sprites.HeartsBorder = LoadTexture(ASSETS_DIR + "Health-Stamina/HeartsBorder.png");
        sprites.Heart = LoadTexture(ASSETS_DIR + "Health-Stamina/Heart.png");
        sprites.LeftArrow = LoadTexture(ASSETS_DIR + "SimpleKeys/ARROWLEFT.png");
        sprites.RightArrow = LoadTexture(ASSETS_DIR + "SimpleKeys/ARROWRIGHT.png");
        sprites.P = LoadTexture(ASSETS_DIR + "SimpleKeys/P.png");

    }

    void SetSpriteTiling(const VectorMath::Vector2 position)
    {
        slSetSpriteTiling(position.X, position.Y);
    }


    void SetSpriteScroll(const VectorMath::Vector2 position)
    {
        if (position.X > FLT_EPSILON + 1.0f && position.X < 0 && position.Y < 0 && position.Y > FLT_EPSILON + 1.0f)
        {
            std::cout << "Scroll higher than the permitted amount";
            abort();
        }
        slSetSpriteScroll(position.X, position.Y);
    }


    void LoadSprite(const Texture texture, const VectorMath::Vector2 position, const VectorMath::Vector2 size)
    {
        slSprite(texture, position.X, position.Y, size.X, size.Y);
    }

    void Rotate(const float angle)
    {
        slRotate(angle);
    }

    void Translate(const VectorMath::Vector2 &position)
    {
        slTranslate(position.X, position.Y);
    }
}
