
#include <iostream>
#include <fstream>

#pragma once
#ifndef Element2_h
#define Element2_h

struct Element2 {
    char Name[50];
    int kurs;
    char Space[50];

    Element2();
    Element2(const char* name, const char* space, int k);
    ~Element2();

    friend std::istream& operator>>(std::istream& inp, Element2& obj);
    friend std::ostream& operator<<(std::ostream& out, const Element2& obj);

    Element2& operator=(const Element2& other);
    bool operator==(const Element2& other) const;
};


#endif