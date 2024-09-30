/*
Done by: me
Student Name: Illya Maksemchuk
Student Group: 121
Pr2_2

*/
// 2. Задано множину послідовностей значень A[m,n].
// Замінити в кожній послідовності A[i] мінімальні значення на
// суму елементів цієї послідовності

// 3. Задано дві послідовності значень A[n] і B[m]. Замінити
// в A[n] входження значень із B[m] на добуток елементів
// підпослідовності B[m].

// 4. Задано множину послідовностей значень A[m,m].
// Замінити в кожному стовпці множини A[m,m] максимальні
// значення на добуток елементів цього стовпця.
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int creatNum(int &num, char letter)
{
	cout << "Enter number " << letter << " : ";
	cin >> num;
	return num;
}

vector<vector<int>> creat2DVec(int &num1, int &num2)
{
	vector<vector<int>> vec(num1, vector<int>(num2));
	for (int i = 0; i < num1; i++)
	{
		for (int j = 0; j < num2; j++)
		{
			int rand_num = rand() % 200 - 100;
			vec[i][j] = rand_num;
		}
	}
	return vec;
}

vector<int> creatVec(int &len)
{
	vector<int> vec(len);
	for (int i = 0; i < len; i++)
	{
		vec[i] = rand() % 200 - 100;
	}
	return vec;
}

void print2DVector(const vector<vector<int>> &vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
		{
			cout << setw(4) << vec[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

vector<vector<int>> MinToSum(vector<vector<int>> &vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		int sum = 0;
		int min = vec[i][0];

		for (int j = 0; j < vec[i].size(); j++)
		{
			sum += vec[i][j];
			if (min > vec[i][j])
				min = vec[i][j];
		}
		for (int k = 0; k < vec[i].size(); k++)
		{
			if (vec[i][k] == min)
			{
				vec[i][k] = sum;
				cout << "Has been changed" << "[" << i << "]" << "[" << k << "]" << endl;
			}
		}
	}
	return vec;
}

int main()
{
	{
		int m = creatNum(m, 'm');
		int n = creatNum(n, 'n');

		vector<vector<int>> A = creat2DVec(m, n);
		print2DVector(A);
		A = MinToSum(A);
		print2DVector(A);
	}

	{
		int mult = 1;
		bool check = true;
		int m = creatNum(m, 'm');
		int n = creatNum(n, 'n');

		vector<int> A = creatVec(m);
		vector<int> B = creatVec(n);

		for (int i = 0; i < B.size(); i++)
			mult *= B[i];

		for (int i = 0; i < A.size(); i++)
			for (int j = 0; j < B.size(); j++)
			{
				if (A[i] == B[j])
				{
					A[i] = mult;
					check = false;
					cout << "Mathes are in " << "A[" << i << "]" << "B[" << j << "]" << endl;
				}
			}
		if (check)
			cout << "In arrays no mathes" << endl;
		else
			for (int temp : A)
				cout << temp << " ";
		cout << endl;
		for (int temp : B)
			cout << temp << " ";
	}
}