/*Flight booking system: part 1

Let's pretend we're working on an airline flight booking system.

Our systems save an identification number, the capacity and the number of seats reserved for all flight bookings.

Our first job will be to print out a status report about the percentage of capacity filled.

The report should be in the form: "Flight [id] : [reserved]/[capacity] ([percentage]%) seats taken"
*/

#include <iostream>

class FlightBooking {
public:
  FlightBooking(int id, int capacity, int reserved);
  void printStatus();
private:
  int id;
  int capacity;
  int reserved;
};

void FlightBooking::printStatus()
{
  // print report here
  std::cout << "Flight " << id << " : " << reserved << "/" 
    << capacity << " (" << ((100 * reserved) / capacity) <<  "%) seats reserved" << std::endl;
}

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
  // Save data to members
  this->id = id;
  this->capacity = (capacity > 0) ? capacity : 0;
  this->reserved = (reserved > 0) ? reserved : 0;
}

int main() {
  int reserved = 0,
      capacity = 0;
  std::cout << "Provide flight capacity: ";
  std::cin >> capacity;

  std::cout << "Provide number of reserved seats: ";
  std::cin >> reserved;

  FlightBooking booking(1, capacity, reserved);

  booking.printStatus();

  return 0;
}