#include<stdio.h>
#include "Range.hpp"

int main(void)
{
	for (auto i : Range<int>(32))
	{
		printf("%d\n", i);
	}

	return 0;
}