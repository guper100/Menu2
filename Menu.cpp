#include <iostream>
#include <clocale>
#include <Windows.h>
#include "Functions.h"
using namespace std;

std::wstring strToWStr(const std::string& s) // to translate a string filled from cin to wstring for ShellExecute function
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}


void menu_2()
{
	Sleep(500u);
	
	cout << "1. Open calculator" << endl;
	cout << "2. Open explorer" << endl;
	cout << "3. Open specific path" << endl;
	cout << "4. Exit" << endl << endl;

	bool in_menu_2 = true;
	while (in_menu_2 == true)
	{
		if (GetAsyncKeyState(VK_NUMPAD1))
		{
			ShellExecute(0, L"open", L"calc.exe", NULL, NULL, SW_SHOWNORMAL);
		}
		else if (GetAsyncKeyState(VK_NUMPAD2))
		{
			ShellExecute(0, L"open", L"explorer.exe", NULL, NULL, SW_SHOWNORMAL);
		}
		else if (GetAsyncKeyState(VK_NUMPAD3))
		{
			string path;
			cout << "Enter path: " << endl;
			cin >> path;
			wstring w_path = strToWStr(path);
			ShellExecute(0, L"open", w_path.c_str(), NULL, NULL, SW_SHOWNORMAL);
		}
		else if (GetAsyncKeyState(VK_NUMPAD4))
		{
			in_menu_2 = false;
			main_menu();
		}
	}
}

void menu_1()
{
	Sleep(500u);

	cout << "1. Open VK" << endl;
	cout << "2. DONovsu" << endl;
	cout << "3. NovsuMail" << endl;
	cout << "4. Exit" << endl << endl;

	bool in_menu_1 = true;
	while (in_menu_1 == true)
	{
		if (GetAsyncKeyState(VK_NUMPAD1))
		{
			ShellExecute(0, L"open", L"https://vk.com", NULL, NULL, SW_SHOWNORMAL);
		}
		else if (GetAsyncKeyState(VK_NUMPAD2))
		{
			ShellExecute(0, L"open", L"http://do.novsu.ru/", NULL, NULL, SW_SHOWNORMAL);
		}
		else if (GetAsyncKeyState(VK_NUMPAD3))
		{
			ShellExecute(0, L"open", L"https://www.novsu.ru/mail/", NULL, NULL, SW_SHOWNORMAL);
		}
		else if (GetAsyncKeyState(VK_NUMPAD4))
		{
			in_menu_1 = false;
			main_menu();
		}
	}
}

bool main_menu()
{
	Sleep(500u);

	cout << "1. Open site" << endl;
	cout << "2. Open application" << endl;
	cout << "3. Exit" << endl << endl;

	bool in_main_menu = true;
	while (in_main_menu == true)
	{
		if (GetAsyncKeyState(VK_NUMPAD1))
		{
			in_main_menu = false;
			menu_1();
		}
		else if (GetAsyncKeyState(VK_NUMPAD2))
		{
			in_main_menu = false;
			menu_2();
		}
		else if (GetAsyncKeyState(VK_NUMPAD3))
		{
			in_main_menu = false;
			return false;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	if (main_menu() == false)
		return 0;
}