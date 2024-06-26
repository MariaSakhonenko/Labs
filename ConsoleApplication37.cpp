#include "Element1.h"
#include "Element2.h"
#include "Element3.h"
#include "MASSIV.h"

#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    
    MASSIV<Element1> array1;
    // Ваш код для заполнения массива Element1

    MASSIV<Element2> array2;
    // Ваш код для заполнения массива Element2

    // Выполнение пересечения массивов Element1 и Element2
    MASSIV<Element3> intersection;
    for (int i = 0; i < array1.getSize(); ++i) 
    {
        for (int j = 0; j < array2.getSize(); ++j)
        {
            if (strcmp(array1[i].Name, array2[j].Name) == 0) 
            {
                // Если студент присутствует в обоих массивах, добавляем его в результат
                Element3 commonElement(array1[i].Name, array1[i].SredniBal, array1[i].kurs);
                intersection.addElement(commonElement);
                break; // Переходим к следующему студенту из array1
            }
        }
    }

    // Сортировка массива Element3 по полю SredniBal
    for (int i = 0; i < intersection.getSize(); ++i) 
    {
        for (int j = i + 1; j < intersection.getSize(); ++j) 
        {
            if (intersection[i].SredniBal > intersection[j].SredniBal)
            {
                swap(intersection[i], intersection[j]);
            }
        }
    }

    // Ввод значения К с консоли
    int K;
    cout << "Введите значение K: ";
    cin >> K;

    // Фильтрация студентов среди отличников с средним баллом больше К
    MASSIV<Element3> filteredArray;
    for (int i = 0; i < intersection.getSize(); ++i) 
    {
        if (intersection[i].SredniBal > K) 
        {
            filteredArray.addElement(intersection[i]);
        }
    }

    // Вывод результата
    cout << "Результаты пересечения и сортировки:\n";
    for (int i = 0; i < filteredArray.getSize(); ++i) 
    {
        cout << filteredArray[i] << endl;
    }

    return 0;
}
