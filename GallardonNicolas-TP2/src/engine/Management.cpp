#include "sl.h"
#include "VectorMath.h"

#include <random>

namespace Management
{
    void InitWindow(const int width, const int height, const std::string &title, const bool fullScreen)
    {
        srand(time(nullptr));
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
        return slGetDeltaTime();
    }
}
