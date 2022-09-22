#include "pch.h"
#include "SportCar.h"

IMPLEMENT_SERIAL(SportCarDrozdov, vehicleDrozdov, VERSIONABLE_SCHEMA | 0);

void SportCarDrozdov::input()
{
	vehicleDrozdov::input();
	cout << "Введите мощность двигателя в л.с.:" << endl;
	cin >> engine_power;
	cout << "Введите крутящий момент в н/м:" << endl;
	cin >> torque;
}

void SportCarDrozdov::output()
{
	vehicleDrozdov::output();
	cout << "Мощность двигателя в л.с.: " << engine_power << endl;
	cout << "Крутящий момент: " << torque << endl;
}

void SportCarDrozdov::Serialize(CArchive& ar)
{
	vehicleDrozdov::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << engine_power;
		ar << torque;
	}
	else
	{
		ar >> engine_power;
		ar >> torque;
	}
}