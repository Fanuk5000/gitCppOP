#include <iostream>

using namespace std;

int main()
{
	int cou = 0;
	int a[] = {1, 2, 3};
	for (int i = 0; i < 3; i++)
	{
		cout << a[i] << " ";
	}
	int mask = *a;
	cout << endl;
	cout << mask << endl;
}