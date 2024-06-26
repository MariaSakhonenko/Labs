#include <iostream>
using namespace std;
int main() 
    {
    setlocale(LC_ALL, "Russian");
    int n, i;
    cout << "Введите целое число" << endl;
    bool prime = true;
    cin >> n;
    if (n<=1)
    {
        cout << "ОШИБККАА";
    }
    else 
    {
        for (i = 2; i <= abs(n) / 2; i++) 
        {
            if (n % i == 0) 
            { 
                prime = false; break;
            }
        }
        if (prime) cout << "Простое";
        else cout << "Составное";
    }
    return 0;
}