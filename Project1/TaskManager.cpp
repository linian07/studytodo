#include "TaskManager.h"

#include <iostream>
#include <fstream>
#include <limits>
#include <string>
using namespace std;

void  TaskManager :: saveTasks() const {//实现保存数据功能
    ofstream file("tasks.txt");//创建并打开一个文件

    for (size_t i = 0;i < tasks.size();i++) {
        file << tasks[i].done << "|" <<tasks[i].priority<<"|" << tasks[i].title << endl;//传入数据
    }
    file.close();//关闭文件
}

void  TaskManager ::loadTasks() {//实现数据恢复
    ifstream file("tasks.txt");

    if (!file)//检查文件是否打开或者存在
        return;

    string line;

    while (getline(file, line)) {//逐行读取文件内容
        size_t firstseparator = line.find('|');//找到分隔符的位置

        if (firstseparator == string::npos)//没有找到就跳过
            continue;

        size_t secondseparator = line.find('|', firstseparator + 1);

        Task task;
        if (secondseparator == string::npos){
            task.done = (line.substr(0,firstseparator) == "1");
            task.priority = 2;
            task.title = line.substr(secondseparator + 1);
        }
        else {
            task.done = (line.substr(0, firstseparator) == "1");
            task.priority = stoi(line.substr(firstseparator + 1, secondseparator - firstseparator - 1));
            task.title = line.substr(secondseparator + 1);
        }
        tasks.push_back(task);//实现恢复数据
    }

    file.close();
}


string priorityToText(int priority) {
    if (priority == 1) {
        return "Low";
    }
    else if (priority == 2) {
        return "Medium";
    }
    else if (priority == 3) {
        return "High";
    }
    else {
        return "Unknown";
    }
}


void TaskManager :: printTask() const {
    cout << "My Task List" << endl;

    if (tasks.empty()) {
        cout << "No tasks" << endl;
    }
    else {
        for (size_t i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". ";

            if (tasks[i].done) {
                cout << "[x] ";
            }
            else {
                cout << "[ ] ";
            }
            cout << "[" << priorityToText(tasks[i].priority) << "]";
            cout<<tasks[i].title << endl;
        }
    }
}

void  TaskManager :: addTask() {
    string newTask;
    cout << "Please enter a task (enter 'quit' to exit):" << endl;

    while (true) {
        cout << ">";
        getline(cin, newTask);

        if (newTask == "quit")
            break;
        if (newTask.empty()) {
            cout << "Task cannot be empty, please re-enter" << endl;
            continue;
        }

        int priority;

        cout<<"Enter priority (1: Low, 2: Medium, 3: High): ";
        cin>> priority;
        cin.ignore();
        if (priority < 1 || priority>3) {
            cout << "Invalid priority. Set to Medium by default" << endl;
            priority = 2;
        }

        Task task;
        task.title = newTask;
        task.done = false;
        task.priority = priority;

        tasks.push_back(task);//添加任务
        saveTasks ();

        cout << "Task added: " << newTask << endl;
        cout << "Total " << tasks.size() << " task(s) in the list" << endl;
    }
}

void  TaskManager :: markTaskDone() {
    int taskNumber;

    printTask();

    if (tasks.empty())
        return;

    cout << "Enter the task number to mark as done: ";
    cin >> taskNumber;
    cin.ignore();

    if (taskNumber > 0 && taskNumber <= static_cast<int> (tasks.size())) {
        tasks[taskNumber - 1].done = true;
        saveTasks();
        cout << "Task marked as done." << endl;
    }
    else {
        cout << "Invalid task number." << endl;
    }
}

void  TaskManager:: deleteTask() {
    printTask();

    if (tasks.empty())
        return;

    int tasknum;
    cout << "Which task do you want to delete? Enter number: ";
    cin >> tasknum;
    cin.ignore();

    if (tasknum >= 1 && tasknum <= static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + tasknum - 1);//删除任务
        saveTasks();
        cout << "Task deleted." << endl;
    }
    else {
        cout << "Invalid task number." << endl;
    }
}