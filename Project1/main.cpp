#include<iostream>
#include<vector>

#include "TaskManager.h"
#include "Menu.h"
using namespace std;

int main()
{
    TaskManager manager;
    manager.loadTasks();

    int choice;

    while(true) {
        choice = getMenuChoice();
        
        if (choice == 1) {
            manager.addTask();
        }

        else if (choice == 2)
            manager.printTask();

        else if (choice == 3) {
            manager.markTaskDone();
        }

        else if(choice==4) {
            manager.deleteTask();
        }

        else if (choice == 5) {
            manager.saveTasks();
            cout << "Tasks saved. Goodbye!" << endl;
            break;
        }

        else{
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}