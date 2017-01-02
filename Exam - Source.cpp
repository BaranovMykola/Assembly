#include <iostream>
#include <cmath>

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


	/*__asm
	{
		fld _1
		fld b
		fptan
		fdivp st(1), st(0)
		fstp w
	}*/
	/*cout << w << endl << tan(b) << endl << endl;*/
	
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

		fld _1
		fld ai
		fsub b
		fptan
		fdivp st(1), st(0)
		fld c
		fmul _2
		faddp st(1), st(0)
		//...

		fld c
		fdiv ai
		fadd d
		fadd _1
		fdivp st(1), st(0)

		fstp w

		/*fld i
		fadd _1
		fstp i*/
		//loop start
	}

	
	cout << w << endl;
	cout << (2*c+tan(ai-b)) / (c / ai + d + 1) << endl;
	system("pause");
}