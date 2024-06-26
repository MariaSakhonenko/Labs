#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "russian");
	unsigned int y, x, a, b;
	cout << "Enter y, x" << endl;
	cin >> y >> x;
	a = x;
	b = y;
	while (x != y && x > 0 && y > 0)
	{
		if (x > y)
		{
			x = x % y;
		}
		else
		{
			y = y % x;
		}
	}
	cout << "мнд=" << x << endl;
	y = (a * b) / x;
	cout << "мнй=" << y;
	return 0;
}