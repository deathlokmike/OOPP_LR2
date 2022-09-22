#include "pch.h"
#include "SportCar.h"

IMPLEMENT_SERIAL(SportCarDrozdov, vehicleDrozdov, VERSIONABLE_SCHEMA | 0);

void SportCarDrozdov::input()
{
	vehicleDrozdov::input();
	cout << "������� �������� ��������� � �.�.:" << endl;
	cin >> engine_power;
	cout << "������� �������� ������ � �/�:" << endl;
	cin >> torque;
}

void SportCarDrozdov::output()
{
	vehicleDrozdov::output();
	cout << "�������� ��������� � �.�.: " << engine_power << endl;
	cout << "�������� ������: " << torque << endl;
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