#include "z.h"

MyClass::MyClass()
{
    numbers1 = nullptr;
    l = 0;
    t = 0;
}

MyClass::~MyClass()
{
    
    delete [] numbers1;
    delete [] numbers2;
}

void MyClass::fill(int n)
{
    ++l;
    if (l == 1)
    {
        numbers1 = new int[1];
        numbers1[0] = n;
        numbers2 = new int[1];
        numbers2[0] = n;
    }
    else
    {
        delete [] numbers1;
        numbers1 = new int[l];
        
        t = l - 2;
        
        for (int key = 0; key < t + 1; key++)
        {
            numbers1[key] = numbers2[key];
        }
        numbers1[l - 1] = n;
        
        delete [] numbers2;
        
        numbers2 = new int[l];
        
        for (int key = 0; key < t + 1; key++)
        {
            numbers2[key] = numbers1[key];
        }
        numbers2[l - 1] = n;
    }
}

std::ostream& operator<<(std::ostream& os, const MyClass& m)
{
    for (int key = 0; key < 10; key++)
    {
        os << m.numbers2[key] << std::endl;
    }
    
    return os;
}
