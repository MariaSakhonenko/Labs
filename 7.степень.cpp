#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    double x, n, a, h; int c;
    cout << "������� ����� � ���������� �������" << endl;
    cin >> x >> n;
    c = 1 / n;
    h = c % 2;
    if (x == 0 && n == 0)
    {
        cout << "������ ������";
    }
    else if (x < 0 && h == 0)
    {
        cout << "��������" << endl;
    }
    else
    {
        a = pow(x, n);
        cout << "X^n=" << a;
    }
    return 0;
}