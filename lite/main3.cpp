#include <iostream>

double fill(double* num_arr, int x);
void view(double* num_arr, int count);

int main()
{
    int count;
    std::cin >> count;

    double* numbers = new double[count];

    for (int key = 0; key < count; key++)
    {
        numbers[key] = fill(numbers, key * key);
    }

    view(numbers, count);

    delete [] numbers;

    return 0;
}

double fill(double* num_arr, int x)
{  
    double temp;
    
    while (!(std::cin >> temp)) std::cin.clear();

    return temp + x;
}

void view(double* num_arr, int count)
{
    for (int j = 0; j < count; j++) std::cout << "elem: " << num_arr[j] << std::endl;
}