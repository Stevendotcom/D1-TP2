#include "Rules.h"

#include <sl.h>

#include "Background.h"
#include "ColorPalette.h"
#include "Fonts.h"
#include "GameManager.h"
#include "Input.h"
#include "SceneManager.h"
#include "Sprites.h"

using namespace Fonts;
using namespace Sprites;

void Rules::Rules()
{
    constexpr int TITLE_SIZE = 80;
    constexpr int BODY_SIZE = 30;
    constexpr float MARGIN_Y = 60.0f;
    constexpr float MARGIN_Y_BODY = 55.0f;
    constexpr float MARGIN_X = 90.0f;
    constexpr float ALIGN = 10.0F;
    constexpr float BLEED = 25.0F;
    constexpr float BANNER_HEIGTH = 110.0F;
    constexpr float POWERS_IN_DIST = 190;
    constexpr VectorMath::Vector2 SIZE = {800, 200};
    constexpr VectorMath::Vector2 BUTTONS_SIZE = {40.0F, 40.0F};
    constexpr VectorMath::Vector2 POWERS_SIZE = {90.0F, 90.0F};

    while (!Input::IsKeyReleasing(SL_KEY_ENTER) && !GameManager::ShouldWindowClose())
    {
        Background::Draw();

        LoadSprite(sprites.TitleBack, {SCREEN_WIDTH / 2.0F, SCREEN_HEIGHT - BANNER_HEIGTH}, SIZE);

        SetForeColor(Color::coffee, 1);

        ChangeFontSize(TITLE_SIZE);
        CenterText();
        SetFont(fonts.Title);
        TextPrint({SCREEN_WIDTH / 2.0F, SCREEN_HEIGHT - MARGIN_Y - TITLE_SIZE}, "Rules");

        SetForeColor(Color::dimGray, 1);

        ChangeFontSize(BODY_SIZE);
        SetFont(fonts.Body);
        TextPrint({SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT - MARGIN_Y - TITLE_SIZE - BODY_SIZE},
                  "Press Enter key to return");

        TextAlignLeft();
        TextPrint({MARGIN_X, SCREEN_HEIGHT / 2.0F},
                  "Your objective, is to destroy the most amount of blocks possible, \nin the least amount of time");
        TextPrint({MARGIN_X, SCREEN_HEIGHT / 2.0F - BODY_SIZE - MARGIN_Y_BODY}, "Controls: ");

        TextPrint({BLEED + MARGIN_X + BUTTONS_SIZE.X, SCREEN_HEIGHT / 2.0F - (BODY_SIZE + MARGIN_Y_BODY) * 2.0F}, "To move left");
        TextPrint({BLEED + MARGIN_X + BUTTONS_SIZE.X, SCREEN_HEIGHT / 2.0F - (BODY_SIZE + MARGIN_Y_BODY) * 3.0F}, "To move right");
        TextPrint({BLEED + MARGIN_X + BUTTONS_SIZE.X, SCREEN_HEIGHT / 2.0F - (BODY_SIZE + MARGIN_Y_BODY) * 4.0F}, "To Pause");

        TextPrint({SCREEN_WIDTH / 2.0F, SCREEN_HEIGHT / 2.0F - BODY_SIZE - MARGIN_Y_BODY}, "The Powers Are: ");

        TextPrint({SCREEN_WIDTH / 2.0F, SCREEN_HEIGHT / 2.0F - (BODY_SIZE + MARGIN_Y_BODY + 20) * 2.0F}, "Rotate Screen");
        TextPrint({SCREEN_WIDTH / 2.0F, SCREEN_HEIGHT / 2.0F - (BODY_SIZE + MARGIN_Y_BODY + 20) * 3.0F}, "Invert controls");
        TextPrint({SCREEN_WIDTH / 2.0F + POWERS_IN_DIST, SCREEN_HEIGHT / 2.0F - (BODY_SIZE + MARGIN_Y_BODY + 20) * 2.0F}, "Increase lives");
        TextPrint({SCREEN_WIDTH / 2.0F + POWERS_IN_DIST, SCREEN_HEIGHT / 2.0F - (BODY_SIZE + MARGIN_Y_BODY + 20) * 3.0F}, "Go faster");

        SetForeColor(Color::white, 1);
        LoadSprite(sprites.LeftArrow, { BLEED + MARGIN_X, SCREEN_HEIGHT / 2.0F - (BODY_SIZE + MARGIN_Y_BODY) * 2.0F + ALIGN}, BUTTONS_SIZE);
        LoadSprite(sprites.RightArrow, {BLEED + MARGIN_X, SCREEN_HEIGHT / 2.0F - (BODY_SIZE + MARGIN_Y_BODY) * 3.0F + ALIGN}, BUTTONS_SIZE);
        LoadSprite(sprites.P, {BLEED + MARGIN_X, SCREEN_HEIGHT / 2.0F - (BODY_SIZE + MARGIN_Y_BODY) * 4.0F + ALIGN}, BUTTONS_SIZE);

        LoadSprite(sprites.Rotate, {BLEED + SCREEN_WIDTH / 2.0F, SCREEN_HEIGHT / 2.0F - (BODY_SIZE + MARGIN_Y_BODY) * 2.0F + ALIGN}, POWERS_SIZE);
        LoadSprite(sprites.Invert, {BLEED + SCREEN_WIDTH / 2.0F, SCREEN_HEIGHT / 2.0F - (BODY_SIZE + MARGIN_Y_BODY) * 3.0F + ALIGN}, POWERS_SIZE);
        LoadSprite(sprites.OneUp, {BLEED + SCREEN_WIDTH / 2.0F + POWERS_IN_DIST, SCREEN_HEIGHT / 2.0F - (BODY_SIZE + MARGIN_Y_BODY) * 2.0F + ALIGN}, POWERS_SIZE);
        LoadSprite(sprites.Faster, { BLEED + SCREEN_WIDTH / 2.0F + POWERS_IN_DIST, SCREEN_HEIGHT / 2.0F - (BODY_SIZE + MARGIN_Y_BODY) * 3.0F + ALIGN}, POWERS_SIZE);


        GameManager::Render();

    }
    ChangeScene(SceneManager::Scenes::MainMenu);

}
