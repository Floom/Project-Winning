#pragma once
#include"Sound.h"

Sound::Sound()
{
	FMOD::System_Create(&system);
	system->init(100, FMOD_INIT_NORMAL, 0);
}

FMOD::Sound* Sound::CreateSound(char *title,bool stream)
{
	FMOD::Sound *data;
	if(stream == true)
		system->createStream(title, FMOD_DEFAULT, 0, &data);
	else
		system->createSound(title,FMOD_DEFAULT,0, &data);
	return data;
}

void Sound::PlaySoundA(FMOD::Sound *sound,float volume)
{
	system->playSound(FMOD_CHANNEL_FREE, sound, true, &channel);

	channel->setVolume(volume);		// Set the volume while it is paused.
	
	channel->setPaused(false);		// This is where the sound really starts.
	

}

void Sound::PauseSound(bool pause)
{
	channel->setPaused(pause);
}

Sound::~Sound()
{
	system->release();
}