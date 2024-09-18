#include "Wrapper.h"
#include "KeyStates.h"
#include "sl.h"

#include <iostream>
#include <random>


void Wrapper::InitWindow(const int width, const int height, const std::string &title, const bool fullScreen)
{
    srand(time(nullptr));
    slWindow(width, height, title.c_str(), fullScreen);
}


void Wrapper::CloseWindow()
{
    slClose();
}


bool Wrapper::ShouldWindowClose()
{
    return static_cast<bool>(slShouldClose());
}


bool Wrapper::IsKeyDown(const int key)
{
   return slGetKey(key);
}



bool Wrapper::IsKeyAboutToPress(const int key)
{
    //TODO CHECK IF NEEDED
    return IsKeyDown(key) && !KeyStates::GetPreviousKeyState(key);

}


bool Wrapper::IsKeyReleasing(const int key)
{
    // if key is down
    if (IsKeyDown(key))
    {
        //if it was not down
        if(!KeyStates::GetPreviousKeyState(key))
        {
            KeyStates::TogglePreviousKeyState(key);
        }
    }
    //key is up
    else
    {
        //was down
        if(KeyStates::GetPreviousKeyState(key))
        {
            KeyStates::TogglePreviousKeyState(key);
            return true;
        }
    }
    return false;
}


Wrapper::Vector2 Wrapper::GetMousePos()
{
    return {static_cast<float>(slGetMouseX()), static_cast<float>(slGetMouseY())};
}


void Wrapper::Render()
{

    slRender();

}


Wrapper::Texture Wrapper::LoadTexture(const std::string &filename)
{
    return slLoadTexture(filename.c_str());
}


Wrapper::WAV Wrapper::LoadWAV(const std::string &filename)
{
    return slLoadWAV(filename.c_str());
}


Wrapper::Sound Wrapper::SoundPlay(const WAV file)
{
    return slSoundPlay(file);
}


Wrapper::Sound Wrapper::SoundLoop(const WAV file)
{
    return slSoundLoop(file);
}


void Wrapper::SoundPause(const Sound sound)
{
    slSoundPause(sound);
}


void Wrapper::SoundStop(const Sound sound)
{
    slSoundStop(sound);
}


void Wrapper::SoundPauseAll()
{
    slSoundPauseAll();
}


void Wrapper::SoundStopAll()
{
    slSoundStopAll();
}


void Wrapper::SoundResumeAll()
{
    slSoundResumeAll();
}


bool Wrapper::IsSoundPlaying(Sound sound)
{
    return false;
}


bool Wrapper::IsSoundLooping(const Sound sound)
{
    return slSoundLooping(sound);
}


void Wrapper::SetSpriteTiling(const Vector2 position)
{
    slSetSpriteTiling(static_cast<float>(position.X), static_cast<float>(position.Y));
}


void Wrapper::SetSpriteScroll(Vector2 position)
{
    if (position.X > FLT_EPSILON + 1.0f && position.X < 0 && position.Y < 0 && position.Y > FLT_EPSILON + 1.0f)
    {
        std::cout << "Scroll higher than the permitted amount";
        abort();
    }
    slSetSpriteScroll(position.X, position.Y);
}


void Wrapper::LoadSprite(const Texture texture, const Vector2 position, Vector2 size)
{
    slSprite(texture, position.X, position.Y, size.X, size.Y);
}


Wrapper::Font Wrapper::LoadFont(const std::string &filename)
{
    return slLoadFont(filename.c_str());
}

void Wrapper::LoadAllFonts()
{
    title = LoadFont(ASSETS_DIR + "Antiquity-Print/antiquity-print.ttf");
    button = LoadFont(ASSETS_DIR + "DirtyHarold_Font/DirtyHarold.ttf");
}

void Wrapper::SetFont(Font font)
{
    slSetFont(font, fontSize);
}


void Wrapper::ChangeFontSize(int size)
{
    fontSize = size;
    slSetFontSize(fontSize);
}


void Wrapper::TextPrint(const Vector2 position, const std::string &text)
{
    slText(position.X, position.Y, text.c_str());
}

Wrapper::Vector2 Wrapper::GetTextSize(const std::string &text)
{
    return {static_cast<float>(slGetTextWidth(text.c_str())), static_cast<float>(slGetTextHeight(text.c_str()))};
}


void Wrapper::SetBackColor(const Color::Color &color)
{
    slSetBackColor(color.Red, color.Green, color.Blue);
}


void Wrapper::SetForeColor(const Color::Color &color, const float opacity)
{
    slSetForeColor(color.Red, color.Green, color.Blue, opacity);
}


void Wrapper::SetAdditiveBlend(const bool enable)
{
    slSetAdditiveBlend(enable);
}


int Wrapper::GetRandom(const int min, const int max)
{
    return rand() % (max + 1 - min) + min;
}


void Wrapper::CenterText()
{
    slSetTextAlign(SL_ALIGN_CENTER);
}

float Wrapper::GetFrameTime()
{
    return slGetDeltaTime();
}

