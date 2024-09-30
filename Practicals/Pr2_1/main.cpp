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
	cout << "Enter number " << letter << " : ";
	cin >> num;
	return num;
}

vector<vector<int>> creatVec(int &num1, int &num2)
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
// min
int findMinfrom2DArr(const vector<vector<int>> &vec)
{
	int minNum = vec[0][0];
	for (int i = 0; i < vec.size(); i++)
		for (int j = 0; j < vec.size(); j++)
			if (vec[i][j] < minNum)
				minNum = vec[i][j];
	return minNum;
}
//<0 max
int findMMaxfrom2DArr(const vector<vector<int>> &vec)
{
	int maxNum = -9999;
	for (int i = 0; i < vec.size(); i++)
		for (int j = 0; j < vec[i].size(); j++)
			if (vec[i][j] > maxNum and vec[i][j] < 0)
				maxNum = vec[i][j];
	return maxNum;
}
//>0 min
int findMMinfrom2DArr(const vector<vector<int>> &vec)
{
	int minNum = 9999;
	for (int i = 0; i < vec.size(); i++)
		for (int j = 0; j < vec[i].size(); j++)
			if (vec[i][j] < minNum and vec[i][j] > 0)
				minNum = vec[i][j];
	return minNum;
}
// 2. Задано множину послідовностей значень
//  A[m,n]A[m,n]A[m,n], де m – номер послідовності, а n – кількість
//  елементів у m-тій послідовності. Знайти індекси розміщення
//  мінімального значення в множині.

// 3. Задано множину послідовностей значень
// A[m,n]A[m,n]A[m,n], де m – номер послідовності, а n – кількість
// елементів у m-тій послідовності. Знайти максимальне від’ємне
// значення в множині.

// 4. Задано множину послідовностей значень
// A[m,n]A[m,n]A[m,n], де m – номер послідовності, а n – кількість
// елементів у m-тій послідовності. Знайти мінімальне додатне
// значення в множині.

int main()
{

	int m = creatNum(m, 'm');
	int n = creatNum(n, 'n');

	vector<vector<int>> A = creatVec(m, n);

	int mins = findMinfrom2DArr(A);
	int mmax = findMMaxfrom2DArr(A);
	int mmins = findMMinfrom2DArr(A);

	print2DVector(A);

	cout << "The minimal num from 2D arr is: " << mins << endl;
	cout << "The max <0 in 2D arr is: " << mmax << endl;
	cout << "The min >0 in 2D arr is: " << mmins << endl;
	return 0;
}
