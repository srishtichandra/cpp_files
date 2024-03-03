#ifndef Employee_H
#define Employee_H
#include "C:\CPP-Assignment\cpp_files\manager.cpp"
#include <vector>
#include <string>

using namespace std;

class Employee : public User {
     string userID;
    string filename;
    string password;
    string record;
public:
    void clear_due(string userID, string carID, string pay,string update_record) override;
    void add(string ID, string password, string record) override;
    void update(string ID, string carID,string number_of_days) override;
    void deleteUser(string ID) override;
    void search(string ID) override;
    void display() override;
    void modify(string ID, string password, string record, string fine_due, string number_of_cars_rented, string cars_rented) override;
};
#endif