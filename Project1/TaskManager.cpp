#include "TaskManager.h"

#include <iostream>
#include <fstream>
#include <limits>
#include <string>
using namespace std;

void  TaskManager :: saveTasks() const {//实现保存数据功能
    ofstream file("tasks.txt");//创建并打开一个文件

    for (size_t i = 0;i < tasks.size();i++) {
        file << tasks[i].done << "|" << tasks[i].title << endl;//传入数据
    }
    file.close();//关闭文件
}

void  TaskManager ::loadTasks() {//实现数据恢复
    ifstream file("tasks.txt");

    if (!file)//检查文件是否打开或者存在
        return;

    string line;

    while (getline(file, line)) {//逐行读取文件内容
        size_t separator = line.find('|');//找到分隔符的位置

        if (separator == string::npos)//没有找到就跳过
            continue;

        Task task;
        task.done = (line.substr(0, separator) == "1");
        task.title = line.substr(separator + 1);

        tasks.push_back(task);//实现恢复数据
    }

    file.close();
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
            cout << tasks[i].title << endl;
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

        Task task;
        task.title = newTask;
        task.done = false;

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