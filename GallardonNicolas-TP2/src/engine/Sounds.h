#pragma once
#include <string>

typedef int WAV;
typedef int Sound;

namespace Sounds
{
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


};
