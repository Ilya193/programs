#include <iostream>
#include <cstring>

template <typename T1, typename T2>
void maxn(T1* a, T2);

char* s(char* str[], int);

int main()
{
    double numbers[5] = {10.8, 5.2, 7.5, 23.111, 4.434};
    int numbers2[6] = {6, 5, 4, 3, 2, 1};

    char* str[3] = 
    {
        "test1",
        "test123",
        "test12"
    };

    maxn(numbers, 5);
    maxn(numbers2, 6);

    std::cout << s(str, 3) << std::endl;

    return 0;
}

template <typename T1, typename T2>
void maxn(T1* a, T2 size)
{
    double max = 0.0;

    for (int key = 0; key < size; key++)
    {
        if (max < a[key]) 
        {
            max = a[key];
        }
    }

    std::cout << max << std::endl;
}

char* s(char* arr[], int e)
{
    char* ps;
    int max_size = 0;
    char* temp;

    for (int key = 0; key < e; key++)
    {
        if (max_size < strlen(arr[key]))
        {
            max_size = strlen(arr[key]);
        }
    }

    ps = new char[max_size + 1];

    for (int key = 0; key < e; key++)
    {
        if (strlen(arr[key]) == max_size)
        {
            strcpy(ps, arr[key]);
            break;
        }
    }

    return ps;
}
