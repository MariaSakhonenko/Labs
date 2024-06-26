/*
Задание: Вычисления выполнить на Assembler в среде MS Visio С++, ввод данных и вывод результатов, осуществлять на С++.
Вычислить значение  выражения на С++ и Ассемблере используя целые значения (int) переменных.
Обязательные операции на ассемблере : +, -, *, /.
Для проверки результата, вычислить выражение и на С++.
Y=(25*b +4ac +xa^2 /2) / (3x^2 –(b/(7a) +a))
*/
#include <iostream>
#include <cmath>
using namespace std;

extern "C" int	_cdecl _Equation(int a, int b, int c1, int x, int r, int s, int res  );


int solve(int a, int b, int c1, int x, int r, int s, int res)
{
    
    if (a != 0 && (3 * x * x - b / (7 * a) + a) != 0)
    {
        res = 0;
        res = _Equation(a, b, c1, x, r, s, res);
        return res;
    }
    else
    {
        // exit(EXIT_FAILURE);
        cout << "Your IQ is ";
        return -1;
    }
}
int  _cdecl imul1(int b)
{
    return  25 * b;
}

int main()
{
    int a, b, c1, x;
    int r = 0, s = 0, res = 0;
  
    setlocale(LC_ALL, ".1251");
    cout << "Input a, b, c, x " << endl;
    cin >> a >> b >> c1 >> x;
    cout << "a: " << a << "     b:" << b << "     c:" << c1 << "     x:" << x << endl;
    cout << "Y = (25b +4ac +x*a^2 /2) / (3x^2 –(b/(7a) +a))" << endl;
    cout << "Result: " << solve(a, b, c1, x, r, s, res) << '\n';

    int p;
    
    _asm
    {
        push b
        call imul1
        pop edx
        mov b, eax
    }
    cout << "p = 25*b = " << b << endl;
    system("pause");
    
    return 0;
}





   