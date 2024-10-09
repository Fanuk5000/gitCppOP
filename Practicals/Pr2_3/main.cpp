/*
Done by: me
Student Name: Illya Maksemchuk
Student Group: 121
Pr2_3
*/

// 2. Задано послідовність значень A[n]. Сформувати нову
// послідовність B[m] з від’ємних значень послідовності A[n] та
// відсортувати її за спаданням алгоритмом вибірки.

// 3. Задано множину послідовностей A[m,n], де m – номер
// послідовності, а n – кількість елементів у m-ій послідовності.
// Відсортувати кожну послідовність за зростанням алгоритмом
// бульбашки.

// 6. Задано матрицю A[m,n]. Відсортувати кожен стовпець
// за спаданням алгоритмом бульбашки.
#include <fstream>
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

vector<int> creatVec(int &len)
{
	srand(time(0));
	vector<int> vec(len);
	for (int i = 0; i < len; i++)
		vec[i] = rand() % 200 - 100;
	return vec;
}
int creatNum(int &num, char letter)
{
	cout << "Enter number " << letter << " : ";
	cin >> num;
	return num;
}
void printVec(vector<int> &vec)
{
	for (int temp : vec)
		cout << temp << " ";
	cout << endl;
}
int main()
{

	int n = creatNum(n, 'n');
	vector<int> vecA = creatVec(n);
	vector<int> vecB(n);

	printVec(vecA);

	for (int i = 0; i < n; i++)
	{
		if (vecA[i] < 0)
			vecB[i] = vecA[i];
	}
	for (int i = 0; i < n; i++)
	{
		auto mint = min_element(vecA.begin(), vecA.end());
		auto maxt = max_element(vecA.begin(), vecA.end());

		int min = *mint;
		int max = *maxt;

		vecB.push_back(min);
		vecB.insert(vecB.begin(), max);

		vecA.erase(mint);
		vecA.erase(maxt);
	}
	cout << "Vector B: ";
	printVec(vecB);
	return 0;
}