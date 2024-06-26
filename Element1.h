#include <iostream>
#include <fstream>
using namespace std;
#pragma once
#ifndef Element1_h
#define Element1_h


struct Element1 
{
    char Name[50];
    int kurs;
    int SredniBal;

    Element1();
    Element1(const char* name, int av, int k);
    ~Element1();

    friend istream& operator>>(istream& inp, Element1& obj);
    friend ostream& operator<<(ostream& out, const Element1& obj);

    Element1& operator=(const Element1& other);
    bool operator==(const Element1& other) const;
};


#endif