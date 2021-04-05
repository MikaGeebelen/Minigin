#pragma once
class Obserever
{
public:

	enum class Event
	{
		died,
		tile,
		coily,
		disc,
		slick,
		sam
	};
	
	Obserever() = default;
	virtual ~Obserever() = 0;
	Obserever(const Obserever& other) = delete;
	Obserever(Obserever&& other) = delete;
	Obserever& operator=(const Obserever& other) = delete;
	Obserever& operator=(Obserever&& other) = delete;
public:
	virtual void OnNotify(Event event) = 0;
};

