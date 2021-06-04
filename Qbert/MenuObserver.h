#pragma once
#include <Observer.h>
#include <string>
class QbertApplication;
class MenuObserver final: public Observer
{
public:
	MenuObserver(const QbertApplication* pApplication);
	void OnNotify(Event* event) override;

private:
	int m_level;
	std::string m_GameMode;
	const QbertApplication* m_pApp;
};

