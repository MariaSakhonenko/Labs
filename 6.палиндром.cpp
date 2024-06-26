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
    cout << "������� ����� �����" << endl;
    cin >> number;
    if (number == reverse_number(number))
        cout << "���������" << endl;
    else
        cout << "�� ���������" << endl;
    return 0;
}