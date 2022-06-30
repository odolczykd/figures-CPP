#include <iostream>
#include <cmath>
#include "point.h"
using namespace std;

point::point(){
    x=0;
    y=0;
}

point::point(float a, float b){
    x=a;
    y=b;
}

istream& operator>>(istream& in, point &p){
    float a, b;
    in >> a >> b;
    p.x = a;
    p.y = b;
    return in;
}

ostream& operator<<(ostream& out, point &p){
    out << '(' << p.x << ',' << p.y << ')';
    return out;
}

point point::operator+(point p){
    point res;
    res.x = this->x + p.x;
    res.y = this->y + p.y;
    return res;
}

point point::operator-(point p){
    point res;
    res.x = this->x - p.x;
    res.y = this->y - p.y;
    return res;
}

point operator*(float k, point p){
    point res;
    res.x = k * p.x;
    res.y = k * p.y;
    return res;
}

void point::setValue(point p){
    this->x = p.x;
    this->y = p.y;
}

void point::setValue(float a, float b){
    this->x = a;
    this->y = b;
}

float point::getValue(int what){
    if(what==1) return this->x;
    if(what==2) return this->y;
    return 0;
}

float distance(point a, point b){
    return sqrt((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y));
}
