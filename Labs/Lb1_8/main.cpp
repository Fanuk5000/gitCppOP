#include <iostream>

using namespace std;
// 1. Перевірка парності числа
// 2. Підрахунок кількості одиничних бітів
// 3. Перевірка встановленого біта на певній позиції
int main()

{

	{
		// Задача 1: перевірка на парність
		int count = 0;
		int num;
		cout << "Enter int num: ";
		cin >> num;

		if (num & 1)
			cout << "The number is odd" << endl; // не парне
		else
			cout << "The number is even" << endl; // парне

		// Задача 2: підрахунок кількості 1 у двійковому поданні
		while (num > 0)
		{
			count += (num & 1);
			num >>= 1;
		}
		cout << "Amount of 1: " << count << endl;
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