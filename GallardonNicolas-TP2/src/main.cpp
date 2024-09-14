#include "Wrapper.h"
#include "SceneManager.h"


const int SCREEN_WIDTH = 1366;
const int SCREEN_HEIGHT = 768;
const std::string ASSETS_DIR = "../assets/";
const std::string GAME_TITLE = "Good Name";
Wrapper::Font title;
Wrapper::Font button;


int main()
{
    Wrapper::InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE, true);
    Wrapper::LoadAllFonts();
    SceneManager::Manager();
}
