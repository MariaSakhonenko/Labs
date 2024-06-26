#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Enter n" << endl;
	cin >> n;
	int sum = 0;
	n = abs(n);
	while (n != 0)
	{
		sum += n % 10;
		n /= 10;
	}
	cout << "Сумма равна " << sum;
	return 0;
}