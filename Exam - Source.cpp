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
	cout << "b >> c >> d: ";
	double iTemp;
	cin >> iTemp >> b >> c >> d;
	i = iTemp;

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


		fld i
		fadd _1
		fstp i

		mov eax, q
		sub eax, ecx
		fstp res[eax*8]
		fstp w

		loop start
	}

	for (int j = 0;j < q;++j)
	{
		cout << res[j] << " ";
	}
	cout << endl;
	for (int j = 0;j < q;++j)
	{
		ai = (3 * b + c / 3)*(iTemp++);
		cout << (2 * c + tan(ai - b)) / (c / ai + d + 1) << " ";
	}
	system("pause");
}