#include<iostream>
using namespace std;

char calculateGrade(float avg){
  if(avg>=70)
  return 'A';
  else if(avg>=60)
  return 'B';
  else if(avg>=50)
  return 'C';
  else if(avg>=40)
  return 'D';
  else
  return 'F';
}

int main(){
  int numSubjects;
  cout<<"Enter the number of subjects:";
  cin>>numSubjects;
  float marks[numSubjects], total = 0;

  for(int i = 0; i<numSubjects;i++){
    cout<<"Enter marks for subject" <<i+1<<":";
    cin>>marks[i];
    total += marks[i];
  }

  float avg =  total / numSubjects;
  char grade = calculateGrade(avg);

  cout<<"\nTotal Marks:"<<total<<endl;
  cout<<"Average Marks:"<<total<<avg<<endl;
  cout<<"Grade:"<<grade<<endl;

  return 0;
}