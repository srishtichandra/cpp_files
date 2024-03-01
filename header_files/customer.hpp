#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <vector>
#include <string>

using namespace std;

class Customer {
private:
    string userID;
    string filename;
    string password;
    int customer_record;
    int fine_due;
    int number_of_cars_rented;
    vector<string> cars_rented;

public:
   // Customer();
    //Customer(string ID, string password, int customer_record, int fine_due, int number_of_cars_rented, vector<string> cars_rented);
    void clear_due(string userID, string carID, string pay);
    void add(string ID, string password, string customer_record);
    void update(string ID, string carID);
    void delete_customer(string ID);
    void search(string ID);
    void display();
    

};

#endif // CUSTOMER_H
