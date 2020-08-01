#include <iostream> 

#define N 5

int main(void)
{
	int a[N];
	
	int i, k, max, max2;
	
	for (i = 0; i < N; i++)
		std::cin >> a[i];

	max = 0, max2 = 0;
	
	for (i = 0; i < N; i++)
	{
		if (a[i] > max)
			max = a[i];
		else if (a[i] > max2 && a[i] != max)
			max2 = a[i];	
	}
	
	/*for (i = 0; i < N; i++)
	{
		if (a[i] > max2 && a[i] != max)
			max2 = a[i];
	}*/
	
	std::cout << max << std::endl;
	std::cout << max2 << std::endl;
}
