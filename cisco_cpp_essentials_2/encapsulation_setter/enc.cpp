/* Restricting access to object data
 - Hide the area and side members using the keyword private;
 - add a public method set_side to the Square class that will update both fields;
 - set_side should also ignore the change if the argument is less than 0;
 - change the print function implementation into a public method of Square.

*/
    
#include <iostream>
#include <string>

using namespace std;

class Square
{
public:
  Square(double side);
  
  // Your code here
  void set_side(double new_side);
  double get_area() { return area; }
  double get_side() { return side; }

private:
  double    side;
  double    area;
};

// Class::method(arguments) {}
void Square::set_side(double new_side) {
  if (new_side >= 0) {
    side = new_side;
    area = side * side;
  }
}

// Define the class properties
Square::Square(double side)
{
  this->side = side;
  this->area = side * side;
}

void print(Square* square)
{
  cout << "Square: side=" << square->get_side() << " area=" << square->get_area() << endl;
}


int main()
{
  Square s(4);


  print(&s);

  s.set_side(2.0);
  print(&s);

  s.set_side(-33.0);
  print(&s);

  return 0;
}