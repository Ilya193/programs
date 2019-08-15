#include <iostream>
//#include "dft.cpp"

int main()
{
    char str[6] = "$$$$$";

    for (int key = 0; key < 5; key++)
    {
	if (key == 0)
	{
	    std::cout << str[key] << std::endl;

	    continue;
	}

	for (int j = 0; j != key + 1; j++)
	{
	    std::cout << str[j];
	}

	std::cout << std::endl;
    }
	
    return 0;
}
