#include <iostream>

template<typename t>
class array
{
private:
    t* arr;

    int top;
    int py;

public:
    array(int n = 1)
    {
        try
        {
            if (n == 0)
            {
                throw "failed to create";
            }
        }
        catch (const char* s)
        {
            std::cout << s << std::endl;
            exit(0);
        }

        arr = new t[n];
        top = n;
    }

    array(const array& array_)
    {
        arr = new t[array_.top];
        top = array_.top;
        py = array_.py;

        for (int key = 0; key < top; key++)
        {
            arr[key] = array_.arr[key];
        }
    }

    void operator=(const array& array_)
    {
        try
        {
            if (top > array_.top)
            {
                throw "error in object declaration";
            }
        }
        catch (const char* str)
        {
            std::cout << str << std::endl;
            exit(0);
        }

        delete[] arr;

        arr = new t[array_.top];
        top = array_.top;
        py = array_.py;

        for (int key = 0; key < top; key++)
        {
            arr[key] = array_.arr[key];
        }
    }

    ~array()
    {
        delete[] arr;
    }

    array& operator[](int n)
    {
        try
        {
            if (n > top)
            {
                throw "element is missing";
            }
        }
        catch (const char* s)
        {
            std::cout << s << std::endl;
            exit(0);
        }

        py = n;

        return *this;
    }

    void operator=(t val)
    {
        arr[py] = val;
        py = -1; // output
    }

    friend std::ostream& operator<<(std::ostream& os, const array& array_)
    {
        if (array_.py != -1)
        {
            os << array_.arr[array_.py];
        }
        else
        {
            for (int key = 0; key < array_.top; key++)
            {
                if (key < array_.top && key != array_.top - 1)
                {
                    std::cout << array_.arr[key] << std::endl;
                }
                else if (key = array_.top - 1)
                {
                    std::cout << array_.arr[key];
                }
            }
        }
        
        return os;
    }

    friend std::istream& operator>>(std::istream& is, const array& array_)
    {
        is >> array_.arr[array_.py];

        return is;
    }
};

template <typename t>
class array_number
{
private:
    t* arr;
    int top;
    int py;

    int value;

public:
    array_number(int n = 1)
    {
        try
        {
            if (n == 0)
            {
                throw "failed to create";
            }
        }
        catch (const char* s)
        {
            std::cout << s << std::endl;
            exit(0);
        }

        value = n;
        arr = new t[n];
        top = n;
        py = -1; // flag

        for (int key = 0; key < top; key++)
        {
            arr[key] = 0;
        }
    }

    array_number(const array_number& array_num_)
    {
        arr = new t[array_num_.top];
        top = array_num_.top;
        py = array_num_.py;

        for (int key = 0; key < top; key++)
        {
            arr[key] = array_num_.arr[key];
        }
    }

    void operator=(const array_number& array_num_)
    {
        try
        {
            if (top > array_num_.top)
            {
                throw "error in object declaration";
            }
        }
        catch (const char* str)
        {
            std::cout << str << std::endl;
            exit(0);
        }

        delete[] arr;

        arr = new t[array_num_.top];
        top = array_num_.top;
        py = array_num_.py;

        for (int key = 0; key < top; key++)
        {
            arr[key] = array_num_.arr[key];
        }
    }

    ~array_number()
    {
        delete[] arr;
    }

    array_number& operator[](int n)
    {
        try
        {
            if (n > top)
            {
                throw "element is missing";
            }
        }
        catch (const char* s)
        {
            std::cout << s << std::endl;
            exit(0);
        }

        py = n;

        return *this;
    }

    void operator=(t val)
    {
        arr[py] = val;
        py = -1; // output
    }

    friend std::ostream& operator<<(std::ostream& os, const array_number& array_num_)
    {
        if (array_num_.py != -1)
        {
            os << array_num_.arr[array_num_.py];
        }
        else
        {
            for (int key = 0; key < array_num_.top; key++)
            {
                if (key < array_num_.top && key != array_num_.top - 1)
                {
                    std::cout << array_num_.arr[key] << std::endl;
                }
                else if (key = array_num_.top - 1)
                {
                    std::cout << array_num_.arr[key];
                }
            }
        }
        
        return os;
    }

    friend std::istream& operator>>(std::istream& is, const array_number& array_num_)
    {
        is >> array_num_.arr[array_num_.py];

        return is;
    }

    void del(int n = -1) // -1 flag
    {
        try
        {
            if (n > top)
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
            arr[top--] = 0;
        }
        else if (n != -1)
        {
            if (n == top)
            {
                arr[top--] = 0;
            }
            else
            {
                for (int x = 0; x < n; x++)
                {
                    if (x == n - 1)
                    {
                        for (int y = x; x < top; x++)
                        {
                            arr[y] = arr[y + 1];
                        }
                    }
                }

                arr[top--] = 0;
            }
        }
    }

    void append(int n)
    {
        try
        {
            if (top == value)
            {
                delete [] arr;
                throw "arr is full";
            }
        }
        catch (const char* s)
        {
            std::cout << s << std::endl;
            exit(0);
        }

        arr[top++] = n;
    }

    void sort()
    {
        for (int x = 0; x < top; x++)
        {
            for (int y = 0; y < top; y++)
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

    t operator+(const array_number& array_num_)
    {
        int sum = 0;

        for (int key = 0; key < top; key++)
        {
            sum += arr[key] + array_num_.arr[key];
        }

        return sum;
    }
    
    t operator-(const array_number& array_num_)
    {
        int sum = 0;

        for (int key = 0; key < top; key++)
        {
            sum += arr[key] - array_num_.arr[key];
        }

        return sum;
    }

    t sum()
    {
        t sum = 0;

        for (int key = 0; key < top; key++)
        {
            sum += arr[key];
        }

        return sum;
    }

    t max()
    {
        t max = arr[0];

        for (int key = 0; key < top; key++)
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

        for (int key = 0; key < top; key++)
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
        return sum() / top;
    }
};

template<typename t>
class array_string
{

};
