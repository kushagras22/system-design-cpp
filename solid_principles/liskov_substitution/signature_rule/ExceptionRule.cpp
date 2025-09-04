#include <bits/stdc++.h>
using namespace std;

/*
Exception Rule:
-> A subclass should throw fewer or narrower exceptions
(but not additional or broader exceptions) than the parent.

-> C++ does not enforces this. Hence no compilation error.
*/

/*
|----std:logic_error                   <- For logical errors detected before runtime
|    |----std::invalid_argument        <- Invalid function argument
|    |----std::domain_error            <- Function argument domain error
|    |----std::length_error            <- Exceeding valid length limits
|    |----std::out_of_range            <- Array or container index out of bounds
|
|----std::runtime_error                <- For errors that occur at runtime
|    |----std::range_error             <- Numeric result out of range
|    |----std::overflow_error          <- Arithmetic Overflow
|    |----std::underflow_error
*/


class Parent{
    public:
        virtual void getValue() noexcept(false) {    // Parent throws logic_error exception
            throw logic_error("Parent Error");
        }
};

class Child : public Parent{
    public:
        void getValue() noexcept(false) override{    // Child throws out_of_error exception
            throw out_of_range("Child Error");
        }
};

class Client{
    private:
        Parent* p;
    public:
        Client(Parent* p){
            this->p = p;
        }    
        void takeValue(){
            try{
                p->getValue();
            } catch(const logic_error& e){
                cout << "Logic error exception occured: " << e.what() << endl;
            }
        }
};

int main(){
    Parent* parent = new Parent();
    Child* child = new Child();

    Client* client = new Client(parent);
    client->takeValue();

    return 0;
}  