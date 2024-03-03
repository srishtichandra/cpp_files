#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Manager {
public:
    string getID() {
        return ID;
    }

    string getPassword() {
        return password;}

private:
    string ID="admin";
    string password="password";
};
class User {
protected:
    string userID;
    string filename;
    string password;
    int record;
    int fine_due;
    int number_of_cars_rented;
    vector<string> cars_rented;

public:
     void gtID(string ID) {
        userID = ID;    
    }
    void gtPassword(string pass) {
        password = pass;
    }
    void gtRecord(int rec) {
        record = rec;
    }
    void gtFine_due(int fine) {
        fine_due = fine;
    }
    void gtNumber_of_cars_rented(int num) {
        number_of_cars_rented = num;
    }
};
