#include <iostream>

int strlen(char* string);

int main()
{
    char temp[15];
    std::cin.getline(temp, 15);

    int length = strlen(temp);

    std::cout << "length: " << length << std::endl;
    
    return 0;
}

int strlen(char* string)
{
    int length = 0;

    for (; string[length] != '\0'; length++)
    {
        ++length;
    }

    return length - 1;
}
