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

class Person
{
protected:
  string lastName;

  void initRandomPerson(){
    this->age = rand() % 100;
  }

public:
  string firstName;
  size_t age{0};

  Person() { initRandomPerson(); }
  Person(string firstName, string lastName, size_t age) : firstName(std::move(firstName)),
    lastName(std::move(lastName)), age(age) {}
};

class Employee : Person
{
protected:
  size_t workingFloor;
  double salaryPerDay{0};

  void initRandomEmployee(){
    this->workingFloor = rand() % 50;
    this->salaryPerDay = rand() % 500;
  }

public:
  Employee() { initRandomEmployee(); }
  Employee(string firstName, string lastName, size_t age) : Person(firstName, lastName, age) {}
  Employee(string firstName, string lastName, size_t age, size_t workingFloor, double salaryPerDay) : 
    Person(firstName, lastName, age), workingFloor(workingFloor), salaryPerDay(salaryPerDay) {}
};

class Guest : Person
{
public:
  Guest(): Person() {}
  Guest(string firstName, string lastName, size_t age) : Person(firstName, lastName, age) {}
};

class Room
{
protected:
  size_t floor;
  char section;
  RoomState roomState;
  double costPerNight{0};
  size_t totalOccupancy{0};
  size_t actualOccupancy{0};

public:
  const size_t roomNumber;
  string description;

  Room(size_t roomNumber, string description, size_t floor, char section,
    RoomState roomState, double costPerNight, size_t totalOccupancy, size_t actualOccupancy) :
    roomNumber(roomNumber), description(std::move(description)), floor(floor), section(section),
    roomState(roomState), costPerNight(costPerNight), totalOccupancy(totalOccupancy),
    actualOccupancy(actualOccupancy) {
      Guest guests[totalOccupancy];
  }
  
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

class Hotel
{
protected:
  double income{0};
  Employee employees[20];
public:
  string name;
  Hotel(string name) : name(std::move(name)) {}
};

int main()
{
  Hotel CPPsichHotel{"CPPsichHotel"};
  Room x{255, "Showcase room", 2, 'C', RoomState::Available, 45.5, 12, 6};
  Employee manager{"John", "Smith", 49};
  Guest first_guest{};
  std::cout << x.description << '\n';
  return 0;
}
