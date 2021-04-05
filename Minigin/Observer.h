#pragma once
class Observer
{
public:
	enum Events
	{
		Died,
		Coily
	};
	
	Observer() = default;
	virtual ~Observer();
	Observer(const Observer& other) = delete;
	Observer(Observer&& other) = delete;
	Observer& operator=(const Observer& other) = delete;
	Observer& operator=(Observer&& other) = delete;

	virtual void OnNotify(Events event) = 0;


};

