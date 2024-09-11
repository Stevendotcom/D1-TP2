#include "Wrapper.h"
#include <random>

void Wrapper::InitWindow(int width, int height, std::string title, bool fullScreen)
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

bool Wrapper::IsKeyDown(Key key)
{
	return false;
}

bool Wrapper::IsKeyUp(Key key)
{
	return false;
}

bool Wrapper::IsKeyPressing(Key key)
{
	return false;
}

bool Wrapper::IsKeyReleasing(Key key)
{
	return false;
}

Wrapper::Vector2 Wrapper::GetMousePos()
{
	Vector2 position = { slGetMouseX(),slGetMouseY() };
	return position;
}

float Wrapper::GetDeltaTime()
{
	return 0.0f;
}

float Wrapper::TimeFromStart()
{
	return 0.0f;
}

void Wrapper::Render()
{
}

Wrapper::Texture Wrapper::LoadTexture(std::string filename)
{
	return Texture();
}

Wrapper::WAV Wrapper::LoadWAV(std::string filename)
{
	return WAV();
}

Wrapper::Sound Wrapper::SoundPlay(WAV file)
{
	return Sound();
}

Wrapper::Sound Wrapper::SoundLoop(WAV file)
{
	return Sound();
}

void Wrapper::SoundPause(Sound sound)
{
}

void Wrapper::SoundStop(Sound sound)
{
}

void Wrapper::SoundPauseAll()
{
}

void Wrapper::SoundStopAll()
{
}

void Wrapper::SoundResumeAll()
{
}

bool Wrapper::IsSoundPlaying(Sound sound)
{
	return false;
}

bool Wrapper::IsSoundLooping(Sound sound)
{
	return false;
}

void Wrapper::SetSpriteTiling(Vector2 position)
{
}

void Wrapper::SetSpriteScroll(Vector2 position)
{
}

void Wrapper::LoadSprite(Texture texture, Vector2 position, float width, float height)
{
}

Wrapper::Text Wrapper::LoadFont(std::string filename)
{
	return Text();
}

void Wrapper::SetFont(Text font)
{
}

void Wrapper::ChangeFontSize(int fontSize)
{
}

void Wrapper::TextPrint(Vector2 position, std::string text)
{
}

void Wrapper::SetBackColor(Color color)
{
}

void Wrapper::SetForeColor(Color color, float opacity)
{
}

void Wrapper::SetAdditiveBlend(bool enable)
{
}

int Wrapper::GetRandom(int min, int max)
{
	return rand() % (max + 1 - min) + min;
}
