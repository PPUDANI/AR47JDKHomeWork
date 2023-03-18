
#include <iostream>

// 문자열을 넣어주면 글자 개수를 알아냅니다.
// 0을 포함할지 아닐지는 스스로 정하자.
// 영어만 써야함.
int StringCount(const char* _String)
{
	int count = 0;
	while ('\0' != _String[count])
	{
		count++;
	}
	return count;
}

// 공백 제거 함수
int TrimDelete(char* _String)
{
	int count = 0;
	while (0 != _String[count])
	{
		if (' ' != _String[count])
		{
			putchar(_String[count]);
		}
		count++;
	}
	putchar('\n');
	return 0;
}


// 문자열을 정수형으로 형변환해주는 함수 (중첩 while)
int StringToInt(const char* _String)
{
	int num = StringCount(_String);
	int Value = 0;
	int count = 0;
	while (count < num)
	{
		int a = _String[count] - 48;
		int loop = num - count;

		while (--loop)
		{
			a *= 10;
		}

		Value += a;
		count++;
	}
	return Value;
}

// 문자열을 정수형으로 형변환해주는 함수 (중첩 while X)
int StringToInt2(const char* _String)
{
	int count = 0;
	int length = StringCount(_String);
	int Value = 0;
	while (count < length) {
		int num = _String[count] - 48;
		Value = (Value + num) * 10;
		count++;
	}
	return Value / 10;
}

int main()
{
	int Return = StringCount("sdfasfaghasdasasf");

	printf_s("문자열 길이 : %d\n\n", Return);

	char Arr0[1024] = "a b c d e";
	char Arr1[1024] = "a  b c  d   e";
	char Arr2[1024] = "a b  cd e";

	printf_s("Arr0 : ");
	TrimDelete(Arr0);

	printf_s("Arr1 : ");
	TrimDelete(Arr1);

	printf_s("Arr2 : ");
	TrimDelete(Arr2);

	int RValue0 = StringToInt("12624254");
	printf_s("\nRValue : %d\n", RValue0);

	RValue0 = StringToInt2("12624254");
	printf_s("\nRValue : %d\n", RValue0);
}