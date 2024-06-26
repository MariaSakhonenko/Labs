#include <iostream>
using namespace std;
int main()
{
	char b = 0, w = 1;
	const int r = 10;
	int Main[r][r];
	for (int i = 0; i < r; i++) 
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < r; j++) 
			{
				if (j % 2 == 0)
					Main[i][i] = 1;
				else
					Main[i][i] = 0;
				cout << Main[i][i] << " ";
			}
		}
		else
		{
			for (int j = 0; j < r; j++)
			{
				if (j % 2 != 0)
					Main[i][i] = 1;
				else
					Main[i][i] = 0;
				cout << Main[i][i] << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
