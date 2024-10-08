#include <iostream>
#include <vector>
#include <string>
#include <random>

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
	int n = 5;
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
	// Добавление ствола дерева
	int lastRowLength = vec.back().length(); // Length of the last row (widest row)
	int trnkAvg = (((lastRowLength - 1) / 2) - (18 * (n - 1))) - 4;
	for (int i = 0; i < n; i++) // Ствол из 2-х строк
	{
		string trunk = string(trnkAvg, ' ') + "\033[2;33m*\033[0m"; // Пробелы перед стволом
		vec.push_back(trunk);
	}
	// Вывод всей ёлки, сохранённой в векторе
	cout << "\n\n";
	print2DVec(vec);
	cout << test;
	return 0;
}
