#include<iostream>
#include<vector>

using namespace std;

class Student{
  public:

  int id;
  string name;
  float grade;

  Student(int i, string n, float g){
    id = i;
    name = n;
    grade = g;
  }
};

class StudentManagement{
  private:
  vector<Student>students;

  public:
  void addStudent(int id, string name, float grade){
    students.push_back(Student(id, name, grade));
    cout<<"Student added successfully\n!";
  }

  void displayStudents(){
    if(students.empty()){
      cout<<"No students available.\n";

      return;
    }

    cout<<"\nStudent List:\n";
    for(const auto& student:students){
      cout<<"ID:"<<student.id<<", Name:"<<student.name<<",Grade:"<<student.grade<<endl;
    }
  }

  void searchStudent(int id){
    for(const auto& student : students){
      if(student.id == id){
        cout<<"Student Found ID:" <<student.id<<", Name:"<<student.name<<",Grade:"<<student.grade<<endl;
        return;
      }
    }
    cout<<"Student not found!\n";
  }

  void updateStudent(int id, string newName, float newGrade){
    for (auto& student:students){
      if(student.id == id){
        student.name = newName;
        student.grade = newGrade;
        cout<<"Student details updated successfully!\n";

        return;
      }
    }
    cout<<"Student not found!\n";
  }

  void deleteStudent(int id){
    for(size_t i = 0; i<students.size(); i++){
      if(students[i].id == id){
        students.erase(students.begin() + 1);
        cout<<"Student deleted successfully!\n";
        return;
      }
    }
    cout<<"Student not found!\n";
  }
  };

  int main(){
    StudentManagement sm;
    int choice;

    while(true){
      cout<<"\nStudent Management System\n";
      cout<<"1. Add Student\n2. View Students\n3. Search Student\n4. Update Student\n5. Delete Student\n6. Exit\n";      cin>>choice;

      if(choice == 1){
        int id;
        string name;
        float grade;
        cout<<"Enter Student ID:";
        cin>>id;
        cout<<"Enter Name:";
        cin.ignore();
        getline(cin, name);
        cout<<"Enter Grade:";
        cin>>grade;
        sm.displayStudents();
      }
      else if(choice == 2){
        sm.displayStudents();
      }
      else if(choice == 3){
        int id;
        cout<<"Enter Student ID to search";
        cin>>id;
        sm.searchStudent(id);        
      }
      else if(choice == 4){
        int id;
        string newName;
        float newGrade;
        cout<<"Enter Student ID to update:";
        cin>>id;
        cout<<"Enter new Name:";
        cin.ignore();
        getline(cin, newName);
        cout<<"Enter new Grade:";
        cin>>newGrade;
        sm.deleteStudent(id);
      }
      else if(choice == 5){
        int id;
        cout <<"Enter Student ID to delete:";
        cin>>id;
        sm.deleteStudent(id);
      }
      else if(choice == 6){
        cout << "Existing program...\n";
        break;
      }
      else{
        cout<<"Invalid choice, try again.\n";
      }
    }
    return 0;
  }