#include <iostream>
#include <fstream>
#include "t.cpp"

int main()
{
	std::ifstream file1, file2;
	file1.open("g");

	char temp[80];
	int count = 0;

	while (file1 >> temp)
	{
		count++;
	}

	file1.close();

	Lesson c = Lesson(count);
	file2.open("g");

	int i = 0;
	while (file2 >> temp)
	{
 	    c << temp;
		i++;
	}

	for (int key = 0; key < count; key++)
	{
		std::cout << c << std::endl;
	}

	file2.close();

    return 0;
}
