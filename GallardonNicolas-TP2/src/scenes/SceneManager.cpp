#include "SceneManager.h"
#include "Wrapper.h"

static SceneManager::Scenes setScene = SceneManager::Scenes::MainMenu;



void SceneManager::Manager()
{
    bool exit = false;
    while (!Wrapper::ShouldWindowClose() && !exit)
    {
        switch (setScene)
        {
        case Scenes::MainMenu:
            //MainMenu();
            break;
        case Scenes::Play:
            //Play();
            break;
        case Scenes::Credits:
            //Credits();
            break;
        case Scenes::Exit:
            //Exit();
            exit = true;
            break;
        case Scenes::Rules:
            break;
        }
    }
    Wrapper::CloseWindow();
}



void SceneManager::ChangeScene(Scenes scene)
{
    setScene = scene;
}
