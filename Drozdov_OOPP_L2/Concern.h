#pragma once
#include "Car.h"
#include "SportCar.h"

class ConcernDrozdov
{
	vector<shared_ptr<vehicleDrozdov>> motorshow;
public:
	virtual void add_new();
	virtual void out_console();
	virtual void to_file();
	virtual void from_file();
	virtual void addSC();
	virtual void clear();
	virtual ~ConcernDrozdov()
	{
		motorshow.clear();
	}
};