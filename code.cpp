#include <iostream>
#include <vector>
#include <string>

using namespace std;

void displayMenu() {
    cout << "\nTo-Do List Application" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Delete Task" << endl;
    cout << "4. Exit" << endl;
    cout << "Choose an option: ";
}

int main() {
    vector<string> tasks;
    int choice;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Ignore newline character

        switch (choice) {
            case 1: {
                string task;
                cout << "Enter task: ";
                getline(cin, task);
                tasks.push_back(task);
                cout << "Task added successfully!" << endl;
                break;
            }
            case 2:
                if (tasks.empty()) {
                    cout << "No tasks available." << endl;
                } else {
                    cout << "\nYour Tasks:" << endl;
                    for (size_t i = 0; i < tasks.size(); i++) {
                        cout << i + 1 << ". " << tasks[i] << endl;
                    }
                }
                break;
            case 3: {
                if (tasks.empty()) {
                    cout << "No tasks to delete." << endl;
                } else {
                    int index;
                    cout << "Enter task number to delete: ";
                    cin >> index;
                    if (index > 0 && index <= tasks.size()) {
                        tasks.erase(tasks.begin() + index - 1);
                        cout << "Task deleted successfully!" << endl;
                    } else {
                        cout << "Invalid task number!" << endl;
                    }
                }
                break;
            }
            case 4:
                cout << "Exiting application..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
