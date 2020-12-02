#include <iostream>
#include <cstring>

std::string split1(std::string& s, const char ch)
{
    std::string temp;

    for (int k = 0; s[k] != ch; k++)
    {
        temp += s[k];
    }

    return temp;
}

std::string split2(std::string& s)
{
    std::string temp;

    for (int k = 0; k < s.size(); k++)
    {
        if (s[k] == ' ')
        {
            for (int i = k; i < s.size(); i++)
            {
                temp += s[i];
            }

            break;
        }
    }

    return temp;
}

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
