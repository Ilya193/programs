#include <iostream>
#include "dft.cpp"

int main()
{
    cl t1 = cl("hell");
    cl t2 = cl("hello");

    char symbol1 = t1.operator[](3);
    char symbol2 = t2.operator[](2);

    std::cout << symbol1 << std::endl;
    std::cout << symbol2 << std::endl;

    t1.operator==(t2);
    t1.operator>(t2);
    t1.operator<(t2);

    return 0;
}
