#include <iostream>
#include <fstream>
#include "t.cpp"

int main()
{
    Pj t;

    t.file_read();

    if (t.i == 1)
    {
        t.general_fun();
    }
    else
    {
        return 0;
    }

    return 0;
}
