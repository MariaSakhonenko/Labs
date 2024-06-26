#include <iostream>
#include <fstream>
using namespace std;
#pragma once
#ifndef Element3_h
#define Element3_h


struct Element3 
{
    char Name[50];
    int kurs;
    int SredniBal;

    Element3();
    Element3(const char* name, int av, int k);
    ~Element3();

    friend istream& operator>>(istream& inp, Element3& obj);
    friend ostream& operator<<(ostream& out, const Element3& obj);

    Element3& operator=(const Element3& other);
    bool operator==(const Element3& other) const;
};
#endif

