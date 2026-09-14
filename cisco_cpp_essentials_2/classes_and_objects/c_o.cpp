/* Classes and Objects in C++
Add more members to the class 'Person' e os acesse.
*/
#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
  string name;
  int    age;
  // Your code here
  string occupation;
};

void print(Person* person)
{
  cout << person->name << " is " << person->age << " years old and works as " << person->occupation << endl;
}


int main()
{
  Person person;
  person.name = "Harry";
  person.age  = 23;  

  // Your code here
  person.occupation = "teacher";
  
  Person person2;
  person2.name = "Anna";
  person2.age  = 29;
  person2.occupation = "nutricionist";

  cout << "Meet " << person2.name << endl;
  print(&person2);
  cout << "Meet " << person.name << endl;
  print(&person);
  
  return 0;
}