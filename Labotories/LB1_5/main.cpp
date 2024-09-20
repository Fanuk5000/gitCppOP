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
		cout << "res: " << boolalpha << res << endl;
	}

	{
		float a = 85;
		float b = 85;
		float c = 6.4;
		float d = 9.3;

		// <УЛО1> (<УЛО2> (A<ОВ1>B) <БЛО> (<УЛО3> (C<ОВ2>D)))
		//  empty ( !     (a - b))   ^  (    -     (a < b)))
		bool res = ((!(a - b)) ^ (-(a < b)));
		cout << "res: " << boolalpha << res << endl;
	}

	return 0;
}