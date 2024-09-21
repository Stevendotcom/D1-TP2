#include "Background.h"

#include "ColorPalette.h"
#include "Sprites.h"

void Background::Draw()
{
    SetForeColor(Color::white, 1.0);
    Sprites::LoadSprite(sprites.Background, {SCREEN_WIDTH / 2.0F, SCREEN_HEIGHT / 2.0F}, {
                                     static_cast<float>(SCREEN_WIDTH), static_cast<float>(SCREEN_HEIGHT)});
}
