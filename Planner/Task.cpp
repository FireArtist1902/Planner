#include "Task.h"
string Task::getTag() { return tag; }
bool Task::IsPriority(){ return priority; }
string Task::getDate(){	return date; }
string Task::getText() { return text; }
void Task::setText(string text) { this->text = text; }
void Task::setTag(string tag) { this->tag = tag; }
void Task::setPriority(bool priority) { this->priority = priority; }
void Task::setDate(string date) { this->date = date; }
Task::~Task()
{
	tag.clear();
	date.clear();
	text.clear();
}