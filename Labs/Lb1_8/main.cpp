#include <iostream>

using namespace std;
// 1. Перевірка парності числа
// 2. Підрахунок кількості одиничних бітів
// 3. Перевірка встановленого біта на певній позиції
int main()

{
	{
		// Задачі 1
		int cou = 0;
		int num;
		cout << "Enter int num: ";
		cin >> num;
		if (num % 2 == 0)
			cout << "The number is paired" << endl;
		else
			cout << "The number isn`t paired" << endl;
		// Кінець

		// Задача 2
		while (num >= 1)
		{
			if (num % 2 == 1)
				cou++;
			num /= 2;
		}
		cout << "Amout of 1: " << cou << endl;
		// Кінець
	}
	{
		// Задача 3
		int num;
		cout << "Enter num: ";
		cin >> num;

		int indx;
		cout << "Enter index of bit u wanna check ";
		cin >> indx;

		int mask = 1 << indx;
		cout << "On position " << indx << " : " << bool(num & mask) << endl;
	}
	return 0;
}