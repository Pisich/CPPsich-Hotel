#include <iostream>
#include <string>

enum class RoomState{
  Available,
  Cleaning,
  Remodeling,
  Occupied,
  OutOfService
}

class Room{
  protected:
    size_t floor;
    char roomSection;
    RoomState roomState;
    double costPerNight;
    size_t totalOccupancy;
    size_t actualOccupancy;
  
  public:
    size_t roomNumber;
    string roomDescription;

}

int main() {
  std::cout << "Hello World!";
  return 0;
}
