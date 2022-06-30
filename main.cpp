/*
    PROGRAMOWANIE II (2021/22)
    Projekt obiektowy: Podstawowe informacje o figurach geometrycznych w ukladzie wspolrzednych
    Autor: Dawid Odolczyk

    Abstrakt:
    Program przechowuje i wyswietla podstawowe informacje o figurach geometrycznych osadzonych w kartezjanskim
    ukladzie wspolrzednych. Figury obslugiwane przez program osadzone sa w ponizszej hierarchii:
    0.     figura (klasa abstrakcyjna, rodzic wszystkich ponziszych klas)
    1.     trojkat
    1.1.   trojkat prostokatny
    2.     czworokat (klasa abstrakcyjna)
    2.1.   prostokat
    2.1.1. kwadrat
    3.1.   elipsa
    3.2.   okrag/kolo
    4.     wielokat foremny
*/

#include <iostream>
#include "figures.h"
using namespace std;

#define HOW_MANY_FIGS 16            // maksymalna liczba figur w bazie 
int i, mode, howManyAdded = 0;
Figure *f[HOW_MANY_FIGS];           // tablica z figurami geometrycznymi

/* Wyswietl spis tresci programu */
void contents(){
    cout << endl << "BAZA FIGUR GEOMETRYCZNYCH -- SPIS TRESCI" << endl;
    cout << "========================================" << endl << endl;
    cout << "1. Dodaj figure do bazy" << endl;
    cout << "2. Wyswietl informacje o figurze" << endl;
    cout << "3. Zakoncz program" << endl << endl;
    cout << "Wybierz opcje: ";
}

/* Dodaj figure do bazy */
void addFigure(){
    char fig;
    string figName;
    point a, b, c, d;
    float p, q, r;
    int x;
    cout << "Dostepne figury:" << endl;
    cout << "A. trojkat" << endl;
    cout << "B. trojkat prostokatny" << endl;
    cout << "C. prostokat" << endl;
    cout << "D. kwadrat" << endl;
    cout << "E. elipsa" << endl;
    cout << "F. kolo" << endl;
    cout << "G. wielokat foremny" << endl;
    cout << "Jaka figure chcesz dodac do bazy? ";
    cin >> fig;
    switch(fig){

    case 'A':
        cout << "Podaj nazwe trojkata: ";
        cin >> figName;
        cout << "Podaj trzy wspolrzedne (x,y) wierzcholkow trojkata " << figName << " w formacie: x y" << endl;
        cout << "(Ex. Dla danych wejsciowych 0 0 5.3 2 -4 7 otrzymamy trojkat o wierzcholkach (0,0), (5.3,2) i (-4,7))" << endl;
        cin >> a >> b >> c;
        f[howManyAdded++] = new Triangle(a,b,c,figName);
        cout << "Pomyslnie dodano trojkat " << figName << " do bazy (ID figury: " << howManyAdded<< ")" << endl;
	    break;

    case 'B':
        cout << "Podaj nazwe trojkata prostokatnego: ";
        cin >> figName;
        cout << "Podaj trzy wspolrzedne (x,y) wierzcholkow trojkata " << figName << " w formacie: x y" << endl;
        cout << "(Ex. Dla danych wejsciowych 0 0 3 0 0 4 otrzymamy trojkat prostokatny o wierzcholkach (0,0), (3,0) i (0,4))" << endl;
        cin >> a >> b >> c;
        f[howManyAdded++] = new RightTriangle(a,b,c,figName);
        cout << "Pomyslnie dodano trojkat prostokatny " << figName << " do bazy (ID figury: " << howManyAdded << ")" << endl;
	    break;

    case 'C':
        cout << "Podaj nazwe prostokata: ";
        cin >> figName;
        cout << "Podaj cztery wspolrzedne (x,y) wierzcholkow prostokata " << figName << " w formacie: x y" << endl;
        cout << "(Ex. Dla danych wejsciowych 0 0 2.1 3 -7 7 .5 -4 otrzymamy prostokat o wierzcholkach (0,0), (2.1,3), (-7,7) i (0.5,-4))" << endl;
        cin >> a >> b >> c >> d;
        f[howManyAdded++] = new Rectangle(a,b,c,d,figName);
        cout << "Pomyslnie dodano prostokat " << figName << " do bazy (ID figury: " << howManyAdded << ")" << endl;
	    break;

    case 'D':
        cout << "Podaj nazwe kwadratu: ";
        cin >> figName;
        cout << "Podaj cztery wspolrzedne (x,y) wierzcholkow kwadratu " << figName << " w formacie: x y" << endl;
        cout << "(Ex. Dla danych wejsciowych 0 0 2 0 2 2 0 2 otrzymamy kwadrat o wierzcholkach (0,0), (2,0), (2,2) i (0,2))" << endl;
        cin >> a >> b >> c >> d;
        f[howManyAdded++] = new Square(a,b,c,d,figName);
        cout << "Pomyslnie dodano kwadrat " << figName << " do bazy (ID figury: " << howManyAdded << ")" << endl;
        break;

    case 'E':
        cout << "Podaj nazwe elipsy: ";
        cin >> figName;
        cout << "Podaj dwie dlugosci a, b polosi elipsy " << figName << " w formacie: a b" << endl;
        cout << "(Ex. Dla danych wejsciowych 3 5 otrzymamy elipse o srodku w poczatku ukladu wspolrzednych i polosiach dlugosci 3 i 5" << endl;
        cout << "     Inaczej: otrzymamy elipse o rownaniu x^2 / 3 + y^2 / 5 <= 1)" << endl;
        cin >> p >> q;
        f[howManyAdded++] = new Ellipse(p,q,figName);
        cout << "Pomyslnie dodano elipse " << figName << " do bazy (ID figury: " << howManyAdded << ")" << endl;
        break;

    case 'F':
        cout << "Podaj nazwe kola: ";
        cin >> figName;
        cout << "Podaj srodek kola " << figName << " (jako wspolrzedne (x,y) punktu) i jego promien r w formacie: x y r" << endl;
        cout << "(Ex. Dla danych wejsciowych 2 4 6 otrzymamy kolo o srodku w punkcie (2,4) i promieniu 6" << endl;
        cout << "     Inaczej: otrzymamy kolo o rownaniu (x-2)^2 + (y-4)^2 <= 36)" << endl;
        cin >> a >> r;
        f[howManyAdded++] = new Circle(a,r,figName);
        cout << "Pomyslnie dodano kolo " << figName << " do bazy (ID figury: " << howManyAdded << ")" << endl;
        break;

    case 'G':
        cout << "Podaj nazwe wielokata foremnego: ";
        cin >> figName;
        cout << "Podaj liczbe bokow n i dlugosc d jednego z bokow wielokata foremnego " << figName << " w formacie: n d" << endl;
        cout << "(Ex. Dla danych wejsciowych 6 3 otrzymamy szesciokat foremny o boku dlugosci 3)" << endl;
        cin >> x >> p;
        f[howManyAdded++] = new RegularPolygon(x,p,figName);
        cout << "Pomyslnie dodano wielokat foremny " << figName << " do bazy (ID figury: " << howManyAdded << ")" << endl;
        break;

    default:
        cout << "Nieznane polecenie!" << endl;
        break;
    }
}

/* Wyswietl informacje o figurze na ekran */
void showFigure(){
    int whichFig;
    cout << "Informacje o ktorej figurze chcesz wyswietlic? Podaj ID figury: ";
    cin >> whichFig;
    cout << endl;
    if(whichFig>=HOW_MANY_FIGS){
        cout << "BLAD! ID moze osiagnac maksymalnie wartosc " << HOW_MANY_FIGS << endl;
        return;
    }
    else{
        if(whichFig>=1 && whichFig<=howManyAdded){
            f[whichFig-1]->showInfo();
        }
        else{
            cout << "BLAD! Nie ma figury o ID rownym " << whichFig << endl;
        }
    }
}

int main(){

    while(1){
        contents();
        cin >> mode;
        cout << endl;

        switch(mode){
        case 1:
            if(howManyAdded >= HOW_MANY_FIGS)
                cout << "BLAD! Maksymalnie mozesz dodac do bazy " << HOW_MANY_FIGS << " figur!" << endl;
            else
                addFigure();
            break;
        case 2:
            showFigure();
            break;
        case 3:
            cout << "Do zobaczenia! Milego dnia :)" << endl;
            exit(0);
            break;
        default:
            cout << "Nieznane polecenie!" << endl;
            break;
        }
    }

    return 0;
}