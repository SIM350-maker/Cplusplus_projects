#include<iostream>

using namespace std;

class BankAccount{
  private:
  string accountHolder;
  double balance;

  public:

  BankAccount(string name, double initialBalance){
    accountHolder = name;
    balance = initialBalance;
  }

  void deposit(double amount){
    if(amount>0){
      balance += amount;
      cout << "Deposit successful! New balance:" << balance<<"ksh"<< endl;
    }else{
      cout<<"Invalid deposit amount!" <<endl;
    }
  }

  void withdraw(double amount){
    if(amount>0 && amount <= balance){
      balance -= amount;
      cout<<"Withdrawal successful! New balance: &" << balance <<endl;
    }else{
      cout<<"invalid withdraw amount or insufficient balance!" << endl;
    }
  }

  void displayBalance(){
    cout<<"Account Holder:"<<accountHolder<<endl;
    cout<<"Current Balance: $"<<balance<<endl;
  }
};

int main(){
string name;
double initialDeposit;
cout<<"Welcome to the bank Account Management System System!"<<endl;
cout<<"Enter your name:";
getline(cin, name);
cout<<"Enter initial deposit amount:";
cin>>initialDeposit;

BankAccount account(name, initialDeposit);

int choice;
double amount;

do{

cout<<"\n1. Deposit Money\n2. Withdraw Money\n3. Display Balance\n4. Exit\n";
cout<<"Choose an option:";
cin>>choice;

switch(choice){
  case 1:
  cout<<"Enter deposit amount:";
  cin>>amount;
  account.deposit(amount);
  break;

  case 2:
  cout<<"Enter withdrawal amount:";
  cin>>amount;
  account.withdraw(amount);
  break;

  case 3:
  account.displayBalance();
  break;

  case 4:
  cout<<"Thank you " <<name << " Using our bank system!"<<endl;
  break;

  default:
  cout<<"Invalid choice! Please try again."<<endl;
}
}while(choice !=4);
return  0;

}
