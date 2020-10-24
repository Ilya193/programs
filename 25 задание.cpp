#include <iostream>

void f1(int i)
{
    int count = 0;
    
    for (int j = 2; j <= i / 2; j++)
    {
        if (i % j == 0)
        {
            count++;
        }
    }
    
    if (count == 4)
    {
        count = 0;
        
        for (int j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                std::cout << j << std::endl;
            }
        }
    }
    
    std::cout << std::endl;
}

void f2(int i, int count)
{
    int z = 0, a = 0;

    for (int x = 2; x < i; x++)
    {
        if (i % x != 0)
        {
            z++;
        }
        if (i % x == 0)
        {
            a++;
        }
    }

    if (z > 0 && a == 0)
    {
        std::cout << count << " " << i << std::endl;
    }
}

int main()
{
    // делители
    for (int i = 0; i <= 0; i++)
    {
        f1(i);
    }
    
    //простые числа
    int count = 1;
    for (int i = 0; i <= 0; i++)
    {
        f2(i, count);
        count++;
    }
    
    return 0;
}
