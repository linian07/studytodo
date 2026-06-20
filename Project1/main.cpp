#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

struct Task {
    string title;
    bool done;
};

void saveTasks (const vector<Task>& tasks) {//实现保存数据功能
    ofstream file("tasks.txt");//创建并打开一个文件

    for (size_t i = 0;i < tasks.size();i++) {
        file << tasks[i].done << "|" << tasks[i].title << endl;//传入数据
    }
    file.close();//关闭文件
}

void loadTasks(vector<Task>& tasks) {//实现数据恢复
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

void printTask(const vector<Task>& tasks) {
    cout << "My Task List" << endl;
    if (tasks.empty()) {
        cout << "No tasks" << endl;
    }
    else {
        for (size_t i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". " ;
            if (tasks[i].done){
                cout << "[x] ";
            }
            else {
                cout<<"[ ] ";
            }
            cout << tasks[i].title << endl;
        }
    }
}

int main()
{
    vector<Task>tasks;
    loadTasks(tasks);

    int choice;

    while(true) {
        cout << "Study Todo" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. List tasks" << endl;
        cout << "3. Mark task as done" << endl;
        cout << "4. Delete task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> choice;
        cin.ignore();
        
        if (choice == 1) {
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
                saveTasks(tasks);

                cout << "Task added: " << newTask << endl;
                cout << "Total " << tasks.size() << " task(s) in the list" << endl;
            }
        }

        else if (choice == 2)
            printTask(tasks);

        else if (choice == 3) {
            int tasknum;
            cout << "Which task did you finish? Enter number: ";
            cin >> tasknum;
            cin.ignore();

            if (tasknum >= 1 && tasknum <= static_cast<int>(tasks.size())) {
                tasks[tasknum - 1].done = true;//标记任务完成
                saveTasks(tasks);
                cout << "Task marked as done." << endl;
            }
            else {
                cout << "Invalid task number." << endl;
            }
        }

        else if(choice==4) {
            int tasknum;
            cout << "Which task do you want to delete? Enter number: ";
            cin >> tasknum;
            cin.ignore();
            if (tasknum >= 1 && tasknum <= static_cast<int>(tasks.size())) {
                tasks.erase(tasks.begin() + tasknum - 1);//删除任务
                saveTasks(tasks);
                cout << "Task deleted." << endl;
            }
            else {
                cout << "Invalid task number." << endl;
            }
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