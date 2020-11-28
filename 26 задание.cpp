#include <iostream>
#include <fstream>

void sort(int* arr, int value)
{
    for (int x = 0; x < value; x++)
    {
        for (int y = 0; y < value; y++)
        {
            if (arr[x] < arr[y])
            {
                int temp = arr[y];
                arr[y] = arr[x];
                arr[x] = temp;
            }
        }
    }
}

int main() {
    std::ifstream file("27880.txt");

    std::string str;
    int numbers[2324] = {};
    int c = 0;

    while (getline(file, str))
    {
        if (str == "8358 2324")
            continue;

        numbers[c++] = std::stoi(str);
    }

    sort(numbers, c);

    int sum = 0, index = 0, sum2 = 0, count = 0, max = 0, i;

    while (sum + numbers[index] <= 8358)
    {
        count++;
        sum += numbers[index];
        i = numbers[index];
        index++;
    }

    // ЕСЛИ НЕ БУДЕТ НАЙДЕНО ДРУГОГО ФАЙЛА

    sum2 = sum - i;

    for (int k = index; k < c; k++)
    {
        if (sum2 + numbers[k] <= 8358)
            max = numbers[k];
    }

    std::cout << count << " " << max << std::endl;

    return 0;
}
