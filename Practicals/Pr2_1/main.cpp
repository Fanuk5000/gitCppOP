/*
Done by: me
Student Name: Illya Maksemchuk
Student Group: 121
Pr2_1

*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <format>

using namespace std;
int creatNum(int &num, char letter)
{
	// static int cou = 1;
	// char res;
	// if (cou == 1)
	// 	res = 'm';
	// else
	// {
	// 	res = 'n';
	// 	cou = 1;
	// }
	cout << "Enter number " << letter << " : ";
	cin >> num;
	// cou++;
	return num;
}

vector<vector<int>> creatVec(vector<vector<int>> &vec, int &num1, int &num2)
{
	for (int i = 0; i < num1; i++)
	{
		for (int j = 0; j < num2; j++)
		{
			int rand_num = rand() % 100 - 50;
			vec[i][j] = rand_num;
		}
	}
	return vec;
}

void print2DVector(const vector<vector<int>> &vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec.size(); j++)
		{
			cout << setw(4) << vec[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int findMinfrom2DArr(const vector<vector<int>> &vec)
{
	int minNum = vec[0][0];
	for (int i = 0; i < vec.size(); i++)
		for (int j = 0; j < vec.size(); j++)
			if (vec[i][j] < minNum)
				minNum = vec[i][j];
	return minNum;
}

int main()
{
	{
		// 2. Задано множину послідовностей значень
		//  A[m,n]A[m,n]A[m,n], де m – номер послідовності, а n – кількість
		//  елементів у m-тій послідовності. Знайти індекси розміщення
		//  мінімального значення в множині.
		srand(time(0));

		int m = creatNum(m, 'm');
		int n = creatNum(n, 'n');
		vector<vector<int>> A = creatVec(A, m, n);
		// vector<vector<int>> A(m, vector<int>(n));
		// for (int i = 0; i < m; i++)
		// {
		// 	for (int j = 0; j < n; j++)
		// 	{
		// 		int rand_num = rand() % 100 - 50;
		// 		A[i][j] = rand_num;
		// 	}
		// }
		cout << A[0][0] << endl;
		print2DVector(A);
		int mins = findMinfrom2DArr(A);
		cout << "The minimal num from 2D arr is: " << mins << endl;
		return 0;
	}
	{
		// 3. Задано множину послідовностей значень
		//  A[m,n]A[m,n]A[m,n], де m – номер послідовності, а n – кількість
		//  елементів у m-тій послідовності. Знайти максимальне від’ємне
		//  значення в множині
		srand(time(0));

		int m = creatNum(m, 'm');
		int n = creatNum(n, 'n');
	}
}