#include <bits/stdc++.h>
using namespace std;

/*
A post condition must be statisfied after a method is executed.
Sub classes can strengthen the postcondition but cannot weaken it.
*/

class Car {
    protected:
        int speed;
    public:
        Car(int speed){
            this->speed = speed;
        }

        void accelerate(){
            cout << "Accelerating" << endl;
            speed += 20;
        }

        // Post-Condition: Speed must reduce after brake
        virtual void brake() {
            cout << "Applying brake" << endl;
            speed -= 20;
        }
};

class HybridCar : public Car {
    private:
        int charge;
    public:
        HybridCar() : Car(40){
            charge = 0;
        }
    
    /*
    PostCondition: Speed must reduce after brake
    PostCondition: Charging must increase.
    */
    void brake(){
        cout << "Applying brakes" << endl;
        speed -= 20;
        cout << "Speed: " << speed << endl;
        charge += 10;
        cout << "Charge: " << charge << endl;
    }
};

int main(){
    Car* hybridCar = new HybridCar();
    hybridCar->brake();              // Works fine: HybridCar reduces speed and also increases charge.

    // Client feels no difference in substituting HybridCar in place of Car.
    return 0;
}