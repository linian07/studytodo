#include <iostream>
#include<limits>

#include "Menu.h"

using namespace std;


void showMenu() {
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. View Tasks By Priority" << endl;
    cout << "4. Mark Task as Done" << endl;
    cout << "5. Delete Task" << endl;
    cout << "6. Save and Exit" << endl;
    cout << "Enter your choice: ";
}

int getMenuChoice() {
    int choice;

    while (true) {//只有输入数字才会结束
        showMenu();

        if (cin >> choice) {//判断输入是否为数字
            cin.ignore(numeric_limits<streamsize>::max(), '\n');//丢弃输入缓冲区中的剩余输入
            return choice;//结束
        }

        cout << "Invalid input. Please enter a number." << endl;

        cin.clear();//清除cin的错误状态
        cin.ignore(numeric_limits<streamsize>::max(), '\n');//丢弃输入缓冲区中的无效输入
    }
}
