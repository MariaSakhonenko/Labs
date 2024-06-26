#include "Element2.h"
#include <iostream>
using namespace std;


Element2::Element2() : kurs(0) 
{
    memset(Name, 0, sizeof(Name));
    memset(Space, 0, sizeof(Space));
}

Element2::~Element2() {};

Element2::Element2(const char* name, const char* space, int k) : kurs(k) 
{
    strncpy(Name, name, sizeof(Name) - 1);
    Name[sizeof(Name) - 1] = '\0';
    strncpy(Space, space, sizeof(Space) - 1);
    Name[sizeof(Space) - 1] = '\0';
}

     istream& operator>>(istream& inp, Element2& obj) 
     {
        inp.getline(obj.Name, sizeof(obj.Name));
        inp.getline(obj.Space, sizeof(obj.Space));
        inp >> obj.kurs;
        return inp;
     }

    ostream& operator<<(ostream& out, const Element2& obj) 
    {
        out << "Name: " << obj.Name << ", Space: " << obj.Space << ", kurs: " << obj.kurs;
        return out;
    }


    Element2& Element2::operator=(const Element2& other) 
    {
        if (this != &other) 
        {
            strncpy(Name, other.Name, sizeof(Name));
            strncpy(Space, other.Space, sizeof(Space));
            kurs = other.kurs;
        }
        return *this;
    }
    bool Element2::operator== (const Element2& other) const 
    {
        return strncmp(Name, other.Name, sizeof(Name)) == 0 && strncmp(Space, other.Space, sizeof(Space)) && kurs == other.kurs;
    }


