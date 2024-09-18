#include "MainMenu.h"

#include <sl.h>

#include "KeyStates.h"
#include "SceneManager.h"

const int TITLE_FONT_SIZE = 100;
const int AMOUNT = 4;

using namespace Buttons;


void MainMenu::Menu()
{
    int selected = 0;
    Button buttons[AMOUNT];

    MakeButtons(buttons);

    Wrapper::SetBackColor({1, 1, 1});
    Wrapper::CenterText();


    Draw(buttons);
    while (!Wrapper::IsKeyDown(SL_KEY_ENTER) && !Wrapper::ShouldWindowClose())
    {
        Input(buttons, selected);
        Draw(buttons);
        Wrapper::Render();
    }

    SceneManager::ChangeScene(static_cast<SceneManager::Scenes>(selected + 1));
}


void MainMenu::MakeButtons(Buttons::Button buttons[])
{
    const int width = 360;
    const int height = 100;
    const Wrapper::Texture sprite = Wrapper::LoadTexture(ASSETS_DIR + "Pixelarium/banner.png");

    for (int i = 0; i < AMOUNT; i++)
    {
        buttons[i] =
        {
            {SCREEN_WIDTH / 2.0f, height * static_cast<float>(AMOUNT - i) + 50.0f},
            {width, height},
            sprite,
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
    if (Wrapper::IsKeyReleasing(SL_KEY_DOWN))
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
    else if (Wrapper::IsKeyReleasing(SL_KEY_UP))
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

    Wrapper::SetFont(title);
    Wrapper::ChangeFontSize(TITLE_FONT_SIZE);
    titleSize = Wrapper::GetTextSize(GAME_TITLE);
    Wrapper::SetForeColor(Color::coffee, 1.0);

    Wrapper::TextPrint({SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT - titleSize.Y - margin}, "Game name");

    RenderButtons(buttons, AMOUNT);
}

