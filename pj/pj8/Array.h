#include <iostream>
#include <initializer_list>

template <typename t, int value = 1>
class array_number
{
private:
    t arr[value];
    int count;

    void show()
    {
        for (int key = 0; key < count; key++)
        {
            if (key < count && key != count - 1)
            {
                std::cout << arr[key] << std::endl;
            }
            else if (key == count - 1)
            {
                std::cout << arr[key];
            }
        }
    }

public:
    array_number(int n)
    {
        count = value;

        for (int key = 0; key < count; key++)
        {
            arr[key] = n;
        }
    }

    array_number()
    {
        count = value;

        for (int key = 0; key < count; key++)
        {
            arr[key] = 0;
        }
    }

    array_number(const array_number& a)
    {
        count = a.count;

        for (int key = 0; key < count; key++)
        {
            arr[key] = a.arr[key];
        }
    }

    array_number(std::initializer_list<t> il)
    {
        count = value;

        if (il.size() == 1)
        {
            for (int key = 0; key < count; key++)
            {
                const t* n = il.begin();
                arr[key] = *n;
            }
        }
        else if (count == il.size())
        {
            int c = 0;
            for (auto a : il)
            {
                arr[c++] = a;
            }
        }
        else
        {
            try
            {
                if (count < il.size())
                {
                    throw "size > value";
                }
                if (count > il.size())
                {
                    throw "size < value";
                }
            }
            catch (const char* str)
            {
                std::cout << str << std::endl;
                exit(0);
            }
        }
    }

    t& operator[](int n)
    {
        return arr[n];
    }

    friend std::ostream& operator<<(std::ostream& os, array_number& a)
    {
        a.show();

        return os;
    }

    array_number operator+(array_number& an)
    {
        array_number<t, value> temp;

        for (int key = 0; key < count; key++)
        {
            temp.arr[key] = arr[key] + an.arr[key];
        }

        return temp;
    }

    array_number operator-(array_number& an)
    {
        array_number<t, value> temp;

        for (int key = 0; key < count; key++)
        {
            temp.arr[key] = arr[key] - an.arr[key];
        }

        return temp;
    }

    void append(t n)
    {
        try
        {
            if (count == value)
            {
                throw "arr is full";
            }
        }
        catch (const char* str)
        {
            std::cout << str << std::endl;
            exit(0);
        }

        arr[count++] = n;
    }

    void del(int n = -1) // -1 flag
    {
        try
        {
            if (n > count)
            {
                throw "element is missing";
            }
        }
        catch (const char* str)
        {
            std::cout << str << std::endl;
            exit(0);
        }

        if (n == -1)
        {
            arr[count--] = 0;
        }
        else
        {
            for (int x = 0; x < n; x++)
            {
                if (x == n - 1)
                {
                    for (int y = x; x < count; x++)
                    {
                        arr[y] = arr[y + 1];
                    }
                }
            }

            arr[count--] = 0;
        }
    }

    int size()
    {
        return count;
    }

    void sort()
    {
        for (int x = 0; x < count; x++)
        {
            for (int y = 0; y < count; y++)
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

    t sum()
    {
        t sum = 0;

        for (int key = 0; key < count; key++)
        {
            sum += arr[key];
        }

        return sum;
    }

    t max()
    {
        t max = arr[0];

        for (int key = 0; key < count; key++)
        {
            if (arr[key] > max)
            {
                max = arr[key];
            }
        }

        return max;
    }

    t min()
    {
        t min = arr[0];

        for (int key = 0; key < count; key++)
        {
            if (arr[key] < min)
            {
                min = arr[key];
            }
        }

        return min;
    }

    t average()
    {
        return sum() / count;
    }
};
