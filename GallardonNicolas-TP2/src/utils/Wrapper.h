#pragma once
#include <string>
#include "ColorPalette.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const std::string ASSETS_DIR;


namespace Wrapper
{
    struct Vector2
    {
        float X;
        float Y;
    };


    typedef int Texture;
    typedef int WAV;
    typedef int Sound;
    typedef int Font;

    static int fontSize = 20;

    //Window

    void InitWindow(int width, int height, const std::string &title, bool fullScreen);
    void CloseWindow();
    bool ShouldWindowClose();

    //Input

    bool IsKeyDown(int key);
    bool IsKeyAboutToPress(int key);
    bool IsKeyReleasing(int key);
    Vector2 GetMousePos();

    //Rendering

    void Render();

    //Texture

    Texture LoadTexture(const std::string &filename);

    // Sound

    WAV LoadWAV(const std::string &filename);
    Sound SoundPlay(WAV file);
    Sound SoundLoop(WAV file);
    void SoundPause(Sound sound);
    void SoundStop(Sound sound);
    void SoundPauseAll();
    void SoundStopAll();
    void SoundResumeAll();
    bool IsSoundPlaying(Sound sound);
    bool IsSoundLooping(Sound sound);

    //Shape Drawing

    void SetSpriteTiling(Vector2 position);
    void SetSpriteScroll(Vector2 position);
    void LoadSprite(Texture texture, Vector2 position, Vector2 size);

    //Text

    Font LoadFont(const std::string &filename);
    void SetFont(Font font);
    void ChangeFontSize(int size);
    void TextPrint(Vector2 position, const std::string &text);

    //Color

    void SetBackColor(const Color::Color &color);
    void SetForeColor(const Color::Color &color, float opacity);
    void SetAdditiveBlend(bool enable);

    //Utility

    int GetRandom(int min, int max);
    void CenterText();
}
extern Wrapper::Font title;
extern Wrapper::Font button;