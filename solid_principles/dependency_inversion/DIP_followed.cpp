#include <bits/stdc++.h>
using namespace std;

// Abstraction (Interface)
class DB{
    public:
        virtual void save(string data) = 0;     // Pure virtual function
};

class MySQLDB : public DB {         // Low-level module
    public:
        void save(string data) override {
            cout << "Executing SQL Query: INSERT INTO users VALUES('" << data << "');" << endl;
        }
};

class MongoDB : public DB{
    public:
        void save(string data) {    // Low-level module
            cout << "Executing MongoDB function: db.users.insert({name: '" << data << "'})" << endl;
        }
};

class UserService {      // High-level module (Loosely coupled)
    private:
        DB* db;          // Dependency Injection
    public:
        UserService(DB* database){
            db = database;
        } 
        
        void storeUser(string user){
            db->save(user);
        }
};

int main(){
    MySQLDB mysql;
    MongoDB mongodb;

    UserService service1(&mysql);
    service1.storeUser("John Doe");

    UserService service2(&mongodb);
    service2.storeUser("Jane Doe");

    return 0;
}