#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Task {
    string description;
    bool completed;
};

// Function prototypes
void displayMenu();
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void markCompleted(vector<Task>& tasks);
void removeTask(vector<Task>& tasks);

int main() {
    vector<Task> tasks;
    int ch;

    cout << "\t\t\t\t=======================================================" << endl;
    cout << "\t\t\t\t*\t\t\t\t\t\t      *" << endl;
    cout << "\t\t\t	*\t\tWelcome to To-Do List Manager\t      *" << endl;
    cout << "\t\t\t\t*\t\t\t\t\t\t      *" << endl;
    cout << "\t\t\t\t=======================================================" << endl<<endl;
    do {
        displayMenu();
        cin >> ch;

        switch (ch) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                 markCompleted(tasks);
                break;
            case 3:
            	viewTasks(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "\n\t\t\t\t=======================================================" << endl;
                cout << "\t\t\t\t| \t\t\t\t\t\t      |" << endl;
                cout << "\t\t\t\t|    Thank you for using the To-Do List Manager!      |" << endl;
                cout << "\t\t\t\t| \t\t\t\t\t\t      |" << endl;
                cout << "\t\t\t\t=======================================================" << endl;
                break;
            default:
            	cout << "\n\t\t\t\t=======================================================" << endl;
                cout << "\t\t\t\t	 Invalid choice. Please try again." << endl;
                cout << "\t\t\t\t=======================================================" << endl<<endl;

                break;
        }

    } while (ch != 5);

    return 0;
}

void displayMenu() {
	 // Display menu options
    cout << "\t\t\t\t=======================================================" << endl;
    cout << "\t\t\t\t \t\t\t MENU" << endl;
    cout << "\t\t\t\t   1. Add Task " << endl;
    cout << "\t\t\t\t   2. Mark Task as Completed "<< endl;
    cout << "\t\t\t\t   3. View Tasks " << endl;
    cout << "\t\t\t\t   4. Remove Task " << endl;
    cout << "\t\t\t\t   5. Logout " << endl;
    cout << "\t\t\t\t=======================================================" << endl<<endl;
    cout << "\t\t\t\tEnter your choice: ";
}

void addTask(vector<Task>& tasks) {
    Task newTask;
    cout << "\n\t\t\t\tEnter task description: ";
    cin.ignore();
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "\n\t\t\t\t\tTASK ADDED SUCCESSFULLY!" << endl<<endl;
}

void viewTasks(const vector<Task>& tasks) {
	// Display the to-do list
    cout << "\n\t\t\t\t=======================================================" <<endl;
    cout << "\n\t\t\t\t\t\t\tTo-Do List:"<<endl<<endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << "\t\t\t\t" << (i + 1) << "  . ";
        if (tasks[i].completed)
            cout << " [ X ] ";
        else
            cout << " [  ] ";
        cout << tasks[i].description;
        cout << string(50 - tasks[i].description.length(), ' ') << " " << endl;
    }
     cout << endl;
    cout << "\t\t\t\t=======================================================" << endl<<endl;
}

void markCompleted(vector<Task>& tasks) {
    viewTasks(tasks);
    int index;
    cout << "\t\t\t\tEnter the number of the task to mark as completed: ";
    cin >> index;

    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        tasks[index - 1].completed = true;
          // Task marked as completed confirmation
    cout << "\n\t\t\t\t\t\tTask marked as completed!" << endl<<endl;

    } else {
    	cout << "\n\t\t\t\t=======================================================" << endl;
        cout << "\t\t\t\t\t   Invalid task number. Please try again" << endl;
        cout << "\t\t\t\t=======================================================" << endl<<endl;

    }
}

void removeTask(vector<Task>& tasks) {
    viewTasks(tasks);
    int index;
    cout << "\t\t\t\tEnter the number of the task to remove:  ";
    cin >> index;

    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + index - 1);
         // Task removed confirmation
         cout << "\n\t\t\t\t=======================================================" << endl;
         cout << "\t\t\t\t| \t\t\t\t\t\t      |" << endl;
         cout << "\t\t\t\t|\t  TASK REMOVED SUCCESSFULLY!\t\t      | " <<endl;
         cout << "\t\t\t\t| \t\t\t\t\t\t      |" << endl;
         cout << "\t\t\t\t=======================================================" << endl<<endl;
    } 
	else {
    	cout << "\n\t\t\t\t=======================================================" << endl;
        cout << "\t\t\t\t\t   Invalid task number. Please try again" << endl;
        cout << "\t\t\t\t=======================================================" << endl<<endl;
    }
}
//Created by Noor Fatima
//For Internship Task To-do list
//For @softcode      
