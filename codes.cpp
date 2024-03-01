#include "header_files/cars.hpp"
#include "header_files/employee.hpp"
#include "header_files/customer.hpp"
#include "cars.cpp"
#include "employee.cpp"
#include "customer.cpp"
#include "file_handling.cpp"
#include <iostream>
#include <string>
#include <fstream>
#include "manager.cpp"

string userID; string  password;
using namespace std;

bool authenticateUser(const string& filename, const string& userID, const string& password) {
    // Load user data from CSV file
    vector<vector<string>> users = loadCSV(filename);

    // Search for the user ID in the loaded data
    for (const auto& user : users) {
        if (user[0] == userID && user[1] == password) {
            // User ID and password match, authentication successful
            return true;
        }
    }

    // User ID or password doesn't match, authentication failed
    return false;
}

// Function to handle login for any type of user
bool loginUser(const string& userType, const string& userFile) {
   
    cout << "Enter " << userType << " ID: ";
    cin >> userID;
    cout << "Enter password: ";
    cin >> password;
    
    // Perform authentication
    if (authenticateUser(userFile, userID, password)) {
        cout << userType << " authentication successful!" << endl;
        return 1;
        // Proceed with user-specific functionalities
    } else {
        cout << userType << " authentication failed. Invalid user ID or password." << endl;
        return 0;
    }
}



// Function to display a box-style menu option
void displayMenuOption(const string& option) {
    int len = option.length();
    cout << " ";
    for (int i = 0; i < len + 4; ++i) cout << "_";
    cout << endl;
    cout << "| " << option << " |" << endl;
    cout << "|";
    for (int i = 0; i < len + 2; ++i) cout << "_";
    cout << "|" << endl;
}

// Function to display the main menu
void displayMainMenu() {
    cout << "\nMain Menu:" << endl;
    displayMenuOption("1. Customer Login");
    displayMenuOption("2. Employee Login");
    displayMenuOption("3. Manager Login" );
    displayMenuOption("3. Exit"          );
}

int main() {
    displayMenuOption("Welcome to car Rental System");
    // Main menu
    int choice1, choice2;
    do {
        displayMainMenu();
        cout << "Enter your choice: ";
        cin >> choice1;
         Car car;
        string carID, Model, Condition, LicensePlate,customer_record, fine_due, number_of_cars_rented;
                       // vector<string> cars_rented(stoi(number_of_cars_rented));
        bool availability;
                        string userID;
                        string number_of_days;
                        Customer customer;
                        Employee employee;
                        Manager manager;

        switch (choice1) {            
            case 1:
                if (loginUser("Customer", "DB/customer.csv")) {
                    do {
                        cout << "1. Display cars" << endl;
                        cout << "2. Request a car" << endl;
                        cout << "3. Search a car" << endl;
                        cout << "4. Return a car" << endl;
                        cout << "5. Show due date of a car" << endl;
                        cout << "6. Exit" << endl;
                        cout << "Enter your choice: ";
                        cin >> choice2;
                        Car car;
                        Customer customer;
                        string carID;
                        string pay;

                        switch (choice2) {
                            case 1:
                                car.display();
                                break;
                            case 2:
                                cout << "Enter the car ID: ";
                                cin >> carID; int number_of_days; 
                                cout << "Enter the number of days you want to rent the car from today: ";
                                cin >> number_of_days;
                                car.request(carID, userID, to_string(number_of_days));
                                customer.update(userID, carID);
                                break;
                            case 3:
                                cout << "Enter the car ID: ";
                                cin >> carID;
                                car.search(carID);
                                break;
                            case 4:
                                cout << "Enter the car ID: ";
                                cin >> carID;
                 
                                pay= car.return_car(carID);
                                cout << "Pay this amount" << pay << endl;
                                customer.clear_due(userID,carID,pay);
                                break;
                            case 5:
                                cout << "Enter the car ID: ";
                                cin >> carID;
                                car.show_duedate(carID);
                                break;
                            case 6:
                                cout << "Exiting program..." << endl;
                                break;
                            default:
                                cout << "\nInvalid choice. Please try again." << endl;
                                break;
                        }
                    } while (choice2 != 6);
                }
                break;
            case 2:
                if (loginUser("Employee", "DB/employee.csv")) {
                    do {
                        cout << "1. Display cars" << endl;
                        cout << "2. Request a car" << endl;
                        cout << "3. Search a car" << endl;
                        cout << "4. Return a car" << endl;
                        cout << "5. Show due date of a car" << endl;
                        cout << "6. Exit" << endl;
                        cout << "Enter your choice: ";
                        cin >> choice2;
                        Car car;
                        Employee employee;
                        string carID;
                        switch (choice2) {
                            case 1:
                                car.display();
                                break;
                            case 2:
                                cout << "Enter the car ID: ";
                                cin >> carID;int number_of_days;
                              cout << "Enter the number of days you want to rent the car from today: ";
                                cin >> number_of_days;
                                car.request(carID,userID, to_string(number_of_days));
                                employee.update(userID, carID);

                                break;
                            case 3:
                                cout << "Enter the car ID: ";
                                cin >> carID;
                                car.search(carID);
                                break;
                            case 4:
                                cout << "Enter the car ID: ";
                                cin >> carID;
                                cout << "Pay this amount" << car.return_car(carID);
                                break;
                            case 5:
                                cout << "Enter the car ID: ";
                                cin >> carID;
                                car.show_duedate(carID);
                                break;
                            case 6:
                                cout << "Exiting program..." << endl;
                                break;
                            default:
                                cout << "\nInvalid choice. Please try again." << endl;
                                break;
                        }
                    } while (choice2 != 6);
                }
                break;
            case 3: 
            
             cout << "Enter  ID: ";
                     cin >> userID;
                     cout << "Enter password: ";
                     cin >> password;
            if(userID==manager.getID() && password==manager.getPassword()){
                    do {
                        cout << "1. Display cars" << endl;
                        cout << "2. Add a car" << endl;
                        cout << "3. Update a car" << endl;
                        cout << "4. Delete a car" << endl;
                        cout << "5. Search a car" << endl;
                        cout << "6 Display customers" << endl;
                        cout << "7. Add a customer" << endl;                       
                        cout << "8. Delete a customer" << endl;
                        cout << "9. Search a customer" << endl;
                        cout << "10. Display employees" << endl;
                        cout << "11. Add an employee" << endl;                       
                        cout << "12. Delete an employee" << endl;
                        cout << "13. Search an employee" << endl;
                        cout << "14. Exit" << endl;
                        cout << "Enter your choice: ";
                        cin >> choice2;
                       
                        switch (choice2) {
                            case 1:
                                car.display();
                                break;
                            case 2:
                                cout << "Enter the car ID: ";
                                cin >> carID;
                                cout << "Enter the model: ";
                                cin >> Model;
                                cout << "Enter the condition: ";
                                cin >> Condition;
                                cout << "Enter the license plate: ";
                                cin >> LicensePlate;
                                car.add(carID, Model, Condition, LicensePlate);
                                break;
                            case 3:
                                cout << "Enter the car ID: ";
                                cin >> carID;
                                cout << "Enter the model: ";
                                cin >> Model;
                                cout << "Enter the condition: ";
                                cin >> Condition;
                                cout << "Enter the license plate: ";
                                cin >> LicensePlate;
                                cout << "Enter the availability: ";
                                cin >> availability;
                                cout << "Enter the user ID: ";
                                cin >> userID;
                                cout << "Enter the number of days: ";
                                cin >> number_of_days;
                                car.update(carID, Model, Condition, LicensePlate, availability, userID, number_of_days);
                                break;
                            case 4:
                                cout << "Enter the car ID: ";
                                cin >> carID;
                                car.delete_car(carID);
                                break;
                            case 5:
                                cout << "Enter the car ID: ";
                                cin >> carID;
                                car.search(carID);
                                break;
                            case 6:
                                customer.display();
                                break;
                            case 7: 
                                cout << "Enter the customer ID: ";
                                cin >> userID;
                                cout << "Enter the password: ";
                                cin >> password;
                                cout << "Enter the customer record: ";
                                cin >> customer_record;                            

                                customer.add(userID, password, (customer_record));
                                break;
                            case 8:
                                cout << "Enter the customer ID: ";
                                cin >> userID;
                                customer.delete_customer(userID);
                                break;
                            case 9:
                                cout << "Enter the customer ID: ";
                                cin >> userID;
                                customer.search(userID);
                                break;
                            case 10:
                                customer.display();
                                break;
                            case 11: 
                                cout << "Enter the customer ID: ";
                                cin >> userID;
                                cout << "Enter the password: ";
                                cin >> password;
                                cout << "Enter the customer record: ";
                                cin >> customer_record;                            

                                customer.add(userID, password, (customer_record));
                                break;
                            case 12:
                                cout << "Enter the customer ID: ";
                                cin >> userID;
                                customer.delete_customer(userID);
                                break;
                            case 13:
                                cout << "Enter the customer ID: ";
                                cin >> userID;
                                customer.search(userID);
                                break;

                            case 14:
                             cout << "Exiting program..." << endl;
                                break;
                            default:
                                cout << "\nInvalid choice. Please try again." << endl;
                                break;                                        
                          
                        }
                    } while (choice2 != 10);
                }
                else{
                    cout << "Invalid user ID or password." << endl;
                }
                break;
            case 4:
                cout << "\nExiting program..." << endl;
                break;
            default:
                cout << "\nInvalid choice. Please try again." << endl;
                break;
        }
    } while (choice1 != 3);

    return 0;
}
