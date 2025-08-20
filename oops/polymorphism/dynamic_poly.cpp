#include <bits/stdc++.h>
using namespace std;

class Car {
    protected:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
    
    public:
        Car(string b, string m){
            this->brand = b;
            this->model = m;
            isEngineOn = false;
            currentSpeed = 0;
        }

        void startEngine(){
            isEngineOn = true;
            cout << brand << " " << model << " : Engine Started"<< endl;
        }

        void stopEngine() {
            isEngineOn = false;
            currentSpeed = 0;
            cout << brand << " " << model << " : Engine Stopped" << endl;
        }

        virtual void accelerate() = 0;      // Abstract method for dynamic polymorphism
        virtual void brake() = 0;           // Abstract method for dynamic polymorphism
        virtual ~Car() {}
};

class ManualCar : public Car {
    private:
        int currentGear;
    
    public:
        ManualCar(string b, string m) : Car(b, m) {
            this->currentGear = 0;
        }

        void shiftGear(int gear) {
            currentGear = gear;
            cout << brand << " " << model << " : Shifted to gear " << currentGear << endl;
        }

        // Overriding accelerate - dynamic polymorphism
        void accelerate() {
            if(!isEngineOn) {
                cout << brand << " " << model << " : Cannot accelerate! Engine is off " << endl;
                return;
            }
            currentSpeed += 20;
            cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" << endl;
        }

        // Overriding brake - dynamic polymorphism
        void brake() {
            currentSpeed -= 20;
            if(currentSpeed < 0)
                currentSpeed = 0;
            cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/h" << endl;
        }
};

class ElectricCar : public Car {
    private:
        int batteryLevel;
    
    public:
        ElectricCar(string b, string m) : Car(b, m) {
            this->batteryLevel = 100;
        }

        // Overriding accelerate - dynamic polymorphism
        void accelerate() {
            if(!isEngineOn) {
                cout << brand << " " << model << " : Cannot accelerate! Engine is off " << endl;
                return;
            }

            if(batteryLevel <= 0) {
                cout << brand << " " << model << " : Battery dead! Cannot accelerate." << endl;
                return;
            }

            batteryLevel -= 10;
            currentSpeed += 15;
            cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h. Battery at " << batteryLevel << "%" << endl;  
        }

        // Overriding brake - dynamic polymorphism
        void brake() {
            currentSpeed -= 15;
            if(currentSpeed < 0)
                currentSpeed = 0;
            cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/h" << endl;
        }

        void chargeBattery() {
            batteryLevel = 96;
            if(batteryLevel == 100){
                cout << brand << " " << model << " : Battery fully charged!" << endl;
            } else if(batteryLevel < 20) {
                cout << brand << " " << model << " : Battery low, Plug in charger!" << endl;
            } else {
                cout << brand << " " << model << " : Battery percentage: " << batteryLevel << "%" << endl;
            }
        }
};

int main() {
    ManualCar* myManualCar = new ManualCar("Suzuki", "DZire");
    myManualCar->startEngine();
    myManualCar->accelerate();
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();

    cout << "------------------------------" << endl;

    ElectricCar* myElectricCar = new ElectricCar("Mahindra", "BYD");
    myElectricCar->startEngine();
    myElectricCar->accelerate();
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->stopEngine();

    delete myManualCar;
    delete myElectricCar;

    return 0;
}
