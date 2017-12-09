#include <iostream>
#include <fstream>
#include <string>
#include "car_service.h"

using namespace std;

CarService readData(const string &fileName);
void printCarParam(const CarService& cars);
void printCarParam(const Car& car);

int main()
try
{
  CarService carService; 
  carService = readData("car_db.txt");

  // �������� ����������� ����� �� �����
  printCarParam(carService);

  // ��������� ������ �� �� ������� 
  printCarParam(carService.getCar(2));
  printCarParam(carService.getCar(4));

  // ��������� ������ �� �� ��������� �����
  printCarParam(carService.getCar("MN51M"));

  // �������� ������ 
  carService.popCar();
  carService.popCar();
  printCarParam(carService);

}
catch(char* s) {
  cout << s << endl;
}

CarService readData(const string &fileName)
{
  ifstream fin(fileName);
  if(!fin.is_open()) {
    throw "Error: file doesn't open";
  }
  CarService retCars;

  while(!fin.eof()) {
    Car car;
    fin >> car.licensePlate >> car.color >> car.numWheels >> car.owner;
    retCars.addCar(car);
  }
  return retCars;
}

void printCarParam(const CarService & cars)
{
  for(auto car : cars.getCars()) {
    cout << car.licensePlate << " " << car.color << " " << car.numWheels << " " << car.owner << endl;
  }
  cout << endl;
}

void printCarParam(const Car & car)
{
  cout << car.licensePlate << " " << car.color << " " << car.numWheels << " " << car.owner << endl;
  cout << endl;
}
