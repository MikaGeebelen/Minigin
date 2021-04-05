#pragma once
#include "SoundSystem.h"
class ServiceLocater
{
private:
	static BaseSoundSystem* m_pSoundSystem;
public:
	static void DestroySoundSystem();
	static BaseSoundSystem& GetSoundSystem();
	static void RegisterSoundSystem(BaseSoundSystem* pSoundSystem);
};
