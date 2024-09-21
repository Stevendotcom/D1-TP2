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
        sprites.PlayerHit = LoadTexture(ASSETS_DIR + "Tiny-Swords/WarriorHit.png");
        sprites.Background = LoadTexture(ASSETS_DIR + "Tiny-Swords/Background.png");
        sprites.Ball = LoadTexture(ASSETS_DIR + "Tiny-Swords/Sheep.png");
        sprites.Button = LoadTexture(ASSETS_DIR + "Pixelarium/banner.png");
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


    void SetSpriteScroll(VectorMath::Vector2 position)
    {
        if (position.X > FLT_EPSILON + 1.0f && position.X < 0 && position.Y < 0 && position.Y > FLT_EPSILON + 1.0f)
        {
            std::cout << "Scroll higher than the permitted amount";
            abort();
        }
        slSetSpriteScroll(position.X, position.Y);
    }


    void LoadSprite(const Texture texture, const VectorMath::Vector2 position, VectorMath::Vector2 size)
    {
        slSprite(texture, position.X, position.Y, size.X, size.Y);
    }
}
