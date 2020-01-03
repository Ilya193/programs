#include <iostream>
#include <cstring>

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

bool palindrome(const char* str)
{
    for (int x = 0, y = strlen(str) - 1; str[x] != '\0'; x++, y--)
    {
        if (str[x] == str[y])
        {
            continue;
        }
        else
        {
            return 0;
        }
    }

    return 1;
}

bool palindrome(std::string str)
{
    for (int x = 0, y = str.size() - 1; x <= y; x++, y--)
    {
        if (str[x] == str[y])
        {
            continue;
        }
        else
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    std::string s = "h%dgl%";
    int numbers[5];
    int count = 0;

    find(s, '%', numbers, count);
    std::cout << palindrome(s) << std::endl;

    return 0;
}
