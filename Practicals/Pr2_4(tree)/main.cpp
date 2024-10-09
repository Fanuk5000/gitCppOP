/*
Done by: me
Student Name: Illya Maksemchuk
Student Group: 121
Pr2_4(tree)

*/
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <fstream>
#include <regex>

using namespace std;

/*

####*
###***
##*****
####*
###***
##*****
#*******
####*
###***
##*****
#*******
*********
	*
	*

*/

// ## Задача - Christmas Tree

// Основна вимоги (Закриється одна практична -> 2.3 або 2.4)
// Напишіть програму, яка отримує від користувача число n, що вказує кількість рівнів (шарів) ялинки. Програма повинна вивести ялинку з n рівнів у вигляді трикутників з зірочок (*). Кожен рівень ялинки складається з кількох рядків, де кількість зірочок збільшується від 1 до непарного числа, а також відображається стовбур.

// Додаткові вимоги (Закриваються дві практичні -> 2.3 i 2.4)
// + за використання двохвимірного масиву
// + за відмальовування ялинки в кольорі
// + за додавання в рандомних місцях ялинки іграшок (@, $, %, #)
// + за запис ялинки в файл - cristmas_tree.txt

// Advanced (2.2 i 2.3 i 2.4)
// + Зробити гірляду, в якій іграшки будуть вмикатись і вимикатись (колір іграшок змінюється).

// *Приклад виводу*

void print2DVec(const vector<string> &vec)
{
	for (const auto &row : vec)
	{
		cout << row << endl;
	}
}

int main()
{
	srand(time(0));
	const string a = "\033[31m@\033[0m";
	const string dola = "\033[37m$\033[0m";
	const string proc = "\033[34m%\033[0m";
	const string chn = "\033[33m#\033[0m";
	//@, $, %, #
	int n = 3; // n

	int couN = n;
	int couSpace = n;
	int couEnd = n - 1;
	int couStar = 1;

	// for (int i = 0; i < n; i++)
	// 	suma += n + i;

	vector<string> vec;

	// main cycle
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < couN; i++)
		{
			couSpace--;
			string row = "";

			// space
			for (int j = 0; j < couSpace + couEnd; j++)
			{
				row += " ";
			}
			// star
			for (int j = 0; j < couStar; j++)
			{
				int num = rand() % 11;
				if (num < 7)
					row += "\033[32m*\033[0m"; // green star
				else if (num == 7)
					row += a;
				else if (num == 8)
					row += dola;
				else if (num == 9)
					row += proc;
				else if (num == 10)
					row += chn;
			}
			vec.push_back(row);
			couStar += 2;
		}
		couEnd--;
		couStar = 1;
		couN++;
		couSpace = couN;
	}

	int lastRowLength = vec.back().length();
	int trnkAvg = (((lastRowLength - 1) / 2) - (18 * (n - 1))) - 4; // Don`t ask how I calculedet this, just a math
	for (int i = 0; i < n; i++)
	{
		string trunk = string(trnkAvg, ' ') + "\033[2;33m*\033[0m";
		vec.push_back(trunk);
	}

	cout << "\n\n";
	print2DVec(vec);
	fstream myfile;
	myfile.clear();
	myfile.open("tree.txt", ios::out);
	regex ansi_escape("\033\\[[0-9;]*m");
	for (const string &temp : vec)
	{
		string clean_temp = regex_replace(temp, ansi_escape, "");
		myfile << clean_temp << endl;
	}

	myfile.close();
	return 0;
}
