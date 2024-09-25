/**
 * Done by: me
 * Student Name: Illya Maksemchuk
 * Student Group: 121
 * Lab 1.5
 */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	{
		float a = 5.8;
		float b = 39.1;
		float c = 70;
		float d = 42;
		// Variant 9
		//  <УЛО1> (<УЛО2> (A<ОВ1>B) <БЛО> (<УЛО3> (C<ОВ2>D)))
		//   empty ( !     (a - b))   ^  (    -     (a < b)))
		bool res = ((!(a - b)) ^ (-(a < b)));
		cout << "Result of 1: " << boolalpha << res << endl
			 << endl;
	}

	{
		float a = 85;
		float b = 85;
		float c = 6.4;
		float d = 9.3;

		// <УЛО1> (<УЛО2> (A<ОВ1>B) <БЛО> (<УЛО3> (C<ОВ2>D)))
		//  empty ( !     (a - b))   ^  (    -     (a < b)))
		bool res = ((!(a - b)) ^ (-(a < b)));
		cout << "Result of 2: " << boolalpha << res << endl
			 << endl;
	}

	{
		const int A = 49;
		int b = -65;
		int e = 2;

		int var = 13;
		int *c = &var;

		int d = 13;
		long f;
		// A <БО1> <УО> B <АО1> <СО> C <ОВ> D <АО2> E <БО2> <БазО> F
		// БО1 БО2 АО1 АО2 УО СО БазО ОВ
		// ^    <<  –   +   – * sizeof >=
		float res = (A ^ -b) - (*c >= d) + (e << sizeof(f));
		cout << "Result of computation: " << res << endl;
	}

	return 0;
}