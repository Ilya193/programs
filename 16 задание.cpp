#include <iostream>

int main()
{
    int* numbers = new int[30];
    numbers[1] = 1; // зависит от задания
    int res;

    // зависит от задания
    for (int i = 2; i <= 26; i++)
    {
        if (i % 2 == 0)
        {
            res = 2 + numbers[i - 1];
            numbers[i] = res;
        }
        else if (i % 2 != 0)
        {
            res = 2 * numbers[i - 2];
            numbers[i] = res;
        }
    }

    std::cout << res << std::endl;

    return 0;
}
