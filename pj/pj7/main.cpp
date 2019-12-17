#include <iostream>

template <typename t>
class test_array
{
private:
    t* arr1;
    t* arr2;

    int top;

public:
    explicit test_array(int n)
    {
        try
        {
            if (n == 0)
            {
                throw "error to create";
            }
        }
        catch (const char* str)
        {
            std::cout << str << std::endl;
            exit(0);
        }

        arr1 = new t[n];
        top = n;

        for (int key = 0; key < top; key++)
        {
            arr1[key] = key + 1;
        }
    }

    ~test_array()
    {
        delete[] arr1;
    }

    void append(t number)
    {
        arr2 = new t[top + 1];

        for (int key = 0; key < top; key++)
        {
            arr2[key] = arr1[key];
        }

        arr2[top++] = number;

        delete[] arr1;

        arr1 = new t[top];

        for (int key = 0; key < top; key++)
        {
            arr1[key] = arr2[key];
        }
        
        delete[] arr2;
    }
};

int main()
{
    test_array<double> ta(3);

    ta.append(5.28);

    return 0;
}
