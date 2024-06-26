#include <iostream>
using namespace std;
int main() 

{
	setlocale(LC_ALL, "ru");
	 int a;
	cout << "Enter a != 0" << endl;
	cin >> a;
	if (a == 0)
		system("pause");
	else
	{
		int power = 0, ispower = 0;
		if (a < 0)
			a *= -1;
		_asm
		{
			mov edx, 1
			mov ebx, a
			mov ecx, 1
			mov eax, a
			loop1:

			cmp eax, 0
			je endloop
			add power, 1
			shr eax, 1
			mov ebx, eax
			and ebx, ecx
			
			cmp ebx, edx
			je ift
			jmp loop1
			

			ift:
			cmp ispower, 1
			je iff
			mov ispower, 1
			jmp loop1

			iff:
			mov ispower, 0
			endloop: nop
		};
		if (!ispower) {
			cout << "не степень 2";
		}
		else {
			cout << "степень: " << power - 1;
		}

	}
	return 0;
}