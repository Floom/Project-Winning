#pragma once
#include"fmod.hpp"
#include"fmod_errors.h"
#include"fmod_codec.h"
#include"fmod_dsp.h"
#include"fmod_memoryinfo.h"
#include"fmod_output.h"


class Sound
{
public:
	Sound();
	~Sound();
	FMOD::Sound* Sound::CreateSound(char *title,bool stream);
	void PlaySoundA(FMOD::Sound *sound,float volume);
	void PauseSound(bool pause);
	FMOD::System *system;
	FMOD::Channel *channel;
};
