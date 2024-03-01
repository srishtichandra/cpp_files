#ifndef Employee_H
#define Employee_H

#include <vector>
#include <string>

using namespace std;

class Employee {
private:
    string userID;
    string filename;
    string password;
    int Employee_record;
    int fine_due;
    int number_of_cars_rented;
    vector<string> cars_rented;

public:
   // Employee();
    //Employee(string ID, string password, int Employee_record, int fine_due, int number_of_cars_rented, vector<string> cars_rented);
    void clear_due(string userID, string carID, string pay);
    void add(string ID, string password, string Employee_record);
    void update(string ID, string carID);
    void delete_Employee(string ID);
    void search(string ID);
    void display();
    

};

#endif // Employee_H
