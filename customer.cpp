#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "file_handling.cpp"
#include "header_files/customer.hpp"
#include <fstream>


using namespace std;


void Customer::add(string ID, string password, string customer_record) {
    vector<vector<string>> data = loadCSV("DB/customer.csv");
    data.push_back({ID, password, customer_record, "0", "0", ""});
    saveCSV("DB/customer.csv", data);
}

void Customer::update(string ID,string carID) {
    // Load data from the CSV file
    //the customer will rent a car then the carID will be added to the cars_rented vector , number of cars rented will be incremented by 1
    vector<vector<string>> data = loadCSV("DB/customer.csv");
    cout << "Updating customer record\n";
    
    for(auto& row : data){
        if(row[0] == ID){
            row[4] = to_string(stoi(row[4]) + 1);
            row[5] += carID + " ";
            break;
        }
    }
    
    saveCSV("Db/customer.csv", data);
}

void Customer::deleteUser(string ID) {
    // Load data from the CSV file
    vector<vector<string>> data = loadCSV("DB/customer.csv");
    for (auto it = data.begin(); it != data.end(); ++it) {
        if ((*it)[0] == ID) {
            it = data.erase(it); // Erase the element and get the next iterator
            if (it == data.end()) // Check if it reached the end
                break; // If end is reached, exit the loop
        }
    }
    saveCSV("DB/customer.csv", data);
}


void Customer::search(string ID) {
    // Load data from the CSV file
    vector<vector<string>> data = loadCSV("DB/customer.csv");
    for (const auto &row : data) {
        if (row[0] == ID) {
            cout << "Customer ID: " << row[0] << endl;
            cout << "Password: " << row[1] << endl;
            cout << "Customer Record: " << row[2] << endl;
            break; // Stop searching after finding the customer
        }
    }
}
void Customer::clear_due(string userID ,string carID, string pay, string update_record) {
    // Load data from the CSV file
    vector<vector<string>> data = loadCSV("DB/customer.csv");

    for (auto& row : data) {
        if (row[0] == userID) {
            row[2] = to_string(stoi(row[2]) -  stoi(update_record)*0.5);
            row[3] = to_string(stoi(row[3]) - stoi(pay));
            row[4] = to_string(stoi(row[4]) - 1);
            row[5] = deleteWord(row[5], carID);

            break;
        }
    }
    saveCSV("DB/customer.csv", data);
}
void Customer::display() {
    vector<vector<string>> data = loadCSV("DB/customer.csv");
    for (const auto &row : data) {
        cout << "Customer ID: " << row[0] << endl;
        cout << "Password: " << row[1] << endl;
        cout << "Customer Record: " << row[2] << endl;
        cout << "Fine Due: " << row[3] << endl;
        cout << "Number of Cars Rented: " << row[4] << endl;
        cout << "Cars Rented: " << row[5] << endl;
    }
    cout << "-----------------------------------\n";
}
void Customer::modify(string ID, string password, string customer_record, string fine_due, string number_of_cars_rented, string cars_rented) {
    // Load data from the CSV file
    vector<vector<string>> data = loadCSV("DB/customer.csv");

    for (auto& row : data) {
        if (row[0] == ID) {
            row[1] = password;
            row[2] = customer_record;
            row[3] = fine_due;
            row[4] = number_of_cars_rented;
            row[5] = cars_rented;
            break;
        }
    }

    saveCSV("DB/customer.csv", data);
}