#include <iostream>
#include "t.cpp"

int main()
{
    int n;
    std::cin >> n;
    std::cin.get();

    List t = List(n);

    t.general_fun();

    return 0;
}
