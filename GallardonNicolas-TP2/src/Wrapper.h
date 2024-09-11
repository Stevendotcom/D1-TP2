#pragma once
#include "sl.h"
#include <string>

namespace Wrapper
{
	struct Vector2
	{
		float X;
		float Y;
	};

	struct Color
	{
		float Red;
		float Green;
		float Blue;
	};

	typedef int Texture;
	typedef int WAV;
	typedef int Sound;
	typedef int Text;

	//Window

	void InitWindow(int width, int height, std::string title, bool fullScreen);
	void CloseWindow();
	bool ShouldWindowClose();
	
	//Input

	bool IsKeyDown(int key);
	bool IsKeyUp(int key);
	bool IsKeyPressing(int key);
	bool IsKeyReleasing(int key);
	Vector2 GetMousePos();
	
	//Time

	float GetDeltaTime();
	float TimeFromStart();

	//Rendering

	void Render();

	//Texture

	Texture LoadTexture(std::string filename);
	
	// Sound

	WAV LoadWAV(std::string filename);
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
	void LoadSprite(int texture, Vector2 position, double width, double height);
	
	//Text
	
	Text LoadFont(std::string filename);
	void SetFont(Text font);
	void ChangeFontSize(int fontSize);
	void TextPrint(Vector2 position, std::string text);

	//Color
	void SetBackColor(Color color);
	void SetForeColor(Color color, float opacity);
	void SetAdditiveBlend(bool enable);
		
}

