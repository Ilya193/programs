#include <iostream>

void fib(int x, int y, int z);

int main()
{
	int x = 1, y = 1, z = 0;

	fib(x, y, z);

	return 0;
}

void fib(int x, int y, int z)
{
	while (z < 1000)
	{
		z = x + y;
		std::cout << z << std::endl;
		x = y;
		y = z;
	}
}
