#include<iostream>
using namespace std;

int main(){
  double num1, num2;
  char operation;

  cout << "Simple Calculator" << endl;
  cout << "Enter first number:";
  cin >> num1;
  cout << "Enter an operator (+,-,*,/):";
  cin >> operation;
  cout << "Enter second number:";
  cin >> num2;

  switch(operation){
    case '+':
    cout << "Result: " << num1 + num2 << endl;
    break;

    case '-':
    cout << "Result: " << num1 - num2 << endl;
    break;

    case '*':
    cout << " Result: " << num1 * num2 << endl;
    break;

    case '/':
    if(num2 !=0)
    cout << " Result: " << num1 / num2 << endl;

    else

    cout << "Error! Division by Zero is not allowed." << endl;
    break;

    default:
    cout << "Invalid operator! Please use +,-,*, or /."<< endl;

  }

  return 0;
}