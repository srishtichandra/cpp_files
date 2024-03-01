#include <iostream>
#include <string>

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
