#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	long int l, n;
	cout << "������� ����� �������� ���������" << endl;
	cin >> l;
	cout << "������� ������ ��������" << endl;
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