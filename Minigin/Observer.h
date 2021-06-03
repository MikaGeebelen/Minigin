#pragma once
class Event;
class Observer
{
public:

	Observer() = default;
	virtual ~Observer();
	Observer(const Observer& other) = delete;
	Observer(Observer&& other) = delete;
	Observer& operator=(const Observer& other) = delete;
	Observer& operator=(Observer&& other) = delete;

	virtual void OnNotify(Event* event) = 0;

};

