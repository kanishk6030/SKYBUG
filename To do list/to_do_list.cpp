#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Task {
private:
    string explanation;
    bool completed;

public:
    Task(const string& desc) : explanation(desc), completed(false) {}

    string getexplanation() const {
        return explanation;
    }

    bool isCompleted() const {
        return completed;
    }

    void ReportAsCompleted() {
        completed = true;
    }
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& explanation) {
        tasks.push_back(Task(explanation));
    }

    void PreviewTasks() const {
        cout << "Tasks:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            cout << (tasks[i].isCompleted() ? "[X] " : "[ ] ");
            cout << tasks[i].getexplanation() << endl;
        }
    }

    void ReportTaskAsCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index-1].ReportAsCompleted();
            cout << "Task marked as completed.\n";
        } else {
            cout << "Invalid task index.\n";
        }
    }

    void DeleteTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            cout << "Task Deleted.\n";
        } else {
        cout << "Invalid task index.\n";
        }
    }
};

int main() {
    TodoList to_do_List;
    char choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add your Task\n";
        cout << "2. Report Task as Completed\n";
        cout << "3. PreView Your Tasks\n";
        cout << "4. Delete Your Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                string taskexplanation;
                cout << "Enter task explanation: ";
                cin.ignore();
                getline(cin, taskexplanation);
                to_do_List.addTask(taskexplanation);
                break;
            }
            case '2': {
                size_t index;
                cout << "Enter the index of the task to mark as completed: ";
                cin >> index;
                to_do_List.ReportTaskAsCompleted(index);
                break;
            }
            case '3':
                to_do_List.PreviewTasks();
                break;
            
            case '4': {
                size_t index;
                cout << "Enter the index of the tasDelete: ";
                cin >> index;
                to_do_List.DeleteTask(index);
                break;
            }
            case '5':
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '5');

    return 0;
}
