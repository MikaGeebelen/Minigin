#pragma once
#include "BaseComponent.h"
#include "Observer.h"
class ObserverComponent : public BaseComponent
{
public:
	ObserverComponent(GameObject* const parent, Observer* observer);
	virtual ~ObserverComponent();
	ObserverComponent(const ObserverComponent& other) = delete;
	ObserverComponent(ObserverComponent&& other) = delete;
	ObserverComponent& operator=(const ObserverComponent& other) = delete;
	ObserverComponent& operator=(ObserverComponent&& other) = delete;

	virtual void OnNotify(Event* event);

	virtual void Render() override;
	virtual void Update(const float& deltaTime) override;
private:
	Observer* m_pObserver;
};
