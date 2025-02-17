#include<iostream>
#include<vector>

using namespace std;

class Contact{
  public :
    string name;
    string phone;
    string email;

    Contact(string n, string p, string e){
      name = n;
      phone = p;
      email = e;
    }
};

  class ContactManager{
      private:
      vector<Contact>contacts;

      public:

      void addContact(string name, string phone, string email){
          contacts.push_back(Contact(name, phone, email));
          cout << "Contact ad successfully!"<<endl;
        }

        void viewContacts(){
          if(contacts.empty()){
            cout<<"No contacts available!"<<endl;
            return;
          }

          cout<< "\nContacts List:"<<endl;
          for(size_t i = 0; i<contacts.size(); i++){
            cout<<i+1<< ".Name:"<<contacts[i].name 
            <<",Phone:" << contacts[i].phone
            <<",Email:" << contacts[i].email<<endl;
          }
        }

        void  searchContact(string searchName){
          bool found = false;
          for (size_t i =0; i<contacts.size(); i++){
            if(contacts[i].name == searchName){
              cout<<"Contact Found:\n";
              cout<<",Phone:"<<contacts[i].phone
              <<",Email:"<<contacts[i].email<<endl;
              found=true;
              break;
            }
          }if(!found){
            cout<<"Contacts not fund!"<<endl;
          }
        }

        void deleteContact(int index){
          if(index > 0 && index<=contacts.size()){
            contacts.erase(contacts.begin()+index-1);
            cout<<"COntact deleted successfully!"<<endl;
          }else{
            cout<<"Invalid contact number!"<<endl;
          }
        }
};

int main(){
  ContactManager manager;
  int choice;
  string name, phone, email;
  int index;

  do {
    cout<<"\n1. Add Contact\n2. View Contacts\n3. Search Contact\n4. Delete Contact\n5. Exit\n";
    cout<<"Choose an option:";
    cin>>choice;

    cin.ignore();

    switch(choice){
      case 1:
      cout<<"Enter Name:";
      getline(cin, name);
      cout<<"Enter Phone:";
      getline(cin, phone);
      cout<<"Enter Email:";
      getline(cin, email);
      manager.addContact(name, phone, email);
      break;

      case 2:
      manager.viewContacts();
      break;

      case 3:
      cout<<"Enter name to search:";
      getline(cin, name);
      manager.searchContact(name);
      break;

      case 4:
      cout<<"Enter contact number to delete:";
      cin>>index;
      manager.deleteContact(index);
      break;

      case 5:
      cout<<"Exiting Contact Manager. Have a great day!"<<endl;
      break;

      default:
      cout<<"Invalid choice! please try again."<<endl;
    }
  }while(choice !=5);

  return 0;
}
