
#include <iostream>

inline int MyPrintf(const char* const _Value, ...)
{
	__int64 Address = (__int64)&_Value;
	int count = 0;
	while ('\0' != _Value[count])
	{
		if (_Value[count] == '%')
		{
			Address += 8;
			switch (_Value[++count])
			{

			case 'd':
			{
				int* DecAddress = (int*)Address;
				printf_s("%d", *DecAddress);

				break;
			}
			case 's':
				break;

			default:
				break;
			}
		}
		else
		{
			putchar(_Value[count]);
		}

		count++;
	}
	return 0;
}

void Test(int _1, int, int)
{
	__int64 Address = (__int64) & _1;

	Address += 8;
	int* _2 = (int*)Address;

	Address += 8;
	int* _3 = (int*)Address;
	
}
int main()
{
	// Test(10, 20, 30);
	MyPrintf("Decimal : %d, %d, %d, %d, %d\n", 1, 5, 4, 6, 2);
}

