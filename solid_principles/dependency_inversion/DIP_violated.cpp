#include <bits/stdc++.h>
using namespace std;

class MySQLDB {         // Low-level module
    public:
        void saveToSQL(string data){
            cout << "Executing SQL Query: INSERT INTO users VALUES('" << data << "');" << endl;
        }
};

class MongoDB{
    public:
        void saveToMongo(string data) {         // Low-level module
            cout << "Executing MongoDB function: db.users.insert({name: '" << data << "'})" << endl;
        }
};

class UserService {      // High-level module (Tightly coupled)
    private:
        MySQLDB sqlDb;  // Direct dependency on MySQL
        MongoDB mongoDb; // Direct dependency on MongoDB
    public:
        void storeUserToSQL(string user){
            // MySQL-specific code
            sqlDb.saveToSQL(user);
        } 
        
        void storeUserToMongo(string user){
            // Mongo-specific code
            mongoDb.saveToMongo(user);
        } 
};

int main(){
    UserService service;
    service.storeUserToSQL("John");
    service.storeUserToMongo("Doe");

    return 0;
}