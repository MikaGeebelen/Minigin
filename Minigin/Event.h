#pragma once
class Event
{
public:
	Event() = default;
	virtual ~Event() = default;
	Event(const Event& other) = delete;
	Event(Event&& other) = delete;
	Event& operator=(const Event& other) = delete;
	Event& operator=(Event&& other) = delete;
	
	virtual  int GetEvent() = 0;
};


