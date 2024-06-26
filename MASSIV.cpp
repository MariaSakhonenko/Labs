/*#include "MASSIV.h"
#include <iostream>
#include <fstream>

template<typename T>
class MASSIV {
private:
    int size;
    T* data;

public:


    MASSIV(int s = 0) : size(s), data(new T[s]) {}

    MASSIV(const MASSIV& other) : size(other.size), data(new T[other.size]) {
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    ~MASSIV() {
        delete[] data;
    }


    int getSize() const {
        return size;
    }

    void addElement(const T& element) {
        T* newData = new T[size + 1];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        newData[size++] = element;
        delete[] data;
        data = newData;
    }

    friend std::istream& operator>>(std::istream& input, MASSIV<T>& obj) {
        for (int i = 0; i < obj.size; ++i) {
            input >> obj.data[i];
        }
        return input;
    }

    friend std::ostream& operator<<(std::ostream& output, const MASSIV<T>& obj) {
        for (int i = 0; i < obj.size; ++i) {
            output << obj.data[i] << std::endl;
        }
        return output;
    }

    void writeBinary(std::ofstream& file) {
        file.write(reinterpret_cast<const char*>(&size), sizeof(size));
        file.write(reinterpret_cast<const char*>(data), size * sizeof(T));
    }

    void readBinary(std::ifstream& file) {
        file.read(reinterpret_cast<char*>(&size), sizeof(size));
        delete[] data;
        data = new T[size];
        file.read(reinterpret_cast<char*>(data), size * sizeof(T));
    }

    T& operator[](int index) {
        if (index >= 0 && index < size) {
            return data[index];
        }
        else {
            throw std::out_of_range("Index out of range");
        }
    }

};
*/