#pragma once
#include "Obserever.h"
#include <vector>
class Subject
{
public:
	Subject() = default;
	~Subject();
	
	void AddObserver(Obserever* obserever);
	void RemoveObserver(Obserever* obserever);


	void Notify(Obserever::Event event);
private:
	std::vector<Obserever*> m_pObserever;
};

