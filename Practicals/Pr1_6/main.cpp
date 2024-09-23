
/*
Done by: me
Student Name: Illya Maksemchuk
Student Group: 121
PR1_6

*/

// 1. Задано ціле значення А. Визначити, яких бітів (0 чи 1)
// більше в його двійковому поданні.

// 2. Задано дві послідовності, які складаються з 0 та 1.
// Скласти специфікацію для моделювання операцій XOR

#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int main()
{
	{
		int cou0 = 0;
		int cou1 = 0;

		int number;
		cout << "Enter you number";
		cin >> number;
		bitset<8> binary(number);
		string code = binary.to_string();

		cout << code << endl;

		for (int i = 0; i < code.length(); i++)
		{
			cout << code[i] << endl;
			if (code[i] == '0')
			{
				cou0 += 1;
			}
			else if (code[i] == '1')
			{
				cou1 += 1;
			}
		}
		if (cou0 > cou1)
		{
			cout << "In the number more 0 than 1" << endl;
		}
		else
		{
			cout << "In the number more 1 than 0" << endl;
		}
		return 0;
	}

	{
		int num1;
		cout << "Enter you number1";
		cin >> num1;
		int num2;
		cout << "Enter you number2";
		cin >> num2;
		}
}
