// Drozdov_OOPP_L2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include "pch.h"
#include "framework.h"
#include "Drozdov_OOPP_L2.h"
#include "Concern.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


void Menu()
{
	cout << "1. Добавить авто в картотеку\n" <<
		"2. Показать каталог авто\n" <<
		"3. Сохранить базу авто в файл\n" <<
		"4. Загрузить базу авто из файла\n" <<
		"5. Отчистить список\n" <<
		"6. Добавить спорткар в картотеку\n" <<
		"0. Закрыть программу" << endl;
}


CWinApp theApp;


int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            wprintf(L"Критическая ошибка: сбой при инициализации MFC\n");
            nRetCode = 1;
        }
        else
        {
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
			setlocale(LC_ALL, "Rus");
			int n;
			ConcernDrozdov concern;
			for (;;)
			{
				Menu();
				check_menu(n, 0, 6);
				switch (n)
				{
				case 1:
					concern.add_new();
					break;
				case 2:
					concern.out_console();
					break;
				case 3:
					concern.to_file();
					break;
				case 4:
					concern.from_file();
					break;
				case 5:
					concern.clear();
					break;
				case 6:
					concern.addSC();
					break;
				case 0:
					return 0;
				default:
					break;
				}
			}
        }
    }
    else
    {
        // TODO: измените код ошибки в соответствии с потребностями
        wprintf(L"Критическая ошибка: сбой GetModuleHandle\n");
        nRetCode = 1;
    }
    return nRetCode;
}
