#pragma once
#include "Car.h"
class SportCarDrozdov : public vehicleDrozdov
{
	int engine_power = 0;
	int torque = 0;
public:
	DECLARE_SERIAL(SportCarDrozdov)
	SportCarDrozdov() {}
	virtual ~SportCarDrozdov() {}
	virtual void output();
	virtual void input();
	virtual void Serialize(CArchive& ar);
};

