#include <iostream>
using namespace std;
//TaskNode can add a Node in LinkedList
struct TaskNode {
public:
    int task_id;
    string Description;
    int priority;
    TaskNode* next;

    TaskNode(int id, string& desc, int prio){
    	task_id=id;
		 Description=desc; 
		 priority=prio;
		  next=NULL;
    } 
};
//manage the task
struct TaskList {
private:
    TaskNode* first;

public:
    TaskList(){
    first=NULL;
	} 
	
	// Add new Task(Node) 
	
    void add_task(int task_id, string& Description, int priority) {
        TaskNode* new_task = new TaskNode(task_id, Description, priority);
        if (first == NULL || first->priority < priority) {
            new_task->next = first;
            first = new_task;
        } else {
            TaskNode* current = first;
            while (current->next!=NULL && current->next->priority >= priority) {
                current = current->next;
            }
            new_task->next = current->next;
            current->next = new_task;
        }
        cout << "Task added." << endl;
    }
	//Remove the Highest periority task from the LinkedList

    void remove_highest_priority_task() {
        if (first == NULL) {
            cout << "No tasks to remove." << endl;
            return;
        }
        TaskNode* removed_task = first;
        first = first->next;
        cout << "Removed task with ID: " << removed_task->task_id
                  << ", Description: " << removed_task->Description << endl;
        delete removed_task;
    }
		//Remove task by ID
    void remove_task_by_id(int task_id) {
        if (first == NULL) {
            cout << "No tasks to remove." << endl;
            return;
        }

        if (first->task_id == task_id) {
            TaskNode* removed_task = first;
            first = first->next;
            cout << "Removed task with ID: " << task_id << endl;
            delete removed_task;
            return;
        }

        TaskNode* current = first;
        while (current->next!=NULL && current->next->task_id != task_id) {
            current = current->next;
        }

        if (current->next == NULL) {
            cout << "Task with ID: " << task_id << " not found." << endl;
        } else {
            TaskNode* removed_task = current->next;
            current->next = current->next->next;
            cout << "Removed task with ID: " << task_id << endl;
            delete removed_task;
        }
    }
    //for veiwing All Task

    void view_tasks()  {
        if (first == NULL) {
            cout << "No tasks available." << endl;
            return;
        }
        TaskNode* current = first;
        cout << "Tasks:" << endl;
        while (current) {
            cout << "ID: " << current->task_id 
                      << ", Description: " << current->Description 
                      << ", Priority: " << current->priority << endl;
            current = current->next;
        }
    }
	//destructor to free up the  memory space
    ~TaskList() {
        while (first) {
            TaskNode* temp = first;
            first = first->next;
            delete temp;
        }
    }
};

int main() {
    TaskList task_list;

    while (true) {
        cout << "\nTask Management System" << endl;
        cout << "1. Add a new task" << endl;
        cout << "2. View all tasks" << endl;
        cout << "3. Remove the highest priority task from the list" << endl;
       	cout << "4. Remove a task by ID" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int task_id;
            string Description;
            int priority;

            cout << "Enter task ID: ";
            cin >> task_id;
            cout << "Enter task Description: ";
          	cin.ignore(); // Clear input buffer
            getline(cin, Description);
            cout << "Enter task priority: ";
            cin >> priority;

            task_list.add_task(task_id, Description, priority);
        } else if (choice == 2) {
            task_list.view_tasks();
        } else if (choice == 3) {
            task_list.remove_highest_priority_task();
        } else if (choice == 4) {
            int task_id;
            cout << "Enter task ID to remove From the List: ";
            cin >> task_id;
            task_list.remove_task_by_id(task_id);
        }else {
           cout << "Invalid choice. Try again." <<  endl;
        }
    }

    return 0;
}

