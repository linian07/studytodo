#pragma once

#include<vector>
#include"Task.h"
using namespace std;

void saveTasks(const vector<Task>& tasks);
void loadTasks(vector<Task>& tasks);
void printTask(const vector<Task>& tasks);
void showMenu();
int getMenuChoice();
void addTask(vector<Task>& tasks);
void markTaskDone(vector<Task>& tasks);
void deleteTask(vector<Task>& tasks);