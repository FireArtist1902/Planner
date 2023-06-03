#pragma once
#include "Task.h"
#include <vector>
class System
{
	vector<Task> t; //������� �������
	vector<Task> pt;//������ �������
public:
	void createTask(string text, string tag, bool priority, string date);
	void loadTask();
	void menu();
	void createMenu();
	void showMenu();
	void redMenu();
protected:
	void saveTask();
	void Pmenu();
	void Tmenu();
	void PRed();
	void TRed();
};