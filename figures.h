#include <iostream>
#include "point.h"
using namespace std;

/* Klasa abstrakcyjna figury z czystymi funkcjami wirtualnymi */
class Figure{
protected:
    string name;
public:
    virtual void showInfo() = 0;
    virtual float perimeter() = 0;
    virtual float area() = 0;
};

/* Klasa reprezentujaca trojkat */
class Triangle: public Figure{
protected:
    point a, b, c;
public:
    Triangle();
    Triangle(point x, point y, point z, string n);
    virtual void showInfo();
    virtual float perimeter();
    virtual float area();
    void centroid();
};

/* Klasa reprezentujaca trojkat prostokatny (klasa pochodna trojkata) */
class RightTriangle: public Triangle{
public:
    RightTriangle();
    RightTriangle(point x, point y, point z, string n);
    virtual void showInfo();
    void angles();
};

/* Klasa abstrakcyjna reprezentujaca czworokat z czystymi funkcjami wirtualnymi 
   (pochodna klasy Figure) */
class Quadrangle: public Figure{
public:
    Quadrangle();
    virtual void showInfo() = 0;
    virtual void showSides() = 0;
    virtual float perimeter() = 0;
    virtual float area() = 0;
    virtual void diagonalPoint() = 0;
    virtual float diagonalLength() = 0;
};

/* Klasa reprezentujaca prostokat (pochodna czworokata) */
class Rectangle: public Quadrangle{
protected:
    point a, b, c, d;
public:
    Rectangle();
    Rectangle(point w, point x, point y, point z, string n);
    virtual void showInfo();
    virtual void showSides();
    virtual float perimeter();
    virtual float area();
    virtual void diagonalPoint();
    virtual float diagonalLength();
};

/* Klasa reprezentujaca kwadrat (pochodna prostokata) */
class Square: public Rectangle{
public:
    Square();
    Square(point w, point x, point y, point z, string n);
    virtual void showInfo();
    virtual void showSides();
    virtual float perimeter();
    virtual float area();
    virtual void diagonalPoint();
    virtual float diagonalLength();
};

/* Klasa reprezentujaca elipse */
class Ellipse: public Figure{
    float a, b;
public:
    Ellipse();
    Ellipse(float x, float y, string n);
    virtual void showInfo();
    void ellipseEquation();
    virtual float perimeter();
    virtual float area();
};

/* Klasa reprezentujaca kolo */
class Circle: public Figure{
    point p;
    float r;
public:
    Circle();
    Circle(point a, float rd, string n);
    virtual void showInfo();
    void circleEquation();
    virtual float perimeter();
    virtual float area();
    float arcLength(float angle);
    float sectorArea(float angle);
};

/* Klasa reprezentujaca wielokat foremny */
class RegularPolygon: public Figure{
    int n;
    float len;
public:
    RegularPolygon();
    RegularPolygon(int a, float l, string nm);
    virtual void showInfo();
    virtual float perimeter();
    virtual float area();
    int howManyDiags();
    float angle();
};