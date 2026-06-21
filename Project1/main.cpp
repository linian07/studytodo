#include<iostream>
#include<vector>

#include "TaskManager.h"
using namespace std;

int main()
{
    vector<Task>tasks;
    loadTasks(tasks);

    int choice;

    while(true) {
        choice = getMenuChoice();
        
        if (choice == 1) {
            addTask(tasks);
        }

        else if (choice == 2)
            printTask(tasks);

        else if (choice == 3) {
            markTaskDone(tasks);
        }

        else if(choice==4) {
            deleteTask(tasks);
        }

        else if (choice == 5) {
            saveTasks(tasks);
            cout << "Tasks saved. Goodbye!" << endl;
            break;
        }

        else{
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}