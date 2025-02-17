#include <iostream> 
#include <vector> 

using namespace std; 

      class Task { 
          public: 
      string description; 
      bool completed; 
      Task(string desc) { 
      description = desc; 
      completed = false; 
    } 
}; 
 


  class ToDoList { 
    private: 
        vector<Task> tasks; 
 
    public: 
    // Add a new task 
      void addTask(string desc) { 
       tasks.push_back(Task(desc)); 
        cout << "Your Task has been added successfully!" << endl; 
    } 
 
    // View all tasks 
    void viewTasks() { 
        if (tasks.empty()) { 
            cout << "Your haven't added any tasks so far"<< endl <<"No tasks available!" << endl; 
            return; 
        } 
 
        cout << "\nTo-Do List:" << endl; 
        for (size_t i = 0; i < tasks.size(); i++) { 
            cout << i + 1 << ". " << (tasks[i].completed ? "[✓] " : "[ ] ") << tasks[i].description << endl; 
        } 
    } 
 
    // Mark a task as completed 
    void completeTask(int index) { 
        if (index > 0 && index <= tasks.size()) { 
            tasks[index - 1].completed = true; 
            cout << "Task marked as completed!" << endl; 
        } else { 
            cout << "Invalid task number!" << endl; 
        } 
    } 
 
    // Delete a task 
    void deleteTask(int index) { 
        if (index > 0 && index <= tasks.size()) { 
            tasks.erase(tasks.begin() + index - 1); 
            cout << "Task deleted successfully!" << endl; 
        } else { 
            cout << "Invalid task number!" << endl; 
        } 
    } 
}; 
 
int main() { 
    ToDoList todo; 
    int choice; 
    string description; 
    int taskNumber; 
 
    do { 
        cout << "\n1. Add Task\n2. View Tasks\n3. Complete Task\n4. Delete Task\n5. Exit\n"; 
        cout << "Choose an option: "; 
        cin >> choice; 
        cin.ignore(); 
 
        switch (choice) { 
            case 1: 
                cout << "Enter task description: "; 
                getline(cin, description); 
                todo.addTask(description); 
                break; 

            case 2: 
                todo.viewTasks(); 
                break; 

            case 3: 
                cout << "Enter task number to complete: "; 
                cin >> taskNumber; 
                todo.completeTask(taskNumber); 
                break; 

            case 4: 
                cout << "Enter task number to delete: "; 
                cin >> taskNumber; 
                todo.deleteTask(taskNumber); 
                break; 

            case 5: 
                cout << "Exiting To-Do List. Have a productive day!" << endl; 
                break; 

            default: 

          cout << "Invalid choice! Please try again." << endl; 
          
  } 

  } 
  
    while (choice != 5); 

      return 0; 
  } 