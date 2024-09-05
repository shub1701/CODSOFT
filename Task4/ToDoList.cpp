#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
public:
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& taskDescription) {
        tasks.push_back(Task(taskDescription));
        cout << "Task added: " << taskDescription << endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks available." << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". [" << (tasks[i].completed ? "X" : " ") << "] " << tasks[i].description << endl;
        }
    }

    void markTaskCompleted(int index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            cout << "Task marked as completed: " << tasks[index - 1].description << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    void removeTask(int index) {
        if (index >= 1 && index <= tasks.size()) {
            cout << "Removing task: " << tasks[index - 1].description << endl;
            tasks.erase(tasks.begin() + (index - 1));
        } else {
            cout << "Invalid task number." << endl;
        }
    }
};

int main() {
    ToDoList todoList;
    int choice;

    do {
        cout << "\nTo-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To ignore the newline character after the choice input

        switch (choice) {
            case 1: {
                string taskDescription;
                cout << "Enter task description: ";
                getline(cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            }
            case 2:
                todoList.viewTasks();
                break;
            case 3: {
                int taskNumber;
                cout << "Enter task number to mark as completed: ";
                cin >> taskNumber;
                todoList.markTaskCompleted(taskNumber);
                break;
            }
            case 4: {
                int taskNumber;
                cout << "Enter task number to remove: ";
                cin >> taskNumber;
                todoList.removeTask(taskNumber);
                break;
            }
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
