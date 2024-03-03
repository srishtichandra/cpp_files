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
    virtual void clear_due(string userID, string carID, string pay,string update_record) = 0;
    virtual void add(string ID, string password, string record) = 0;
    virtual void update(string ID, string carID,string number_of_days) = 0;
    virtual void deleteUser(string ID) = 0;
    virtual void search(string ID) = 0;
    virtual void display() = 0;
    virtual void modify(string ID, string password, string record, string fine_due, string number_of_cars_rented, string cars_rented) = 0;
    
    // Add any other common functions or data members here
};
