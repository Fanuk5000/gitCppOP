#include <iostream>
/*
Done by: me
Student Name: Illya Maksemchuk
Student Group: 121
Lb1_6

*/

using namespace std;

void printValue(void *ptr, char type)
{
	if (type == 'i')
	{
		int *intPtr = (int *)ptr;
		cout << "Int value: " << *intPtr << endl;
	}
	else if (type == 'f')
	{
		cout << "Float value: " << *(float *)ptr << endl;
	}
	else if (type == 'c')
	{
		cout << "Unsigned short: " << *(unsigned short *)ptr << endl;
	}
	else
	{
		cout << "Unknown type" << endl;
	}
}

// 1. Опису змінних символьного типу.
// 2. Опису констант символьного типу.
// 3. Ініціювання об'єктів при опису.
// 4. Ініціювання об'єктів оператором привласнення, використовуючи значення з варіанта (табл.
// 14), які наведені у вигляді символьних літералів та кодів символів.
int main()
{
	{
		const char CONST1 = '1';
		char chVar1 = 'p';
		char chVar2 = 'N';

		const char CONST2 = 0x7a;
		char chVar3 = 0x3b;
		char chVar4 = 0x9;

		cout << "CONST1: " << CONST1 << endl;
		cout << "chVar1: " << chVar1 << endl;
		cout << "chVar2: " << chVar2 << endl;

		cout << "CONST2: " << CONST2 << endl;
		cout << "chVar3 " << chVar3 << endl;
		cout << "chVar4" << chVar4 << endl;
	}
	// 1. Опису змінних наступних типів: int, float, unsigned short.
	// 2. Ініціювання змінних, що описанні в п.1 даного завдання, значеннями згідно з варіантом
	// (табл.15).
	// 3. Опису змінних наступних типів: double, int, char.
	// 4. Ініціювання змінних, що описанні в п.3 даного завдання, використовуючи змінні, що описанні
	// в п.1 даного завдання, за допомогою:
	//  неявного приведення типів;
	//  явного приведення типів;
	//  механізму обходу суворої типізації
	{
		cout << endl;

		int intValue = 3841;
		float floatValue = 954.67f;
		unsigned short unsignShort = 6429;
		string testValue = "text";

		void *voidPtr;

		voidPtr = &intValue;
		printValue(voidPtr, 'i');

		voidPtr = &floatValue;
		printValue(voidPtr, 'f');

		voidPtr = &unsignShort;
		printValue(voidPtr, 'c');

		voidPtr = &testValue;
		printValue(voidPtr, 's');
	}
	return 0;
}