#include <iostream>
#include <iomanip>
#include <cmath>
#include "figures.h"
//#include "point.h"
using namespace std;

#define EPSILON 0.00001

/************* TROJKAT *************/

Triangle::Triangle(){
    a.setValue(0,0);
    b.setValue(0,0);
    c.setValue(0,0);
    name = "Triangle";
}

Triangle::Triangle(point x, point y, point z, string n){
    a.setValue(x);
    b.setValue(y);
    c.setValue(z);
    name = n;
}

void Triangle::showInfo(){
    cout << this->name << " - informacje o trojkacie" << endl;
    cout << "* Wierzcholki: " << a << ", " << b << ", " << c << endl;
    cout << "* Dlugosci bokow: " << distance(a,b) << ", " << distance(b,c) << ", " << distance(a,c) << endl;
    cout << "* Obwod: " << this->perimeter() << endl;
    cout << "* Pole: " << this->area() << endl;
    cout << "* Srodek ciezkosci: "; this->centroid(); cout << endl;
}

float Triangle::perimeter(){
    return (distance(a,b)+distance(b,c)+distance(a,c));
}

float Triangle::area(){
    float x,y,z,p;
    x = distance(a,b);
    y = distance(b,c);
    z = distance(a,c);
    p = (x+y+z)/2;
    return sqrt(p*(p-x)*(p-y)*(p-z));
}

void Triangle::centroid(){
    point res;
    float x = (a.getValue(1) + b.getValue(1) + c.getValue(1)) / 3;
    float y = (a.getValue(2) + b.getValue(2) + c.getValue(2)) / 3;
    res.setValue(x,y);
    cout << res;
}

/************* TROJKAT PROSTOKATNY *************/

RightTriangle::RightTriangle(){
    a.setValue(0,0);
    b.setValue(0,0);
    c.setValue(0,0);
    name = "RightTriangle";
}

RightTriangle::RightTriangle(point x, point y, point z, string n) : Triangle(x,y,z,n) {}

void RightTriangle::showInfo(){
    cout << this->name << " - informacje o trojkacie prostokatnym" << endl;
    cout << "* Wierzcholki: " << a << ", " << b << ", " << c << endl;
    cout << "* Dlugosci bokow: " << distance(a,b) << ", " << distance(b,c) << ", " << distance(a,c) << endl;
    cout << "* Obwod: " << this->perimeter() << endl;
    cout << "* Pole: " << this->area() << endl;
    cout << "* Miary katow wewnetrznych (w stopniach)"; this->angles(); cout << endl;
}

void RightTriangle::angles(){
    /* Jesli kat prosty jest przy wierzcholku a */
    if((distance(a,b)*distance(a,b)) + (distance(a,c)*distance(a,c)) - (distance(b,c)*distance(b,c)) <= EPSILON){
        cout << endl << "  > Kat przy wierzcholku " << a << ": ";
        cout << 90;
        cout << endl << "  > Kat przy wierzcholku " << b << ": ";
        cout << setprecision(2) << (180 * asin(distance(a,c) / distance(b,c))) / M_PI;
        cout << endl << "  > Kat przy wierzcholku " << c << ": ";
        cout << setprecision(2) << (180 * asin(distance(a,b) / distance(b,c))) / M_PI;
    }
    /* Jesli kat prosty jest przy wierzcholku b */
    else if((distance(b,a)*distance(b,a)) + (distance(b,c)*distance(b,c)) - (distance(a,c)*distance(a,c)) <= EPSILON){
        cout << endl << "  > Kat przy wierzcholku " << a << ": ";
        cout << setprecision(2) << (180 * asin(distance(b,c) / distance(a,c))) / M_PI;
        cout << endl << "  > Kat przy wierzcholku " << b << ": ";
        cout << 90;
        cout << endl << "  > Kat przy wierzcholku " << c << ": ";
        cout << setprecision(2) << (180 * asin(distance(a,b) / distance(a,c))) / M_PI;
    }
    /* Jesli kat prosty jest przy wierzcholku c */
    else{
        cout << endl << "  > Kat przy wierzcholku " << a << ": ";
        cout << setprecision(2) << (180 * asin(distance(b,c) / distance(a,b))) / M_PI;
        cout << endl << "  > Kat przy wierzcholku " << b << ": ";
        cout << setprecision(2) << (180 * asin(distance(a,c) / distance(a,b))) / M_PI;
        cout << endl << "  > Kat przy wierzcholku " << c << ": ";
        cout << 90;
    }
}

/************* CZWOROKAT (klasa abstrakcyjna) *************/

Quadrangle::Quadrangle(){
    name = "Czworokat";
}

/************* PROSTOKAT *************/

Rectangle::Rectangle(){
    a.setValue(0,0);
    b.setValue(0,0);
    c.setValue(0,0);
    d.setValue(0,0);
    name = "Prostokat";
}

Rectangle::Rectangle(point w, point x, point y, point z, string n){
    a.setValue(w);
    b.setValue(x);
    c.setValue(y);
    d.setValue(z);
    name = n;
}

void Rectangle::showInfo(){
    cout << this->name << " - informacje o prostokacie" << endl;
    cout << "* Wierzcholki: " << a << ", " << b << ", " << c << ", " << d << endl;
    cout << "* Dlugosci bokow: "; this->showSides(); cout << endl;
    cout << "* Dlugosc przekatnych: " << this->diagonalLength() << endl;
    cout << "* Punkt przeciecia przekatnych: "; this->diagonalPoint(); cout << endl;
    cout << "* Obwod: " << this->perimeter() << endl;
    cout << "* Pole: " << this->area() << endl;
}

void Rectangle::showSides(){
    /* Jesli AC jest przekatna */
    if((distance(a,b)*distance(a,b)) + (distance(b,c)*distance(b,c)) - (distance(a,c)*distance(a,c)) <= EPSILON){
        cout << distance(a,b) << ", " << distance(b,c);
    }
    /* Jesli AB jest przekatna */
    else if((distance(a,c)*distance(a,c)) + (distance(b,c)*distance(b,c)) - (distance(a,b)*distance(a,b)) <= EPSILON){
        cout << distance(a,c) << ", " << distance(b,c);
    }
    /* Jesli BC jest przekatna */
    else{
        cout << distance(a,b) << ", " << distance(a,c);
    }
}

float Rectangle::perimeter(){
    /* Jesli AC jest przekatna */
    if((distance(a,b)*distance(a,b)) + (distance(b,c)*distance(b,c)) - (distance(a,c)*distance(a,c)) <= EPSILON){
        return (distance(a,b) + distance(b,c) + distance(c,d) + distance(d,a));
    }
    /* Jesli AB jest przekatna */
    else if((distance(a,c)*distance(a,c)) + (distance(b,c)*distance(b,c)) - (distance(a,b)*distance(a,b)) <= EPSILON){
        return (distance(a,c) + distance(c,b) + distance(b,d) + distance(d,a));
    }
    /* Jesli BC jest przekatna */
    else{
        return (distance(a,c) + distance(c,d) + distance(d,b) + distance(b,a));
    }
}

float Rectangle::area(){
    /* Jesli AC jest przekatna */
    if((distance(a,b)*distance(a,b)) + (distance(b,c)*distance(b,c)) - (distance(a,c)*distance(a,c)) <= EPSILON){
        return (distance(a,b) * distance(b,c));
    }
    /* Jesli AB jest przekatna */
    else if((distance(a,c)*distance(a,c)) + (distance(b,c)*distance(b,c)) - (distance(a,b)*distance(a,b)) <= EPSILON){
        return (distance(a,c) * distance(c,b));
    }
    /* Jesli BC jest przekatna */
    else{
        return (distance(a,c) * distance(a,b));
    }
}

float Rectangle::diagonalLength(){
    /* Jesli AC jest przekatna */
    if((distance(a,b)*distance(a,b)) + (distance(b,c)*distance(b,c)) - (distance(a,c)*distance(a,c)) <= EPSILON){
        return distance(a,c);
    }
    /* Jesli AB jest przekatna */
    else if((distance(a,c)*distance(a,c)) + (distance(b,c)*distance(b,c)) - (distance(a,b)*distance(a,b)) <= EPSILON){
        return distance(a,b);
    }
    /* Jesli BC jest przekatna */
    else{
        return distance(b,c);
    }
}

void Rectangle::diagonalPoint(){
    point diagPt;
    float x, y;
    /* Jesli AC jest przekatna */
    if((distance(a,b)*distance(a,b)) + (distance(b,c)*distance(b,c)) - (distance(a,c)*distance(a,c)) <= EPSILON){
        x = (a.getValue(1) + c.getValue(1)) / 2;
        y = (a.getValue(2) + c.getValue(2)) / 2;
    }
    /* Jesli AB jest przekatna */
    else if((distance(a,c)*distance(a,c)) + (distance(b,c)*distance(b,c)) - (distance(a,b)*distance(a,b)) <= EPSILON){
        x = (a.getValue(1) + b.getValue(1)) / 2;
        y = (a.getValue(2) + b.getValue(2)) / 2;
        diagPt.setValue(x,y);
        cout << diagPt;
    }
    /* Jesli BC jest przekatna */
    else{
        x = (b.getValue(1) + c.getValue(1)) / 2;
        y = (b.getValue(2) + c.getValue(2)) / 2;
    }
    diagPt.setValue(x,y);
    cout << diagPt;
}

/************* KWADRAT *************/

Square::Square(){
    a.setValue(0,0);
    b.setValue(0,0);
    c.setValue(0,0);
    d.setValue(0,0);
    name = "Kwadrat";
}

Square::Square(point w, point x, point y, point z, string n) : Rectangle(w,x,y,z,n) {}

void Square::showInfo(){
    cout << this->name << " - informacje o kwadracie" << endl;
    cout << "* Wierzcholki: " << a << ", " << b << ", " << c << ", " << d << endl;
    cout << "* Dlugosc boku: "; this->showSides(); cout << endl;
    cout << "* Dlugosc przekatnych: " << this->diagonalLength() << endl;
    cout << "* Punkt przeciecia przekatnych: "; this->diagonalPoint(); cout << endl;
    cout << "* Obwod: " << this->perimeter() << endl;
    cout << "* Pole: " << this->area() << endl;
}

void Square::showSides(){
    /* Jesli AC jest przekatna */
    if(2*distance(a,b)*distance(a,b) - distance(a,c)*distance(a,c) <= EPSILON){
        cout << distance(a,b);
    }
    /* Jesli AB jest przekatna */
    else{
        cout << distance(a,c);
    }
}

float Square::perimeter(){
    /* Jesli AC jest przekatna */
    if(2*distance(a,b)*distance(a,b) - distance(a,c)*distance(a,c) <= EPSILON){
        return (4*distance(a,b));
    }
    /* Jesli AB jest przekatna */
    else{
        return (4*distance(a,c));
    }
}

float Square::area(){
    /* Jesli AC jest przekatna */
    if(2*distance(a,b)*distance(a,b) - distance(a,c)*distance(a,c) <= EPSILON){
        return (distance(a,b)*distance(a,b));
    }
    /* Jesli AB jest przekatna */
    else{
        return (distance(a,c)*distance(a,c));
    }
}

float Square::diagonalLength(){
    /* Jesli AC jest przekatna */
    if(2*distance(a,b)*distance(a,b) - distance(a,c)*distance(a,c) <= EPSILON){
        return (distance(a,b)*sqrt(2));
    }
    /* Jesli AB jest przekatna */
    else{
        return (distance(a,c)*sqrt(2));
    }
}

void Square::diagonalPoint(){
    point diagPt;
    float x, y;
    /* Jesli AC jest przekatna */
    if((distance(a,b)*distance(a,b)) + (distance(b,c)*distance(b,c)) - (distance(a,c)*distance(a,c)) <= EPSILON){
        x = (a.getValue(1) + c.getValue(1)) / 2;
        y = (a.getValue(2) + c.getValue(2)) / 2;
    }
    /* Jesli AB jest przekatna */
    else if((distance(a,c)*distance(a,c)) + (distance(b,c)*distance(b,c)) - (distance(a,b)*distance(a,b)) <= EPSILON){
        x = (a.getValue(1) + b.getValue(1)) / 2;
        y = (a.getValue(2) + b.getValue(2)) / 2;
        diagPt.setValue(x,y);
        cout << diagPt;
    }
    /* Jesli BC jest przekatna */
    else{
        x = (b.getValue(1) + c.getValue(1)) / 2;
        y = (b.getValue(2) + c.getValue(2)) / 2;
    }
    diagPt.setValue(x,y);
    cout << diagPt;
}

/************* ELIPSA *************/

Ellipse::Ellipse(){
    a = 0;
    b = 0;
    name = "Elipsa";
}

Ellipse::Ellipse(float x, float y, string n){
    a = x;
    b = y;
    name = n;
}

void Ellipse::showInfo(){
    cout << this->name << " - informacje o elipsie" << endl;
    cout << "* Rownanie elipsy: "; this->ellipseEquation(); cout << endl;
    cout << "* Dlugosci polosi: " << a << ", " << b << endl;
    cout << "* Obwod: " << this->perimeter() << endl;
    cout << "* Pole: " << this->area() << endl;
}

void Ellipse::ellipseEquation(){
    cout << "x^2 / " << a << " + y^2 / " << b << " = 1";
}

float Ellipse::perimeter(){
    /* wartosc przyblizona */
    return (M_PI * (3*(a+b) - sqrt((3*a+b)*(a+3*b))));
}

float Ellipse::area(){
    return (M_PI * a * b);
}

/************* OKRAG + KOLO *************/

Circle::Circle(){
    p.setValue(0,0);
    r = 0;
    name = "Kolo";
}

Circle::Circle(point a, float rd, string n){
    p.setValue(a);
    r = rd;
    name = n;
}

void Circle::showInfo(){
    float angle;
    cout << this->name << " - informacje o kole" << endl;
    cout << "* Rownanie kola: "; this->circleEquation(); cout << endl;
    cout << "* Promien: " << this->r << endl;
    cout << "* Srodek okregu: " << this->p << endl;
    cout << "* Obwod: " << this->perimeter() << endl;
    cout << "* Pole: " << this->area() << endl;
    cout << "> Podaj wartosc kata w stopniach z przedzialu [0,360]: "; cin >> angle;
    cout << "* Dlugosc luku wyznaczonego przez kat " << angle << " w kole " << this->name << ": " << this->arcLength(angle) << endl;
    cout << "* Pole wycinka wyznaczonego przez kat " << angle << " w kole " << this->name << ": " << this->sectorArea(angle) << endl;
}

void Circle::circleEquation(){
    cout << "(x-" << p.getValue(1) << ")^2 + (y-" << p.getValue(2) << ")^2 <= " << r << "^2";
}

float Circle::perimeter(){
    return (2 * M_PI * r);
}

float Circle::area(){
    return (M_PI * r * r);
}

float Circle::arcLength(float angle){
    return (angle*this->perimeter()) / 360;
}

float Circle::sectorArea(float angle){
    return (angle*this->area()) / 360;
}

/************* WIELOKAT FOREMNY *************/

RegularPolygon::RegularPolygon(){
    n = 0;
    len = 0;
    name = "Wielokat foremny";
}

RegularPolygon::RegularPolygon(int a, float l, string nm){
    n = a;
    len = l;
    name = nm;
}

void RegularPolygon::showInfo(){
    cout << this->name << " - informacje o wielokacie foremnym" << endl;
    cout << "* Liczba bokow: " << this->n << endl;
    cout << "* Dlugosc boku: " << this->len << endl;
    cout << "* Obwod: " << this->perimeter() << endl;
    cout << "* Pole: " << this->area() << endl;
    cout << "* Liczba przekatnych: " << this->howManyDiags() << endl;
    cout << "* Miara katow wewntrznych (w stopniach): " << this->angle() << endl;
}

float RegularPolygon::perimeter(){
    return (n*len);
}

float RegularPolygon::area(){
    return (0.25 * (n*len*len*tan(M_PI_2 - M_PI/n)));     /* A = 1/4 * n * len^2 * cot(PI/n) */
}

int RegularPolygon::howManyDiags(){
    return (0.5 * n * (n-3));
}

float RegularPolygon::angle(){
    return (180*(n-2)) / (float)n;
}