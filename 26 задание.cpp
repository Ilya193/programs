#include <iostream>

void sort(int* arr, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
}

int main()
{
    int ob, n;
    std::cin >> ob >> n;
    std::cin.get();
    
    int array[n];
    int c = 0;
    
    while (c < n)
    {
        std::cin >> array[c++];
    }
    
    sort(array, n);
    
    std::cout << std::endl;
    
    for (int k = 0; k < n; k++)
        std::cout << array[k] << std::endl;
    
    std::cout << std::endl;
    
    int sum = 0, max = 0, index = 0;
    
    while (sum <= ob)
    {
        sum += array[index++];
        max = array[index - 1];
    }
    
    /*if (sum != ob)
    {
        sum -= array[index - (index)];
    }*/
    
    index = 0;
    while (sum > ob)
        sum -= array[index++];
    
    std::cout << sum <<  " " << max << std::endl;
    
    /*for (int k = 0; k < n; k++)
        std::cout << array[k] << std::endl;*/

    return 0;
}
