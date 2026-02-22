#include <iostream>
#include <string>

using namespace std;

int main() {

    string tasks[100];
    bool completed[100];
    int taskCount = 0;

    int choice;

    while (true) {

       
        cout << "        TO DO LIST      \n";
        cout << "========================\n";
        cout << "1. Add Task\n";
        cout << "2. Show Tasks\n";
        cout << "3. Mark Task Complete\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        if (choice == 5) {
            cout << "Exiting program...\n";
            break;
        }

        // ADD TASK
        if (choice == 1) {

            cin.ignore();   // clear newline only

            cout << "Enter task description: ";
            getline(cin, tasks[taskCount]);

            completed[taskCount] = false;
            taskCount++;

            cout << "Task added successfully.\n";
        }

        // SHOW TASKS
        else if (choice == 2) {

            if (taskCount == 0) {
                cout << "No tasks available.\n";
                continue;
            }

            for (int i = 0; i < taskCount; i++) {

                cout << i + 1 << ". ";

                if (completed[i])
                    cout << "[X] ";
                else
                    cout << "[ ] ";

                cout << tasks[i] << endl;
            }
        }

        // MARK COMPLETE
        else if (choice == 3) {

            int num;
            cout << "Enter task number: ";
            cin >> num;

            if (num >= 1 && num <= taskCount) {
                completed[num - 1] = true;
                cout << "Task marked complete.\n";
            } else {
                cout << "Invalid task number.\n";
            }
        }

        // DELETE TASK
        else if (choice == 4) {

            int num;
            cout << "Enter task number: ";
            cin >> num;

            if (num >= 1 && num <= taskCount) {

                int index = num - 1;

                for (int i = index; i < taskCount - 1; i++) {
                    tasks[i] = tasks[i + 1];
                    completed[i] = completed[i + 1];
                }

                taskCount--;
                cout << "Task deleted.\n";
            } else {
                cout << "Invalid task number.\n";
            }
        }

        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
