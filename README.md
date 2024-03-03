
**Car Rental System in C++ - README**

---

### Description:
This project is a car rental system implemented in C++ using Object-Oriented Programming (OOP) concepts. The system is designed to operate via a command-line interface and includes functionalities for managing records of cars rented per customer or employee, maintaining databases for customers, employees, and cars, and providing different privileges to customers, employees, and managers.

---
### Assumption:
- A user can rent cars only upto his/her customer records.
- If a customer/employee delayed the returning of his acr for n days his record depriciates by n/2.
- Admin can modify cars only when they are not rented.
- If a user has multiple rented cars then in the CSV files then the carTDs are displayed as a single string separated by space.

---

### Functionalities:
1. **Records Management**:
   - Records of cars rented per customer/employee have been maintained and is updated .
   - Customer_record and employee_record are updated based on various factors such as late return, damage caused, and condition of the returned car.

2. **Database Management**:
   - Separate databases for customers, employees, and cars are maintained in the 'CSV' format.
   - Functionalities for adding, updating, deleting, and searching records in each database are implemented using the differenr classes and derived classes.

3. **User Classes**:
   - Implement three different classes for customers, employees, and manager, each with specific privileges:
     - **Customer**: Can view available cars, browse rented cars, and rent a limited number of cars based on customer_record. Fines are imposed for late returns.
     - **Employee**: Similar to customers but with a 15% discount on all rentals. Fines are also imposed for late returns.
     - **Manager**: Can manage records for customers, employees, and cars. Can also view all cars and their rental status.


---

### Files:
- **cars.hpp**: Header file containing the class definition for managing cars.
- **customers.hpp**: Header file containing the class definition for managing customers.
- **employee.hpp**: Header file containing the class definition for managing employees.
- **manager.cpp**: Implementation file for the manager class.
- **file_handling**: Contains the base user class and all the functions that that interact with the csv files
- **cars.cpp**:Contains the functions and their definations that were mentioned in cars.hpp
- **customer.cpp**:Contains the functions and their definations that were mentioned in customer.hpp
- **manager.cpp**:Contains the functions and their definations that were mentioned in manager.hpp it also contains the base class "User" for the derived classes "Employee" and "Customer".
- **codes.cpp**:Contains the all functions and the maintains a responsive system



- **


---





### GitHub Repository:
[Link to GitHub Repository](https://github.com/srishtichandra/cpp_files.git)

---







The project has a main directory named CPP_Files.In this there are two sub directories DB(shortform for Database) and header_files.The DB directory has all the database regarding the cars,customers and employees,they have information stored in csv format.In the cars.csv each line has carID,car model,condition of the car,its availiblity,the user who has the car rented currently and the due date from when the car will be availbale.

Similarly, the customer and employees have similar kind of database with ID, password,user_record , money_that_needs_to_be_paid , number of cars presently rented and the carIDs of all the rented cars.

In the header_file directory we have three files containing the declaration of the car ,customer and employee classes.
 


## Setup Instructions
Clone this repository using the below command in terminal.
```
git clone https://github.com/srishtichandra/cpp_files.git
```
Run the code below to compile the files and create an executable file.
```
g++ -std=c++17 codes.cpp
```
Run the created executable file by running below code.
```
./a.exe
```

 
