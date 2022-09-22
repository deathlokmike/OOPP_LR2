#pragma once
#include "framework.h"
class vehicleDrozdov: public CObject
{
protected:
	CString name;
	int year = 0;
	double strt_prc = 0;
public:
	DECLARE_SERIAL(vehicleDrozdov)
	vehicleDrozdov() {}
	virtual ~vehicleDrozdov() {}
	virtual void output();
	virtual void input();
	virtual void Serialize(CArchive& ar);
};

template <typename T>
void check_menu(T& input, T min, T max)
{
	while (!(cin >> input) || (input > max) || (input < min))
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Неверные данные" << endl;
	}
}
