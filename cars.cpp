#include "header_files/cars.hpp"
#include "file_handling.cpp"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <fstream>
#include <iostream>
#include <ctime> // For time-related functions
#include <iomanip>
using namespace std;
using namespace std::chrono;

string formatDate(const tm* timeInfo) {
    stringstream ss;
    ss << setw(2) << setfill('0') << timeInfo->tm_mday << "-" << setw(2) << setfill('0') << timeInfo->tm_mon + 1 << "-" << (timeInfo->tm_year + 1900);
    return ss.str();
}
time_t stringToTime(const string& dateStr) {
    tm tm = {};
    stringstream ss(dateStr);
    ss >> get_time(&tm, "%d-%m-%Y");
    return mktime(&tm);
}

void Car::request(string ID, string userID, string number_of_days) {
    auto data = loadCSV("DB/cars.csv");
    for (auto& row : data) {
        if (row[0] == ID) {
            if (row[4] == "1") {
                cout << "The car has been rented" << endl;
                // Update the availability, userID, and number_of_days fields
                row[4] = "0";
                row[5] = userID;
                row[6] = number_of_days;            
               time_t now = time(0);
               tm* currentTime = localtime(&now);

    // Calculate future time
                auto futureTime = system_clock::from_time_t(now) + hours(stoi(row[6]) * 24);
                time_t futureTime_t = system_clock::to_time_t(futureTime);
                tm* futureTimeInfo = localtime(&futureTime_t);

    // Format future time as DD-MM-YYYY
                row[7] = formatDate(futureTimeInfo);

            } 
            else {
                cout << "Car is not available" << endl;
            }
        }
    }
    saveCSV("DB/cars.csv", data); // Save the updated data back to the CSV file
}


void Car::show_duedate(string ID) {
    auto currentTime = system_clock::now();
    auto data = loadCSV("DB/cars.csv");
    for (auto& row : data) {
        if (row[0] == ID) {
            if (row[4] == "0") {

                cout << row[7] << endl;
                // auto futureTime = currentTime + seconds(stoi(row[6]) * 24 * 60 * 60);
                // time_t futureTime_t = system_clock::to_time_t(futureTime);
                // tm* futureTimeInfo = localtime(&futureTime_t);
                // cout << "The car is due on: " << put_time(futureTimeInfo, "%d-%m-%y") << endl;
            } else {
                cout << "Car is not rented" << endl;
            }
        }
    }
}

string Car::return_car(string ID, string condition_in_which_car_returned) {
    auto data = loadCSV("DB/cars.csv");
    for (auto& row : data) {
            if (row[0] == ID) {
                if (row[4] == "0") {
                    row[2] = condition_in_which_car_returned;
                    cout << "The car has been returned" ;
                    row[4] = "1";
                    row[5] = "";
                    int days = stoi(row[6]);
                    row[6] = "0";
                    // calculate the fine the number of days the person was late to return the car
                    // multiply it with 200 and add that to the return value of the function
                    time_t date = stringToTime(row[7]);

    // Get current time
    time_t now = time(0);

    // Calculate the difference in seconds
    double difference = difftime(date, now);

    // Convert difference to days
    int daysDifference = difference / (60 * 60 * 24);
                    int late_fine= (daysDifference*200);


                    saveCSV("DB/cars.csv", data);
                    return to_string(days * 100+late_fine);
                } else {
                    cout << "Car is not rented" << endl;
                    return "0";
                }
            }
        }
    return "";
}


void Car::add(string carID, string Model, string Condition, string LicensePlate) {
    vector<vector<string>> data = loadCSV("DB/cars.csv");
    data.push_back({carID, Model, Condition, LicensePlate, "1", "", "0",""});
    saveCSV("DB/cars.csv", data);
}

void Car::update(string carID, string Model, string Condition, string LicensePlate, bool availiblity, string userID, string number_of_days) {
    auto data = loadCSV("DB/cars.csv");
    for (auto& row : data) {
        if (row[0] == carID) {
            row[1] = Model;
            row[2] = Condition;
            row[3] = LicensePlate;
            row[4] = to_string(availiblity);
            row[5] = userID;
            row[6] = number_of_days;

            int days = stoi(row[6]);
            time_t now = time(0); // Get current time
           time_t dueTime = now + days * 24 * 60 * 60; // Calculate due time in seconds
          tm* dueTimeInfo = localtime(&dueTime); // Convert due time to tm struct

             row[7] = formatDate(dueTimeInfo); // Format due time and store it in row[7]


             // [7] is the due date, so we don't want to change it
            break;
        }
    }
    saveCSV("DB/cars.csv", data);
}

void Car::delete_car(string ID) {
    auto data = loadCSV("DB/cars.csv");
    for (int i = 0; i < data.size(); i++) {
        if (data[i][0] == ID) {
            data.erase(data.begin() + i);
            break;
        }
    }
    saveCSV("DB/cars.csv", data);
}

void Car::search(string ID) {
    auto data = loadCSV("DB/cars.csv");
    for (auto& row : data) {
        if (row[0] == ID) {
            cout << "Car ID: " << row[0] << endl;
            cout << "Model: " << row[1] << endl;
            cout << "Condition (out of 10): " << row[2] << endl;
            cout << "License Plate: " << row[3] << endl;
            if (row[4] == "1") {
                cout << "Availability: Yes" << endl;
            } else {
                cout << "Availability: No" << endl;
            }
            cout << "User ID: " << row[5] << endl;
            cout << "Days from when it will be available: ";
            show_duedate(ID);
            break;
        }
    }
}


void Car::display() {
    auto data = loadCSV("DB/cars.csv");
    for (auto& row : data) {
         {
            cout << "Car ID: " << row[0] << endl;
            cout << "Model: " << row[1] << endl;
            cout << "Condition (out of 10): " << row[2] << endl;
            cout << "License Plate: " << row[3] << endl;
            if (row[4] == "1") {
                cout << "Availability: Yes" << endl;
            } else {
                cout << "Availability: No" << endl;
            }
        }
    }
}
string Car::car_condition(string ID) {
    auto data = loadCSV("DB/cars.csv");
    for (auto& row : data) {
        if (row[0] == ID) {
            string val= row[2] ;
            break;
        }
    }
    return " val";
}