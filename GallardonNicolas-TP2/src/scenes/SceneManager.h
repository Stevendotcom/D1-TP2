#pragma once

namespace SceneManager
{

    enum class Scenes
    {
        MainMenu,
        Play,
        Credits,
        Rules,
        Exit
    };

    void Manager();
    void ChangeScene(Scenes scene);
}
