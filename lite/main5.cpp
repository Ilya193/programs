#include <iostream>

int fill(double*, int);
void show(double*, int);
void reserse(double*, int);

int main()
{
    double numbers[5];

    int x = fill(numbers, 5);
    reserse(numbers, 5);
    show(numbers, 5);

    return 0;
}

int fill(double* arr, int size)
{
    double temp; int x = 0;

    while (x < size && std::cin >> temp)
    {
        if (x < size) arr[x] = temp;
        ++x;
    }

    return x;
}

void reserse(double* arr, int size)
{
    double temp;

    for (int x = 0, j = size - 1; x < j, j > x; ++x, j--)
    {
        if (x == 0 && j == size - 1) continue;

        temp = arr[j];

        arr[j] = arr[x];
        arr[x] = temp;
    }
}

void show(double* arr, int size)
{
    for (int key = 0; key < size; key++)
    {
        std::cout << "elem" << key << ": " << arr[key] << std::endl;
    }
}
