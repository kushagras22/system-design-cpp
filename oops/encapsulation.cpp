#include <bits/stdc++.h>
using namespace std;

class SportsCar {
    private:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
        int currentGear;
        string tyre;
        
    public:
        SportsCar(string carBrand, string carModel) {
            this->brand = carBrand;
            this->model = carModel;
            isEngineOn = false;
            currentSpeed = 0;
            currentGear = 0;
        }   

        // Getter and Setter
        int getCurrentSpeed(){
            return this->currentSpeed;
        }

        string getTyre(){
            return this->tyre;
        }

        void setTyre(string tyre){
            this->tyre = tyre;
        }

        // Behaviours (or methods)
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
    SportsCar* mySportsCar = new SportsCar("Maruti", "Alto");
    mySportsCar->startEngine();
    mySportsCar->shiftGear(1);
    mySportsCar->accelerate();
    mySportsCar->shiftGear(2);
    mySportsCar->accelerate();
    mySportsCar->brake();
    mySportsCar->stopEngine(); 
    mySportsCar->setTyre("MRF");
    cout << mySportsCar->getTyre() << endl;
    
    // Arbitrary speed, that raises error due to being private. 
    // Can be changed using getter or setter if they exist.
    // mySportsCar->currentSpeed = 250;
    

    delete mySportsCar;
    return 0;
}