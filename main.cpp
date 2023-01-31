#include <iostream>
#include <string>

using namespace std;

enum RoomState
{
  Available,
  Cleaning,
  Remodeling,
  Occupied,
  OutOfService
};

class Room
{
protected:
  size_t floor;
  char section;
  RoomState roomState;
  double costPerNight;
  size_t totalOccupancy;
  size_t actualOccupancy;

public:
  const size_t roomNumber;
  string description;

  Room(size_t roomNumber, string description, size_t floor, char section,
       RoomState roomState, double costPerNight, size_t totalOccupancy, size_t actualOccupancy) :
          roomNumber(roomNumber), description(description), floor(floor), section(section),
          roomState(roomState), costPerNight(costPerNight), totalOccupancy(totalOccupancy),
          actualOccupancy(actualOccupancy) {}
  
  size_t getRoomFloor(){
    return floor;
  }
  char getRoomSection(){
    return section;
  }
  RoomState getRoomState(){
    return roomState;
  }
  double getCostPerNight(){
    return costPerNight;
  }
  size_t getTotalOccupancy(){
    return totalOccupancy;
  }
  size_t getActualOccupancy(){
    return actualOccupancy;
  }
};

int main()
{
  Room x{255, "Showcase room", 2, 'C', RoomState::Available, 45.5, 12, 6};
  std::cout << "Hello World!";
  return 0;
}
