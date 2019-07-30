#include <iostream>
#include <fstream>

void fun(char, int, int);

int main()
{
    char ch; int count = 0, new_line = 0;

    fun(ch, count, new_line);

    return 0;
}

void fun(char ch, int count, int new_line)
{
    char filename[15];
    std::cin.getline(filename, 15);

    std::ofstream file1;
    file1.open(filename);

    if (!file1.is_open())
    {
	std::cout << "n" << std::endl;
	exit(EXIT_FAILURE);
    }

    std::cin.get(ch);

    while (ch != '.')
    {
	if (ch == '\n') ++new_line;

	++count;
	file1 << ch << std::endl;
	std::cin.get(ch);
    }
	
    std::ifstream file2;
    file2.open(filename);

    while (file2 >> ch)
    {
	std::cout << "file input: " << ch << std::endl;
    }

    std::cout << "count: " << count << std::endl;
    std::cout << "new_line: " << new_line << std::endl;

    file1.close();
    file2.close();
}
