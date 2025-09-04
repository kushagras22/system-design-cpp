#include <bits/stdc++.h>
using namespace std;

// Single interface for all shapes (Violates ISP)
class Shape{
    public:
        virtual double area() = 0;
        virtual double volume() = 0;   // 2D shapes do not have volume
};

// Square is a 2D shape but is forced to implement volume()
class Square : public Shape {
    private:
        double side;
    public:
        Square(double s) : side(s) {}
    
        double area() override {
            return side * side;
        }

        double volume() override {
            throw logic_error("Volume not applicable for square");   // Unnecessary Method
        }
}; 

// Rectangle is a 2D shape but is forced to implement volume()
class Rectangle : public Shape {
    private:
        double length, width;
    public:
        Rectangle(double l, double w) : length(l), width(w) {}
    
        double area() override {
            return length * width;
        }

        double volume() override {
            throw logic_error("Volume not applicable for rectangle");   // Unnecessary Method
        }
}; 

// Cube is a 3D shape, so it actually has a volume
class Cube : public Shape {
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
    Shape* square = new Square(5);
    Shape* rectangle = new Rectangle(4, 6);
    Shape* cube = new Cube(3);

    cout << "Area of square: " << square->area() << endl;
    cout << "Area of rectangle: " << rectangle->area() << endl;
    cout << "Area of cube: " << cube->area() << endl;
    cout << "Volume of cube: " << cube->volume() << endl;

    try{
        cout << "Square Volume: " << square->volume() << endl;  // Throws an exception
    } catch(logic_error& e){
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}

