#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "russian");
	long long x, f = 1;
	cout << "Enter x" << endl;
	cin >> x;
	if (x > 1)
	{
		for (int i = 1; i <= x; i++)
			f = f * i;
		cout << "f=" << f;
	}
	else if (x == 0 or x == 1)
	{
		cout << "1";
	}
	else
	{
		cout << "Решений нет";
	}
	return 0;
}