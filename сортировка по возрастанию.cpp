#include <time.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int a[100], n;
	cout << "enter n" << endl;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; i < n - 1; j++)
		{
			if (a[j] < a[j + 1])
			{
				swap(a[j], a[j+1])
			}
		}
	}
}