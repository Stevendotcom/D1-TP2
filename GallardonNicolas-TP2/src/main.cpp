#include "Wrapper.h"
#include "SceneManager.h"


const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 900;
const std::string ASSETS_DIR = "../assets/";
Wrapper::Font title;
Wrapper::Font button;

int main()
{
    Wrapper::InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "TEST", false);
    title = Wrapper::LoadFont(ASSETS_DIR + "Antiquity-Print/antiquity-print.ttf");
    button = Wrapper::LoadFont(ASSETS_DIR + "DirtyHarold_Font/DirtyHarold.ttf");
    SceneManager::Manager();
}
