#include <iostream>

static int count = 0;

void fun(int, int*);

int main()
{
    int* numbers;
    int main_number;
    std::cin >> main_number;
    std::cin.get();

    if (main_number >= 3)
    {
        numbers = new int[main_number];

        for (int key = 3; key <= main_number; key++)
        {
            fun(key, numbers);
        }
    }
    else
    {
        std::cout << "false" << std::endl;
    }

    for (int key = 0; key < count; key++)
    {
        std::cout << numbers[key] << std::endl;
    }

    delete[] numbers;
    
    return 0;
}

void fun(int m, int* nr)
{
    static int i = 0;
    int z = 0, a = 0;

    for (int x = 2; x < m; x++)
    {
        if (m % 1 == 0 && m % m == 0 && m % x != 0)
        {
            z++;
        }
        if (m % 1 == 0 && m % m == 0 && m % x == 0)
        {
            a++;
        }
    }

    if (z > 0 && a == 0)
    {
        count++;
        nr[i++] = m;
    }
}

