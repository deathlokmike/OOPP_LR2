#include "pch.h"
#include "Concern.h"


void ConcernDrozdov::add_new()
{
	shared_ptr<vehicleDrozdov> vhl(new vehicleDrozdov);
	vhl->input();
	motorshow.push_back(vhl);
	system("cls");
	cout << "Автомобиль добавлен, выберите пункт для продолжения:" << endl;
}

void ConcernDrozdov::out_console()
{
	if (motorshow.size() != 0) 
	{
		system("cls");
		for (int i = 0; i < int(motorshow.size()); i++)
		{
			cout << i + 1 << ") ";
			(*motorshow[i]).output();
			cout << endl;
		}
	}
	else
	{
		system("cls");
		cerr << "В каталоге нет авто\n" << endl;
	}
}

void ConcernDrozdov::to_file()
{
	if (motorshow.size() != 0) 
	{
		system("cls");
		string path;
		cout << "Укажите название файла:" << endl;
		cin >> path;
		path += ".txt";
		CFile file(path.c_str(), CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		ar << this->motorshow.size();
		for (auto& vhcl : motorshow)
		{
			ar << vhcl.get();
		}
		system("cls");
		cout << "Готово!\n" << endl;
	}
	else
	{
		system("cls");
		cerr << "В каталоге нет авто\n" << endl;
	}
}

void ConcernDrozdov::from_file()
{
	system("cls");
	int count_str;
	string path;
	cout << "Укажите название файла:" << endl;
	cin >> path;
	path += ".txt";
	CFileStatus status;
	if (CFile::GetStatus(path.c_str(), status))
	{
		CFile file(path.c_str(), CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		ar >> count_str;
		for (int i = 0; i < count_str; i++)
		{
			vehicleDrozdov* vhcl;
			ar >> vhcl;
			motorshow.push_back(shared_ptr<vehicleDrozdov>(vhcl));
		}
		system("cls");
		cout << "Готово!\n" << endl;
	}
	else
	{
		system("cls");
		cerr << "Ошибка чтения файла" << endl;
	}
}

void ConcernDrozdov::addSC()
{
	shared_ptr<vehicleDrozdov>vhcl = make_shared<SportCarDrozdov>();
	vhcl->input();
	motorshow.push_back(vhcl);
	system("cls");
	cout << "Спорткар добавлен, выберите пункт для продолжения:" << endl;
}

void ConcernDrozdov::clear()
{
	motorshow.clear();
	system("cls");
	cout << "Список очищен\n" << endl;
}
