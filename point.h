/*
    Klasa point przechowujaca podstawowe informacje o punkcie w ukladzie wspolrzednych
*/

#include <iostream>
using namespace std;

class point{
    float x, y;
public:
    point();
    point(float a, float b);

    friend istream& operator>>(istream &in, point &p);
    friend ostream& operator<<(ostream &out, point &p);

    point operator+(point p);
    point operator-(point p);
    friend point operator*(float k, point p);
    void setValue(point p);
    void setValue(float a, float b);
    float getValue(int what);

    friend float distance(point a, point b);
};