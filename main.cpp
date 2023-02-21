#include<stdio.h>
#include <stdexcept>
#include "Range.hpp"

int main(void)
{
	try
	{
		for (auto i : Range(32, 64, 8))//c++17自动推导，可省略<int>
		{
			printf("%d ", i);//从32开始到64（不包含64）步长为8 输出：32 40 48 56
		}

		putchar('\n');

		for (auto i : Range(32, 64))//c++17自动推导，可省略<int>
		{
			printf("%d ", i);//从32开始到64（不包含64）默认步长为1 输出：32 ~ 63
		}

		putchar('\n');

		for (auto i : Range(12))//c++17自动推导，可省略<int>
		{
			printf("%d ", i);//默认从0开始到12（不包含12）默认步长为1 输出：0 ~ 11
		}

		putchar('\n');

		for (auto i : Range(12, 32, 0))//步长为0，引发异常
		{
			printf("%d ", i);//不会执行到这里
		}

		putchar('\n');//不会执行到这里
	}
	catch (std::invalid_argument &err)
	{
		printf("%s", err.what());//打印异常信息
	}

	return 0;
}

/*
执行输出：
32 40 48 56
32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63
0 1 2 3 4 5 6 7 8 9 10 11
In class : Range.Constructed(3 parameter)
throw : The third parameter "_tStep" is 0 !
*/