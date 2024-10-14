#include <iostream>

using namespace std;
// 1. Перевірка парності числа
// 2. Підрахунок кількості одиничних бітів
// 3. Перевірка встановленого біта на певній позиції
int main()

{

	{
		// Задача 1: перевірка на парність
		int cou = 0;
		int num;
		cout << "Enter int num: ";
		cin >> num;

		if (num & 1)
			cout << "The number isn`t paired" << endl;
		else
			cout << "The number is paired" << endl;

		// Задача 2: підрахунок кількості 1 у двійковому поданні
		while (num > 0)
		{
			cou += (num & 1);
			num >>= 1;
		}
		cout << "Amount of 1: " << cou << endl;
	}
	{
		// Задача 3
		int num;
		cout << "Enter num: ";
		cin >> num;

		int indx;
		cout << "Enter index of bit u wanna check: ";
		cin >> indx;

		int mask = 1 << indx;
		cout << "On position " << indx << " : " << bool(num & mask) << endl;
	}
	return 0;
}