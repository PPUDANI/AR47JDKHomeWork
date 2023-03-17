
#include <iostream>

inline int MyPrintf(const char* const _Value, ...)
{
	//const char* Ptr = _Value;
	//int Value1 = Ptr[2];

	__int64 Address = (__int64)&_Value;
	char* Ptr = (char*)Address;
	Ptr += 8;
	int* IntPtr = (int*)Ptr;
	int Value0 = *IntPtr;

	return 0;

	int Count = 0;
	while (0 != _Value[Count])
	{
		char Value = _Value[Count];
		

		if ('%' != Value)
		{
			putchar(Value);
		}
		else
		{
			
			char Format = _Value[Count + 1];
			switch (Format)
			{
			case 'd':

				break;
			case 's':

				break;
			default:

				break;
			}
			
		}
		Count++;
	}
	return 0;
}
int main()
{
	MyPrintf("abcdefg %d", 1);
}

