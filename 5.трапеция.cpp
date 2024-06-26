#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	long int l, n;
	cout << "¬ведите длину верхнего основани€" << endl;
	cin >> l;
	cout << "¬ведите высоту трапеции" << endl;
	cin >> n;
	for (int j = 0; j < n; j++)
	{
		for (int i = l + j; i > 0; i--)
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}