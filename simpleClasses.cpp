#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>

using namespace std;

float sqr(float x) {
    return pow(x, 2);
}

int sqr(int x) {
    return pow(x, 2);
}

int main() {
    int cAmt;
    int rAmt;
    Circle circles[10];
    Rectangle rectangles[10];
    cout << "How many circles would you like to initialize? (up to 10)\n";
    cin >> cAmt;
    cout << "\nHow many rectangles would you like to initialize? (up to 10)\n";
    cin >> rAmt;
    //cout << "\n";
    float ur;
    float ux;
    float uy;
    float us1;
    float us2;
    for (int i = 0; i < cAmt; i++) {
        cout << "\nInitializing circle #" <<i<<"\nInput radius: ";
        cin >> ur;
        cout << "\nInput x coordinate: ";
        cin >> ux;
        cout << "\nInput y coordinate: ";
        cin >> uy;
        circles[i] = * new Circle(ur, new Vector2(ux, uy));
    }
    for (int i = 0; i < rAmt; i++) {
        cout << "\nInitializing rectangel #" <<i<<"\nInput length of side 1: ";
        cin >> us1;
        cout << "\nInput length of side 2: ";
        cin >> us2;
        cout << "\nInput x coordinate: ";
        cin >> ux;
        cout << "\nInput y coordinate: ";
        cin >> uy;
        rectangles[i] = * new Rectangle(us1, us2, new Vector2(ux, uy));
    }
    cout << "\n\ndisplaying objects in tree form:\n\n";
    cout << "circles = [\n";
    for (int i = 0; i < cAmt; i++) {
        if (i != 0) {
            cout << "\n    ,\n";
        }
        cout << "    {\n        radius: " << circles[i].r << ",\n        coordinates: ("<<(*(circles[i].coords)).x<<","<<(*(circles[i].coords)).y<<")\n    }";
    }
    return 0;
}

class Circle {
    public:
        float r;
        Vector2* coords = new Vector2;
        Circle() {
            r = 1;
            coords = new Vector2(0,0); 
        }
        Circle(float rin, Vector2* cordsin) {
            r = rin;
            coords = (*cordsin).copySelf();
        }

        float area() {
            return M_PI*sqr(r);
        }

        float perimeter() {
            return M_PI*2*r;
        }
};

class Rectangle {
    public:
        float side1;
        float side2;
        Vector2* ulCoords = new Vector2;
        Rectangle() {
            side1 = 1;
            side2 = 1;
            ulCoords = new Vector2(0,0);
        }
        Rectangle(float sidein, float sidein2, Vector2* coordsin) {
            side1 = sidein;
            side2 = sidein2;
            ulCoords = *coordsin->copySelf();
        }
        float perimeter() {
            return side1*2+side2*2;
        }
        float area() {
            return side1*side2;
        }
};

class Vector2 {
    public:
        float x;
        float y;
        float mag;
        float list[2];
        float unitVector[2];

        void updateSelf() {
            mag = sqrt(sqr(x)+sqr(y));
            if (mag == 1) {
                unitVector[0] = x;
                unitVector[1] = y;
                return;
            }
            unitVector[0] = x/mag;
            unitVector[1] = y/mag;
        }
        Vector2() {
            x = 0;
            y = 0;
        }
        Vector2(float xin, float yin) {
            x = xin;
            y = yin;
            updateSelf();
        }
        void set(float xin, float yin) {
            x = xin;
            y = yin;
            updateSelf();
        }
        Vector2* copySelf() {
            return new Vector2(x, y);
        }
};

