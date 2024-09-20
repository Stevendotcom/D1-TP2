#include "SceneManager.h"

#include <iostream>

#include "MainMenu.h"
#include "GameManager.h"


namespace SceneManager
{
    Scenes setScene = Scenes::MainMenu;

    void Manager()
    {
        bool exit = false;
        while (!GameManager::ShouldWindowClose() && !exit)
        {
            switch (setScene)
            {
            case Scenes::MainMenu:
                MainMenu::Menu();
                break;
            case Scenes::Play:
                //Play();
                std::cout << "Playing..." << std::endl;
                setScene = Scenes::MainMenu;
                break;
            case Scenes::Credits:
                //Credits();
                std::cout << "Credits..." << std::endl;
                setScene = Scenes::MainMenu;
                break;
            case Scenes::Rules:
                std::cout << "rules..." << std::endl;
                setScene = Scenes::MainMenu;
                break;
            case Scenes::Exit:
                //Exit();
                std::cout << "exit..." << std::endl;
                exit = true;
                break;
            default:
                std::cerr << "Unknown Scene #" << static_cast<int>(setScene) << std::endl;
                abort();
            }
        }
        GameManager::CloseWindow();
    }


    void ChangeScene(Scenes scene)
    {
        setScene = scene;
    }
}
