#pragma once
#include "BaseComponent.h"
#include "Observer.h"
#include "vector"
class ObserverComponent;
class Event;
class SubjectComponent : public BaseComponent
{
public:
	SubjectComponent(GameObject* const parent);
	~SubjectComponent();
	SubjectComponent(const SubjectComponent& other) = delete;
	SubjectComponent(SubjectComponent&& other) = delete;
	SubjectComponent& operator=(const SubjectComponent& other) = delete;
	SubjectComponent& operator=(SubjectComponent&& other) = delete;
	
	void AddObserver(ObserverComponent* obserever);
	void RemoveObserver(ObserverComponent* obserever);


	void Notify(Event* event);
	void Render() override;
	void Update(const float& deltaTime) override;

private:
	std::vector<ObserverComponent*> m_pObserevers;
};
