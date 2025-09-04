#include <bits/stdc++.h>
using namespace std;

// Separate interfaces for 2D shapes
class TwoDimensionalShapes{
    public:
        virtual double area() = 0;
};

class ThreeDimensionalShapes{
    public:
        virtual double area() = 0;
        virtual double volume() = 0;
};

// Square implements 2D interface
class Square : public TwoDimensionalShapes {
    private:
        double side;
    public:
        Square(double s) : side(s) {}
    
        double area() override {
            return side * side;
        }
}; 

// Rectangle implements 2D interface
class Rectangle : public TwoDimensionalShapes {
    private:
        double length, width;
    public:
        Rectangle(double l, double w) : length(l), width(w) {}
    
        double area() override {
            return length * width;
        }
}; 

// Cube implements 3D interface
class Cube : public ThreeDimensionalShapes {
    private:
        double side;
    public:
        Cube(double s) : side(s) {}
    
        double area() override {
            return 6 * side * side;
        }

        double volume() override {
            return pow(side, 3);
        }
}; 

int main(){
    TwoDimensionalShapes* square = new Square(5);
    TwoDimensionalShapes* rectangle = new Rectangle(4, 6);
    ThreeDimensionalShapes* cube = new Cube(3);

    cout << "Area of square: " << square->area() << endl;
    cout << "Area of rectangle: " << rectangle->area() << endl;
    cout << "Area of cube: " << cube->area() << endl;
    cout << "Volume of cube: " << cube->volume() << endl;

    return 0;
}

