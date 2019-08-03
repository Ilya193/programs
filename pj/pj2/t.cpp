#include "z.h"

int Str::strlen(char* string)
{
    int res = 0;

    for (int x = 0; string[x] != '\0'; x++)
    {
        if (string[x] == ' ')
        {
            gap += 1;
        }
    }

    num_chs = new int[gap];

    for (int y = 0; string[y] != '\0'; y++)
    {
        if (string[y] == ' ')
        {
            num_chs[num_ch] = y;
            num_ch++;
        }
    }

    for (int key = 0; string[key] != '\0'; key++)
    {
        if (string[key + 1] == '\0')
        {
            if (gaps == 0)
            {
                res += 1;
            }

            res += (key + 1) - (num + 1);
        }
        if (string[key] == ' ')
        {
            res += num_chs[var_arr] - ch;
            num = num_chs[var_arr];
            var_arr += 1;
            gaps += 1;
        }
        if (string[key - 1] == ' ')
        {
            ch = key;
        }
    }

    return res;
}
