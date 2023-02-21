#include<stdio.h>
#include <stdexcept>
#include "Range.hpp"

int main(void)
{
	try
	{
		for (auto i : Range(32, 64, 8))//c++17�Զ��Ƶ�����ʡ��<int>
		{
			printf("%d ", i);//��32��ʼ��64��������64������Ϊ8 �����32 40 48 56
		}

		putchar('\n');

		for (auto i : Range(32, 64))//c++17�Զ��Ƶ�����ʡ��<int>
		{
			printf("%d ", i);//��32��ʼ��64��������64��Ĭ�ϲ���Ϊ1 �����32 ~ 63
		}

		putchar('\n');

		for (auto i : Range(12))//c++17�Զ��Ƶ�����ʡ��<int>
		{
			printf("%d ", i);//Ĭ�ϴ�0��ʼ��12��������12��Ĭ�ϲ���Ϊ1 �����0 ~ 11
		}

		putchar('\n');

		for (auto i : Range(12, 32, 0))//����Ϊ0�������쳣
		{
			printf("%d ", i);//����ִ�е�����
		}

		putchar('\n');//����ִ�е�����
	}
	catch (std::invalid_argument &err)
	{
		printf("%s", err.what());//��ӡ�쳣��Ϣ
	}

	return 0;
}

/*
ִ�������
32 40 48 56
32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63
0 1 2 3 4 5 6 7 8 9 10 11
In class : Range.Constructed(3 parameter)
throw : The third parameter "_tStep" is 0 !
*/