﻿#include "MainMenu.h"

#include <sl.h>

#include "Buttons.h"
#include "ColorPalette.h"
#include "Fonts.h"
#include "Input.h"
#include "GameManager.h"
#include "SceneManager.h"
#include "VectorMath.h"

const int TITLE_FONT_SIZE = 100;
const int AMOUNT = 4;

using namespace Buttons;


void MainMenu::Menu()
{
    int selected = 0;
    Button buttons[AMOUNT];

    MakeButtons(buttons);

    Color::SetBackColor({1, 1, 1});
    Fonts::CenterText();


    Draw(buttons);
    while (!Input::IsKeyDown(SL_KEY_ENTER) && !GameManager::ShouldWindowClose())
    {
        Input(buttons, selected);
        Draw(buttons);
        GameManager::Render();
    }

    SceneManager::ChangeScene(static_cast<SceneManager::Scenes>(selected + 1));
}


void MainMenu::MakeButtons(Buttons::Button buttons[])
{
    const int width = 360;
    const int height = 100;

    for (int i = 0; i < AMOUNT; i++)
    {
        buttons[i] =
        {
            {SCREEN_WIDTH / 2.0F, height * static_cast<float>(AMOUNT - i) + 50.0F},
            {width, height},
            sprites.Button,
            Color::dimGray,
            Color::french,
        };
        switch (static_cast<SceneManager::Scenes>(i + 1))
        {
        case SceneManager::Scenes::Play:
            buttons[i].Text = "Play";
            buttons[i].Selected = true;
            break;
        case SceneManager::Scenes::Credits:
            buttons[i].Text = "Credits";
            buttons[i].Selected = false;
            break;
        case SceneManager::Scenes::Rules:
            buttons[i].Text = "Rules";
            buttons[i].Selected = false;
            break;
        case SceneManager::Scenes::Exit:
            buttons[i].Text = "Exit";
            buttons[i].Selected = false;
            break;
        }
    }


}


void MainMenu::Input(Buttons::Button buttons[], int &selected)
{
    buttons[selected].Selected = false;
    if (Input::IsKeyReleasing(SL_KEY_DOWN))
    {
        if (selected == AMOUNT - 1)
        {
            selected = 0;
        }
        else
        {
            selected++;
        }
    }
    else if (Input::IsKeyReleasing(SL_KEY_UP))
    {
        if (selected == 0)
        {
            selected = AMOUNT - 1;
        }
        else
        {
            selected--;
        }
    }
    buttons[selected].Selected = true;
}


void MainMenu::Draw(Buttons::Button buttons[])
{
    const int margin = 30;
    VectorMath::Vector2 titleSize;

    Fonts::SetFont(fonts.Title);
    Fonts::ChangeFontSize(TITLE_FONT_SIZE);
    titleSize = Fonts::GetTextSize(GAME_TITLE);
    SetForeColor(Color::coffee, 1.0);

    Fonts::TextPrint({SCREEN_WIDTH / 2.0F, SCREEN_HEIGHT - titleSize.Y - margin}, "Game name");

    RenderButtons(buttons, AMOUNT);
}
