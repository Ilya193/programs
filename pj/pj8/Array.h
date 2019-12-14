#include <iostream>

template<typename t, int value = 0>
class v
{
private:
    t* arr;
    int top;
    
    int y;
    int val;

public:
    v() // параметры
    {
        if (value == 0)
        {
            arr = new t[1];
            top = 1;
        }
        else
        {
            arr = new t[value];
            top = value - 1;
        }
        
        for (int key = 0; key <= top; key++)
        {
            arr[key] = 0;
        }

        val = value;
    }
    ~v()
    {
        delete[] arr;
    }
    
    v& operator[](int n)
    {
        try
        {
            if (n - 1 >= top)
            {
                delete[] arr;
                throw "element is missing";
            }
        }
        catch (const char* s)
        {
            std::cout << s << std::endl;
            exit(0);
        }
        
        y = n;
        return *this;
    }
    
    void operator=(t n)
    {
        arr[y] = n;
        y = 0;
    }

    void del(int n = 0)
    {
        if (n != 0)
        {
            if (n == value)
            {
                arr[top--] = 0;
            }
            else
            {
                for (int x = 0; x < n; x++)
                {
                    if (x == n - 1)
                    {
                        for (int y = x; y <= top; y++)
                        {
                            arr[y] = arr[y + 1];
                        }
                    }
                }

                arr[top--] = 0;
            }
        }
        else
        {
            arr[top--] = 0;
        }
    }

    void append(int n)
    {
        try
        {
            if (top == value - 1)
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

        arr[++top] = n;
    }

    void sort()
    {
        for (int x = 0; x <= top; x++)
        {
            for (int y = 0; y <= top; y++)
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
    
    friend std::ostream& operator<<(std::ostream& os, v& v_)
    {
        if (v_.y == 0)
        {
            for (int key = 0; key <= v_.top; key++)
            {
                if (key < v_.top)
                {
                    std::cout << v_.arr[key] << std::endl;
                }
                else if (key = v_.top)
                {
                    std::cout << v_.arr[key];
                }
            }
        }
        else
        {
            os << v_.arr[v_.y];
        }
        
        return os;
    }

    t operator+(const v& v_)
    {
        int sum = 0;

        for (int key = 0; key < val; key++)
        {
            sum += arr[key] + v_.arr[key];
        }

        return sum;
    }
    
    t operator-(const v& v_)
    {
        int sum = 0;

        for (int key = 0; key < val; key++)
        {
            sum += arr[key] - v_.arr[key];
        }

        return sum;
    }

    v(const v& v_)
    {
        arr = new t[value];
        top = v_.top;
        y = v_.y;
        val = value;

        for (int key = 0; key < value; key++)
        {
            arr[key] = v_.arr[key];
        }
    }

    t sum()
    {
        t sum = 0;

        for (int key = 0; key <= top; key++)
        {
            sum += arr[key];
        }

        return sum;
    }

    t max()
    {
        t max = arr[0];

        for (int key = 0; key <= top; key++)
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

        for (int key = 0; key <= top; key++)
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
        return sum() / value;
    }
};
