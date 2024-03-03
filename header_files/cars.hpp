#ifndef CARS_H
#define CARS_H
#include <vector>
#include <string>

using namespace std;

class Car {
private:
    string carID;
    string Model;
    string Condition;
    string LicensePlate;
    bool availability;
    string userID;
    string number_of_days;

public:
    //Car();
    //Car(string ID, string Model, string Condition, string LicensePlate, bool availability, string userID, stringnumber_of_days);
    void request(string ID,string userID, string number_of_days);
    void show_duedate(string ID);
    string return_car(string ID,string codition_in_which_car_returned);
    void add(string carID, string Model, string Condition, string LicensePlate);
    void update(string carID, string Model, string Condition, string LicensePlate, bool availability, string userID, string number_of_days);
    void delete_car(string ID);
    void search(string ID);
    void display();
    string car_condition(string ID);
};

#endif // CARS_H
