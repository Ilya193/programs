#include "dft.h"

void find(const char* str, char ch, int* n, int& count)
{
    for (int key = 0; str[key] != '\0'; key++)
    {
        if (str[key] == ch)
        {
            n[count++] = key;
        }
    }
}

void find(std::string str, char ch, int* n, int& count)
{
    for (int key = 0; str[key] != '\0'; key++)
    {
        if (str[key] == ch)
        {
            n[count++] = key;
        }
    }
}

int main()
{
    std::string s = "h%dgl%";
    char ch = '%';
    int numbers[5];
    int count = 0;

    find(s, ch, numbers, count);

    return 0;
}


// h%dgl%
