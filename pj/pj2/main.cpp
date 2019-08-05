#include <iostream>
#include "t.cpp"

int main()
{
    Str s = Str(0, 0, 0, 0, 0, 0);

    char temp[30];
    std::cin.getline(temp, 30);

    int length = s.strlen(temp);
    std::cout << "length: " << length << std::endl;

    return 0;
}
