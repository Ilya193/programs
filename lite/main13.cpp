#include <iostream>

int f(int);

int main()
{
    int main_number = 1000;
    int count = 0;
    int num = 0;

    for (int key = 3; key < main_number; key++)
    {
        num = f(key);

        if (num == 0)
        {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}

int f(int m)
{
    int j = 0;

    for (int x = 1; x < m; x++)
    {
        if (x != 1 && x != m && m % x == 0)
        {
            j = 10; // flag
            break;
        }
    }

    return j;
}
