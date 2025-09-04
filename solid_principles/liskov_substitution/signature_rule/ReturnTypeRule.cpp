#include <bits/stdc++.h>
using namespace std;

/*
Return Type Rule:
-> Subtype overridden method return type should be either identical or narrower than the parent method's
return type.

-> This is also called as return type covariance.
-> C++ enforces this by covariance. 
*/

class Animal{
    // Some common class Animal methods
};

class Dog : public Animal {
    // Additional class Dog methods specific to dogs.
};

class Parent {
    public:
        virtual Animal* getAnimal() {
            cout << "Parent: Returning Animal instance" << endl;
            return new Animal();
        }
};

class Child : public Parent {
    public:
        Dog* getAnimal() override {
            cout << "Child: Returning dog instance" << endl;
            return new Dog();
        }
};

class Client{
    private:
        Parent* p;
    
    public:
        Client(Parent* p){
            this->p = p;
        }

        void takeAnimal(){
            p->getAnimal();
        }
};

int main(){
    Parent* parent = new Parent();
    Child* child = new Child();

    // Calling dog(child class) instance
    Client* client = new Client(child);
    client->takeAnimal();
    
    // Calling Animal(parent class) instance
    client = new Client(parent);
    client->takeAnimal();

    return 0;
}