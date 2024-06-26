#include "Element1.h"
#include <iostream>
using namespace std;


    Element1::Element1() : SredniBal(0), kurs(0) 
    {
        memset(Name, 0, sizeof(Name));
    }

    Element1::~Element1() {};

    Element1::Element1(const char* name, int av, int k) : SredniBal(av), kurs(k) 
    {
        strncpy(Name, name, sizeof(Name) - 1);
        Name[sizeof(Name) - 1] = '\0';
    }

     istream& operator>>(istream& inp, Element1& obj) 
     {
        inp.getline(obj.Name, sizeof(obj.Name));
        inp >> obj.SredniBal;
        inp >> obj.kurs;
        return inp;
    }

     ostream& operator<<(ostream& out, const Element1& obj) 
     {
        out << "Name: " << obj.Name << ", SredniBal: " << obj.SredniBal << ", kurs: " << obj.kurs;
        return out;
    }



     Element1& Element1::operator=(const Element1& other) 
     {
        if (this != &other) 
        {
            strncpy(Name, other.Name, sizeof(Name));
            SredniBal = other.SredniBal;
            kurs = other.kurs;
        }
        return *this;
    }
    bool Element1::operator== (const Element1& other) const 
    {
        return strncmp(Name, other.Name, sizeof(Name)) == 0 && SredniBal == other.SredniBal && kurs == other.kurs;
    }

