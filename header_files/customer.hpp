#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "C:\CPP-Assignment\cpp_files\manager.cpp"

#include <vector>
#include <string>

using namespace std;

class Customer : public User {
public:
    void clear_due(string userID, string carID, string pay,string customer_record) ;
    void add(string ID, string password, string record) ;
    void update(string ID, string carID,string number_of_days) ;
    void deleteUser(string ID) ;
    void search(string ID) ;
    void display() ;
    void modify(string ID, string password, string record, string fine_due, string number_of_cars_rented, string cars_rented) ;
};
#endif
