#include "MainMenu.h"

#include <sl.h>

#include "Background.h"
#include "Buttons.h"
#include "ColorPalette.h"
#include "Fonts.h"
#include "Input.h"
#include "GameManager.h"
#include "SceneManager.h"
#include "VectorMath.h"

const int TITLE_FONT_SIZE = 80;
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
    while (!Input::IsKeyReleasing(SL_KEY_ENTER) && !GameManager::ShouldWindowClose())
    {

        Buttons::Input(buttons, selected, AMOUNT);
        Draw(buttons);
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



void MainMenu::Draw(Button buttons[])
{
    const int margin = 30;
    const int shadeSize = 3;
    VectorMath::Vector2 titleSize;

    Background::Draw();

    Fonts::SetFont(fonts.Title);
    Fonts::ChangeFontSize(TITLE_FONT_SIZE + shadeSize);
    titleSize = Fonts::GetTextSize(GAME_TITLE);
    Color::SetForeColor({0,0,0}, 0.2F);
    Fonts::TextPrint({SCREEN_WIDTH / 2.0F, SCREEN_HEIGHT - titleSize.Y + shadeSize - margin}, GAME_TITLE);

    Fonts::ChangeFontSize(TITLE_FONT_SIZE);
    titleSize = Fonts::GetTextSize(GAME_TITLE);
    SetForeColor(Color::coffee, 1.0);
    Fonts::TextPrint({SCREEN_WIDTH / 2.0F, SCREEN_HEIGHT - titleSize.Y - margin}, GAME_TITLE);

    RenderButtons(buttons, AMOUNT);

    GameManager::Render();
}
