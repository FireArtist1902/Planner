#pragma once
#include <iostream>
using namespace std;
class Task
{
	string text;
	string tag;
	bool priority = false;
	string date;
public:
	string getText();
	string getTag();
	bool IsPriority();
	string getDate();
	void setText(string text);
	void setTag(string tag);
	void setPriority(bool priority);
	void setDate(string date);
	~Task();
	Task(string text, string tag, bool priority, string date) : text(text), tag(tag), priority(priority), date(date) {}
	Task() {}
};

