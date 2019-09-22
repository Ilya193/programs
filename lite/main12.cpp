#include <iostream>

static int count = 5;
static int j = 0;
static int m = 5;
static int gb;

void fun(int*, int*);
void del(int*, int);

int main()
{
    int numbers[5] = {9999, 234325, 0, 1, 34857};
    int new_numbers[5];

    for (int key = 0; key < 5; key++)
    {
        if (numbers[key] > gb)
        {
            gb = numbers[key];
        }
    }

    for (int key = 0; key < 5; key++)
    {
        fun(numbers, new_numbers);
    }

    for (int key = 0; key < 5; key++)
    {
        std::cout << new_numbers[key] << std::endl;
    }

    return 0;
}

void fun(int* arr1, int* arr2)
{
    int num = gb + 1;
    int c;

    for (int key = 0; key < 5; key++)
    {
        if (arr1[key] < num)
        {
            num = arr1[key];
            c = key;
        }
    }
    arr2[j++] = num;

    del(arr1, c);
}

void del(int* arr, int num)
{
    /*if (num == 4)
    {
        arr[count - 1] = gb + gb;
        count--;
        m--;
    }
    else
    {
        for (int x = 0; x <= num; x++)
        {
            if (x == num)
            {
                for (int y = x; y < 4; y++)
                {
                    arr[y] = arr[y + 1];
                }
            }
        }

        arr[count - 1] = gb + gb;
        count--;
        m--;
    }*/

    for (int x = 0; x <= num; x++)
    {
        if (x == num)
        {
            for (int y = x; y < 4; y++)
            {
                arr[y] = arr[y + 1];
            }
        }
    }

    arr[count - 1] = gb + gb;
    count--;
    m--;
}
