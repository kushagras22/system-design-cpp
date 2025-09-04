#include <bits/stdc++.h>
using namespace std;

/*
A pre-condition must be statisfied before a method can be executed.
Sub classes can weaken the precondition but cannot strengthen it.
*/

class User {
    public:
        // Precondition: Password must be at least 8 characters long
        virtual void setPassword(string password){
            if(password.length() < 8){
                throw invalid_argument("Password must be atleast 8 characters long!");
            }
            cout << "Password set successfully!" << endl;
        }
};

class AdminUser : public User {
    public:
        // Precondition: Password must be atleast 6 characters long
        void setPassword(string password) override {
            if(password.length() < 6){
                throw invalid_argument("Password must be atleast 6 characters long!");
            }
            cout << "Password set successfully!" << endl;
        }
};

int main(){
    User* user = new AdminUser();
    user->setPassword("Admin1");               // Works fine: AdminUser allows shorter passwords
}