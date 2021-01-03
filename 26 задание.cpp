#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
    std::ifstream file("C:/code/26/26-20.txt");
    int s, n, summ = 0;

    file >> s >> n;
    std::vector <int> num(n);

    for (int i = 0; i < n; i++)
    {
        file >> num[i];
    }

    sort(num.begin(), num.end());

    int ind, max_s = 0;
    for (ind = 0; ind < n; ind++) {
        if (num[ind] + summ > s) break;
        summ += num[ind];
    }

    summ -= num[ind];

    for (int i = ind + 1; i < n; i++)
        if (summ + num[i] <= s) max_s = num[i];

    std::cout << ind << " " << max_s << std::endl;

    return 0;
}
