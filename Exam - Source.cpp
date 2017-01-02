#include <iostream>

using namespace std;

void main()
{
	double ai = 1.3;
	double b = 1.2;
	double c = 5.1;
	double d = 6.7;
	double i = 1;
	const int q = 5;
	double res[q];
	double _3 = 3;
	double _2 = 2;
	double _1 = 1;
	double w;

	__asm
	{
		mov ecx, q
			start:
		fld b
		fmul _3
		fld c
		fdiv _3
		faddp st(1), st(0)
		fmul i
		fstp ai

		fld i
		fadd _1
		fstp ai
		loop start
	}

	cout << (3 * b + c / 3)*1 << endl;
	system("pause");
}