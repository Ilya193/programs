#include <iostream>
#include "test.cpp"

int main()
{
   	Lesson t;

	int num = 10;

	int* pnum = t.operator*(num);

	std::cout << pnum << std::endl;

    return 0;
}
