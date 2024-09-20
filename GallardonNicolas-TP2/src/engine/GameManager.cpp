#include <random>


#include "GameManager.h"
#include "Fonts.h"
#include "Sprites.h"
#include "sl.h"
#include "VectorMath.h"
#include "SceneManager.h"


namespace GameManager
{
    void Start()
    {
        srand(static_cast<unsigned int>(time(nullptr)));
        InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE, false);
        LoadAllFonts(fonts);
        LoadSprites(sprites);
        SceneManager::Manager();
    }



    void InitWindow(const int width, const int height, const std::string &title, const bool fullScreen)
    {
        slWindow(width, height, title.c_str(), fullScreen);
    }



    void CloseWindow()
    {
        slClose();
    }



    bool ShouldWindowClose()
    {
        return static_cast<bool>(slShouldClose());
    }



    VectorMath::Vector2 GetMousePos()
    {
        return {static_cast<float>(slGetMouseX()), static_cast<float>(slGetMouseY())};
    }



    void Render()
    {

        slRender();

    }



    int GetRandom(const int min, const int max)
    {
        return rand() % (max + 1 - min) + min;
    }



    float GetFrameTime()
    {
        return static_cast<float>(slGetDeltaTime());
    }
}
