#include "pch.h"
#include "Car.h"
IMPLEMENT_SERIAL(vehicleDrozdov, CObject, 0);

istream& operator >> (istream& in, CString& Cstr)
{
	string tmp;
	in >> tmp;
	Cstr = tmp.c_str();
	return in;
}


void vehicleDrozdov::input()
{
	cout << "Введите название автомобиля:" << endl;
	cin.ignore();
	cin >> name;
	cout << "Введите год выпуска:" << endl;
	check_menu(year, 1800, 2020);
	cout << "Введите начальную цену в $:" << endl;
	check_menu(strt_prc, 0.0, 99999999999.0);
}

void vehicleDrozdov::output()
{
	cout << "Автомобиль: " << name << endl;
	cout << "Год выпуска:  " << year << endl;
	cout << "Начальная цена в $: " << strt_prc << endl;
}

void vehicleDrozdov::Serialize(CArchive& ar)
{
	if (ar.IsStoring()) 
	{
		ar << year;
		ar << strt_prc; 
		ar << name;
	}
	else
	{
		ar >> year;
		ar >> strt_prc;
		ar >> name;
	}
}
