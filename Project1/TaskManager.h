#pragma once

#include<vector>
#include"Task.h"
using namespace std;

class TaskManager {
private:
	vector<Task> tasks;
public:
	void loadTasks();
	void saveTasks() const;
	void printTask() const;
	void addTask();
	void markTaskDone();
	void deleteTask();
};

void showMenu();
int getMenuChoice();