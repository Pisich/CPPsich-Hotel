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

  int setRoomFloor(size_t newVal){
    this->floor = newVal;
    return 0;
  }
  int setRoomSection(char newVal){
    this->section = newVal;
    return 0;
  }
  int setRoomState(RoomState newVal) noexcept {
    this->roomState = newVal;
    return 0;
  }
  int setCostPerNight(double newVal) noexcept {
    if (newVal < 0) return 1;
    this->costPerNight = newVal;
    return 0;
  }
  int setTotalOccupancy(size_t newVal) noexcept {
    this->totalOccupancy = newVal;
    return 0;
  }
  int setActualOccupancy(size_t newVal) noexcept {
    if (newVal < 0) return 1;
    if (newVal == 0) setRoomState(RoomState::Cleaning);

    this->actualOccupancy = newVal;
    return 0;
  }
};

int main()
{
  Room x{255, "Showcase room", 2, 'C', RoomState::Available, 45.5, 12, 6};
  std::cout << x.description;
  return 0;
}
