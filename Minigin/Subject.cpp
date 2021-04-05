#include "MiniginPCH.h"
#include "Subject.h"


Subject::~Subject()
{
	for (Obserever* observer : m_pObserever)
	{
		delete observer;
	}
}

void Subject::AddObserver(Obserever* obserever)
{
	m_pObserever.push_back(obserever);
}

void Subject::RemoveObserver(Obserever* obserever)
{
	std::vector<Obserever*>::iterator it = std::find(m_pObserever.begin(), m_pObserever.end(), obserever);
	if (it != m_pObserever.end())
	{
		m_pObserever.erase(it);
	}
}

void Subject::Notify(Obserever::Event event)
{
	for (Obserever* observer: m_pObserever)
	{
		observer->OnNotify(event);
	}
}
