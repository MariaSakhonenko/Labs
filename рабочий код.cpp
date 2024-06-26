#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	double x, k, y, f, x2, e, res;
	cout << "Введите значения x, k" << endl;
	cin >> x >> k;
	x2 = (-1) * pow(x, 2);
	e = pow(10, -k);
	y = x;
	res = x;
	f = 2;
	while (abs(y) > 0)
	{
		y = (y * x2) / (f*(f+1));
		f += 2;
		res = y + res;
	}
	cout << "Результат: " << res << endl;
	cout << "Синус: " << sin(x);
	return 0;
}