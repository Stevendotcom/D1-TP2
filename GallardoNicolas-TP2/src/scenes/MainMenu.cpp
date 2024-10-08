﻿#include "MainMenu.h"

#include <sl.h>

#include "Background.h"
#include "Buttons.h"
#include "ColorPalette.h"
#include "Fonts.h"
#include "Input.h"
#include "GameManager.h"
#include "SceneManager.h"
#include "VectorMath.h"

constexpr int AMOUNT = 4;

using namespace Buttons;
using namespace Fonts;
using namespace Color;
using namespace SceneManager;

void MainMenu::Menu()
{
    int selected = 0;
    Button buttons[AMOUNT];

    MakeButtons(buttons);

    SetBackColor({1, 1, 1});
    CenterText();


    Draw(buttons);
    while (!Input::IsKeyReleasing(SL_KEY_ENTER) && !GameManager::ShouldWindowClose())
    {

        Buttons::Input(buttons, selected, AMOUNT);
        Draw(buttons);
    }

    ChangeScene(static_cast<Scenes>(selected + 1));
}


void MainMenu::MakeButtons(Button buttons[])
{
    constexpr int width = 360;
    constexpr int height = 100;

    for (int i = 0; i < AMOUNT; i++)
    {
        buttons[i] =
        {
            {SCREEN_WIDTH / 2.0F, height * static_cast<float>(AMOUNT - i) + 50.0F},
            {width, height},
            sprites.Button,
            DIM_GRAY,
            WHITE,
        };
        switch (static_cast<Scenes>(i + 1))
        {
        case Scenes::Play:
            buttons[i].Text = "Play";
            buttons[i].Selected = true;
            break;
        case Scenes::Credits:
            buttons[i].Text = "Credits";
            buttons[i].Selected = false;
            break;
        case Scenes::Rules:
            buttons[i].Text = "Rules";
            buttons[i].Selected = false;
            break;
        case Scenes::Exit:
            buttons[i].Text = "Exit";
            buttons[i].Selected = false;
            break;
        }
    }


}


void MainMenu::Draw(Button buttons[])
{
    constexpr int TITLE_FONT_SIZE = 80;
    constexpr int SHADE_SIZE = 3;
    constexpr float MARGIN = 30;
    constexpr float BANNER_HEIGTH = 110.0F;
    constexpr VectorMath::Vector2 SIZE = {800, 200};
    VectorMath::Vector2 titleSize;

    Background::Draw();

    SetForeColor(WHITE, 1.0);
    Sprites::LoadSprite(sprites.TitleBack, {SCREEN_WIDTH / 2.0F, SCREEN_HEIGHT - BANNER_HEIGTH}, SIZE);

    SetFont(fonts.Title);

    ChangeFontSize(TITLE_FONT_SIZE + SHADE_SIZE);
    titleSize = GetTextSize(GAME_TITLE);
    SetForeColor({0, 0, 0}, 0.2F);
    TextPrint({SCREEN_WIDTH / 2.0F, SCREEN_HEIGHT - titleSize.Y + SHADE_SIZE - MARGIN}, GAME_TITLE);

    ChangeFontSize(TITLE_FONT_SIZE);
    titleSize = GetTextSize(GAME_TITLE);
    SetForeColor(COFFEE, 1.0);
    TextPrint({SCREEN_WIDTH / 2.0F, SCREEN_HEIGHT - titleSize.Y - MARGIN}, GAME_TITLE);

    RenderButtons(buttons, AMOUNT);

    GameManager::Render();
}
