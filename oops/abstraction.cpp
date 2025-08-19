#include <bits/stdc++.h>
using namespace std;

class Car {
    public:
    virtual void startEngine() = 0;
    virtual void shiftGear(int gear) = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void stopEngine() = 0;
    virtual ~Car() {}
};

class SportsCar : public Car {
    public:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
        int currentGear;
        
        SportsCar(string carBrand, string carModel) {
            this->brand = carBrand;
            this->model = carModel;
            isEngineOn = false;
            currentSpeed = 0;
            currentGear = 0;
        }   

        void startEngine(){
            isEngineOn = true;
            cout << brand << " " << model << " Engine Started :)" << endl;
        }

        void shiftGear(int gear){
            if(!isEngineOn) {
                cout << "Cannot shift gear, engine is off!" << endl;
                return;
            }

            currentGear = gear;
            cout << brand << " " << model << " Shifted to gear " << currentGear << endl;
        }

        void accelerate() {
            if(!isEngineOn) {
                cout << "Cannot accelerate, engine is off!" << endl;
                return;
            }

            currentSpeed += 20;
            cout << brand << " " << model << " Accelerated to speed " << currentSpeed << "km/h" << endl;
        }

        void brake() {
            currentSpeed -= 20;
            if(currentSpeed < 0) {
                currentSpeed = 0;
            }
            cout << brand << " " << model << " Braking! Speed is now " << currentSpeed << "km/h" << endl;
        }

        void stopEngine() {
            isEngineOn = false;
            currentSpeed = 0;
            currentGear = 0;
            cout << brand << " " << model << " Engine Stopped!" << endl;
        }
};

int main() {
    Car* myCar = new SportsCar("Maruti", "Alto");
    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine(); 

    delete myCar;
    return 0;
}