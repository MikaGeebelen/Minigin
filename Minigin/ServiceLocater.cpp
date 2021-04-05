#include "MiniginPCH.h"
#include "ServiceLocater.h"
BaseSoundSystem* ServiceLocater::m_pSoundSystem = new NullSoundSystem();

void ServiceLocater::DestroySoundSystem()
{
	delete m_pSoundSystem;
}

BaseSoundSystem& ServiceLocater::GetSoundSystem()
{
	return *m_pSoundSystem;
}

void ServiceLocater::RegisterSoundSystem(BaseSoundSystem* pSoundSystem)
{
	delete m_pSoundSystem;
	m_pSoundSystem = pSoundSystem;
}
