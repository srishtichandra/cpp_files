#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream> 
#include "file_handling.cpp"
#include "header_files/employee.hpp" 
#include <fstream>

using namespace std;
void Employee::add(string ID, string password, string Employee_record) {
    auto data = loadCSV("DB/employee.csv");
    data.push_back({ID, password, Employee_record, "0", "0", ""});
    saveCSV("DB/employee.csv", data);
}
void Employee::update(string ID, string carID, string number_of_days) {
    // Load data from the CSV file
    vector<vector<string>> data = loadCSV("DB/employee.csv");

    for(auto& row : data){
        if(row[0] == ID){
            if(stoi(row[2])> stoi(row[4])) {
                row[2] = number_of_days;
                row[3]= to_string(stoi(row[3]) + stoi(number_of_days)*100);
                row[4] = to_string(stoi(row[4]) + 1);
                row[5] += " " + carID  ;
                
            }
            else{
                cout << "You have reached the maximum number of cars rented\n";
            }
            break;
        }
    }    

    saveCSV("DB/employee.csv", data);
}
void Employee::deleteUser(string ID) {
    // Load data from the CSV file
    vector<vector<string>> data = loadCSV("DB/employee.csv");

    for (auto it = data.begin(); it != data.end(); ++it) {
        if ((*it)[0] == ID) {
            data.erase(it);
            break;
        }
    }

    saveCSV("DB/employee.csv", data);
}
void Employee::search(string ID) {
    // Load data from the CSV file
    vector<vector<string>> data = loadCSV("DB/employee.csv");

    for (const auto& row : data) {
        if (row[0] == ID) {
            cout << "Employee ID: " << row[0] << endl;
            cout << "Password: " << row[1] << endl;
            cout << "Employee Record: " << row[2] << endl;
            break; // Stop searching after finding the Employee
        }
    }
}

void Employee::clear_due(string userID, string carID, string pay,string update_record) {
    // Load data from the CSV file
    vector<vector<string>> data = loadCSV("DB/employee.csv");

    for (auto& row : data) {
        if (row[0] == userID) {
           row[2] = to_string(stoi(row[2]) -  stoi(update_record)*0.5);
            row[3] = to_string(stoi(row[3]) - (.85*stoi(pay)));
            //employee gets 15% discount on the money he pays
            row[4] = to_string(stoi(row[4]) - 1);
            row[5] = deleteWord(row[5], carID);

            break;
        }
    }

    saveCSV("DB/employee.csv", data);
}

void Employee::display() {
    vector<vector<string>> data = loadCSV("DB/employee.csv");

    for (const auto& row : data) {
        cout << "Employee ID: " << row[0] << endl;
        cout << "Password: " << row[1] << endl;
        cout << "Employee Record: " << row[2] << endl;
        cout << "Fine Due: " << row[3] << endl;
        cout << "Number of Cars Rented: " << row[4] << endl;
        cout << "Cars Rented: " << row[5] << endl;
    }
}
void Employee::modify(string ID, string password, string employee_record, string fine_due, string number_of_cars_rented, string cars_rented) {
    // Load data from the CSV file
    vector<vector<string>> data = loadCSV("DB/employee.csv");

    for (auto& row : data) {
        if (row[0] == ID) {
            row[1] = password;
            row[2] = employee_record;
            row[3] = fine_due;
            row[4] = number_of_cars_rented;
            row[5] = cars_rented;
            break;
        }
    }

    saveCSV("DB/employee.csv", data);
}
