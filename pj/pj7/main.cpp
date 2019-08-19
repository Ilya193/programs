#include <iostream>
#include "dft.cpp"

int main()
{
    MyClass t = MyClass();
    
    for (int key = 0; key < 10; key++)
    {
        t.fill(key);
    }
    
    std::cout << t;
    
    return 0;
}
