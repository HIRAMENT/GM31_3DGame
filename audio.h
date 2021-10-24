#pragma once

#include <xaudio2.h>
#include "resource.h"


class Audio : public ResourceData
{
private:
	static IXAudio2*				m_Xaudio;
	static IXAudio2MasteringVoice*	m_MasteringVoice;

	IXAudio2SourceVoice*	m_SourceVoice;
	BYTE*					m_SoundData;

	int						m_Length;
	int						m_PlayLength;


public:
	Audio() = delete;
	Audio(const char *Filename);


	static void InitMaster();
	static void UninitMaster();

	void Init() {};
	void Uninit();
	void Update() {};
	void Draw() {};

	void Load(const char *FileName);
	void Play(bool Loop = false);
	void Stop();


};

