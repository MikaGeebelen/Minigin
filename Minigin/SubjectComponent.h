#pragma once
#include "BaseComponent.h"
#include "Observer.h"
class ObserverComponent;
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


	void Notify(Observer::Events event);
	void Render() override;
	void Update(const float& deltaTime) override;

private:
	std::vector<ObserverComponent*> m_pObserevers;
};
