#include <iostream>

void f(int i)
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

int main()
{
    for (int i = 210235; i <= 210300; i++)
    {
        f(i);
    }
    
    return 0;
}
