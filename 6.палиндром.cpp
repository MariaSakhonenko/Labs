#include <iostream>
using namespace std;
int reverse_number(int number)
{
    int n = 0;
    while (number)
    {
        n = 10 * n + number % 10;
        number /= 10;
    }
    return n;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int number;
    cout << "Введите целое число" << endl;
    cin >> number;
    if (number == reverse_number(number))
        cout << "Палиндром" << endl;
    else
        cout << "Не палиндром" << endl;
    return 0;
}