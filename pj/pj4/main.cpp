#include <iostream>
#include "t.cpp"

int main()
{
    std::cout << "the size of the list: ";
    int n;
    std::cin >> n;
    std::cin.get();

    List t = List(n);

    t.general_fun();

    return 0;
}
