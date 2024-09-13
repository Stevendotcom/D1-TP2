#include "MainMenu.h"
#include "SceneManager.h"

#include <sl.h>

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const std::string assetsDir;

const int titleHeight = SCREEN_HEIGHT - 48;
const int titleSize = 30;
const int amount = 4;

using namespace Buttons;



void MainMenu::Menu()
{
    int selected = 0;
    Button buttons[amount];
    MakeButtons(buttons);

    while (!Wrapper::IsKeyReleasing(SL_KEY_ENTER) && !Wrapper::ShouldWindowClose())
    {
        Input(buttons, selected);
        Draw();
    }

    SceneManager::ChangeScene(static_cast<SceneManager::Scenes>(selected + 1));
}



void MainMenu::MakeButtons(Buttons::Button buttons[])
{
    const int width = 50;
    const int height = 20;
    const Wrapper::Texture sprite = Wrapper::LoadTexture(assetsDir + "Pixelarium/banner.png");

    for(int i = 0; i < amount; i++)
    {
        buttons[i] =
        {
            {SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f + height * i},
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



void MainMenu::Input(Buttons::Button buttons[], int& selected)
{
    buttons[selected].Selected = false;
    if(Wrapper::IsKeyDown(SL_KEY_DOWN))
    {
        if(selected == amount)
        {
            selected = 0;
        }
        else
        {
            selected++;
        }
    }
    else if(Wrapper::IsKeyDown(SL_KEY_UP))
    {
        if(selected == 0)
        {
            selected = amount;
        }
        else
        {
            selected--;
        }
    }
    buttons[selected].Selected = true;
}



void MainMenu::Draw()
{
}
