#include "System.h"
#include <fstream>
#include<iostream>
#include <string>
using namespace std;

void System::createTask(string text, string tag, bool priority, string date)
{
	Task ts(text, tag, priority, date);
	if (priority)
	{
		pt.push_back(ts);
		saveTask();
	}
	else
	{
		t.push_back(ts);
		saveTask();
	}
}

void System::loadTask()
{
	ifstream f;
	f.open("Tasks.txt", ios::app);
	if (f.is_open())
	{
		while (!f.eof())
		{
			Task ts;
			string text, tag, date;
			getline(f, text, '\n');
			if (text == "")
			{
				break;
			}
			getline(f, tag, '\n');
			getline(f, date, '\n');
			ts.setText(text);
			ts.setTag(tag);
			ts.setPriority(0);
			ts.setDate(date);
			t.push_back(ts);
		}
	}
	f.close();
	f.open("PriorTasks.txt", ios::app);
	if (f.is_open())
	{
		while (!f.eof())
		{
			Task ts;
			string text, tag, date;
			getline(f, text, '\n');
			if (text == "")
			{
				break;
			}
			getline(f, tag, '\n');
			getline(f, date, '\n');
			ts.setPriority(1);
			ts.setText(text);
			ts.setTag(tag);
			ts.setDate(date);
			pt.push_back(ts);
		}
	}
	f.close();
}

void System::menu()
{
	loadTask();
	while(true)
	{
		int menu = 0;
		cout << "1)Создать задание" << endl;
		cout << "2)Посмотреть созданые задания" << endl;
		cout << "3)Редактировать задание" << endl;
		cout << "0)Выход" << endl;
		cin >> menu;
			switch (menu)
			{
			case 1: createMenu(); break;
			case 2: showMenu(); break;
			case 3: redMenu(); break;
			case 0:exit(0); break;
			default:
				cout << "Такого варианта нет" << endl;
				break;
			}
	}
}

void System::createMenu()
{
	system("cls");
	string text, tag, date, pr;
	bool prior = true;
	cin.ignore(123, '\n');
	cout << "Введите текст задания: ";
	getline(cin, text);

	cout << "Введите тег задания: ";
	getline(cin, tag);


	cout << "Важно ли это задание(да/нет): ";
	cin >> pr;
	if (pr == "да")
	{
		prior = true;
	}
	if (pr == "нет")
	{
		prior = false;
	}

	cin.ignore(123, '\n');
	cout << "Введите дату выполнения задания: ";
	getline(cin, date);
	createTask(text, tag, prior, date);
	cout << "Ваше задание создано" << endl;
	system("pause");
	system("cls");
}

void System::showMenu()
{
	system("cls");
	int menu;
	cout << "1) Показать задания с приоритетом" << endl;;
	cout << "2) Показать задания без приоритете" << endl;;
	cout << "0) Выйти из меню" << endl;
	cin >> menu;
	switch (menu)
	{
	case 1: system("cls"); Pmenu(); break;
	case 2: system("cls"); Tmenu(); break;
	case 0: break;
	default:
		break;
	}
}

void System::redMenu()
{
	int choice;
	cout << "1) Редактиовать важные задачи" << endl;
	cout << "2) Редактировать не важные задачи" << endl;
	cout << "0) Выход" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1: PRed(); break;
	case 2: TRed(); break;
	case 0: break;
	default:
		break;
	}
}

void System::saveTask()
{
	ofstream f;
	if (!t.empty())
	{
		f.open("Tasks.txt");
		if (f.is_open())
		{
			for (int i = 0; i < t.size(); i++)
			{
				f << t[i].getText() << '\n' << t[i].getTag() << '\n' << t[i].getDate() << '\n';
			}
		}
		f.close();
	}
	if (!pt.empty())
	{
		f.open("PriorTasks.txt");
		if (f.is_open())
		{
			for (int i = 0; i < pt.size(); i++)
			{
				f << pt[i].getText() << '\n' << pt[i].getTag() << '\n' << pt[i].getDate() << '\n';
			}
		}
		f.close();
	}
}

void System::Pmenu()
{
	int i;
	for (int i = 0; i < pt.size(); i++)
	{
		if (pt[i].getText() != "")
		{
			cout << i + 1 << ") " << pt[i].getText() << endl;
		}
	}
	cin >> i;
	cout << pt[i - 1].getText() << endl;
	cout << "Тег: " << pt[i - 1].getTag() << endl;
	cout << "Выполнить до: " << pt[i - 1].getDate() << endl;
	system("pause");
	system("cls");
}

void System::Tmenu()
{
	int i;
	for (int i = 0; i < t.size(); i++)
	{
		if (t[i].getText() != "")
		{
			cout << i + 1 << ") " << t[i].getText() << endl;
		}
	}
	cin >> i;
	cout << t[i - 1].getText() << endl;
	cout << t[i - 1].getTag() << endl;
	cout << "Выполнить до: " << t[i - 1].getDate() << endl;
	system("pause");
	system("cls");
}

void System::PRed()
{
	system("cls");
	int i, choice;
	for (int i = 0; i < pt.size(); i++)
	{
		if (pt[i].getText() != "")
		{
			cout << i + 1 << ") " << pt[i].getText() << endl;
		}
	}
	cin >> i;
	cout << pt[i - 1].getText() << endl;
	cout << pt[i - 1].getTag() << endl;
	cout << "Выполнить до: " << pt[i - 1].getDate() << endl;
	cout << "1) Изменить название" << endl;
	cout << "2) Изменить дату выполнения" << endl;
	cout << "3) Изменить тег" << endl;
	cout << "4) Изменить приориет" << endl;
	cin >> choice;
	if (choice == 1)
	{
		string temp;
		cin.ignore(123, '\n');
		cout << "Введите новый текст" << endl;
		getline(cin, temp);
		pt[i - 1].getText().clear();
		pt[i - 1].setText(temp);
	}
	else
	{
		if (choice == 2)
		{
			string temp;
			cin.ignore(123, '\n');
			cout << "Введите новую дату выполнения" << endl;
			getline(cin, temp);
			pt[i - 1].getDate().clear();
			pt[i - 1].setDate(temp);
		}
		else
		{
			if (choice == 3)
			{
				string temp;
				cin.ignore(123, '\n');
				cout << "Введите новый тег" << endl;
				getline(cin, temp);
				pt[i - 1].getTag().clear();
				pt[i - 1].setTag(temp);
			}
			else
			{
				if (choice == 4)
				{
					pt[i - 1].setPriority(false);
					t.push_back(pt[i - 1]);
					pt.erase(pt.begin() + (i - 1));
				}
			}
		}
	}
	system("cls");
}

void System::TRed()
{
	system("cls");
	int i, choice;
	for (int i = 0; i < t.size(); i++)
	{
		if (t[i].getText() != "")
		{
			cout << i + 1 << ") " << t[i].getText() << endl;
		}
	}
	cin >> i;
	cout << t[i - 1].getText() << endl;
	cout << t[i - 1].getTag() << endl;
	cout << "Выполнить до: " << t[i - 1].getDate() << endl;
	cout << "1) Изменить название" << endl;
	cout << "2) Изменить дату выполнения" << endl;
	cout << "3) Изменить тег" << endl;
	cout << "4) Изменить приориет" << endl;
	cin >> choice;
	if (choice == 1)
	{
		string temp;
		cin.ignore(123, '\n');
		cout << "Введите новый текст" << endl;
		getline(cin, temp);
		t[i - 1].getText().clear();
		t[i - 1].setText(temp);
	}
	else
	{
		if (choice == 2)
		{
			string temp;
			cin.ignore(123, '\n');
			cout << "Введите новую дату выполнения" << endl;
			getline(cin, temp);
			t[i - 1].getDate().clear();
			t[i - 1].setDate(temp);
		}
		else
		{
			if (choice == 3)
			{
				string temp;
				cin.ignore(123, '\n');
				cout << "Введите новый тег" << endl;
				getline(cin, temp);
				t[i - 1].getTag().clear();
				t[i - 1].setTag(temp);
			}
			else
			{
				if (choice == 4)
				{
					t[i - 1].setPriority(true);
					pt.push_back(t[i - 1]);
					t.erase(t.begin() + (i - 1));
				}
			}
		}
	}
	system("cls");
}

