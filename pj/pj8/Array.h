template<typename t>
class array
{
private:
    t* arr;
    int value;
    int main_val;

    void show() const
    {
        for (int key = 0; key < value; key++)
        {
            if (key < value && key != value - 1)
            {
                std::cout << arr[key] << std::endl;
            }
            else if (key == value - 1)
            {
                std::cout << arr[key];
            }
        }
    }

    class it
    {
    private:
        t* b;
        t* e;
    public:
        it() : b(nullptr), e(nullptr)
        {

        }

        void settings(t* a1, t* a2)
        {
            b = a1;
            e = a2;
        }

        t* begin() const
        {
            return b;
        }

        t* end() const
        {
            return e;
        }
    };

    it iterator;

public:
    explicit array(int n)
    {
        try
        {
            if (n == 0)
            {
                throw "error";
            }
        }
        catch (const char* str)
        {
            std::cout << str << std::endl;
            exit(0);
        }

        arr = new t[n];
        value = n;
        main_val = n;

        for (int key = 0; key < value; key++)
        {
            arr[key] = 0;
        }

        iterator.settings(arr, &arr[value]);
    }

    array()
    {
        arr = new t[1];
        value = 1;
        main_val = 1;

        for (int key = 0; key < value; key++)
        {
            arr[key] = 0;
        }

        iterator.settings(arr, &arr[value]);
    }

    array(std::initializer_list<t> il)
    {
        arr = new t[il.size()];
        value = il.size();
        main_val = il.size();

        int c = 0;
        for (auto a : il)
        {
            arr[c++] = a;
        }

        iterator.settings(arr, &arr[value]);
    }

    array(const array& a)
    {
        value = a.value;
        main_val = a.main_val;
        arr = new t[value];

        for (int key = 0; key < value; key++)
        {
            arr[key] = a.arr[key];
        }

        std::cout << a.main_val << std::endl;

        iterator.settings(arr, &arr[value]);
    }

    void operator=(const array& a)
    {
        delete[] arr;
        
        value = a.value;
        main_val = a.main_val;
        arr = new t[value];

        for (int key = 0; key < value; key++)
        {
            arr[key] = a.arr[key];
        }

        iterator.settings(arr, &arr[value]);
    }

    ~array()
    {
        delete[] arr;
    }

    t* begin() const
    {
        t* b = iterator.begin();
        return b;
    }

    t* end() const
    {
        t* e = iterator.end();
        return e;
    }

    t& operator[](int n)
    {
        try
        {
            if (n > value - 1)
            {
                throw "element is missing";
            }
        }
        catch (const char* str)
        {
            delete[] arr;
            std::cout << str << std::endl;
            exit(0);
        }

        return arr[n];
    }

    array operator+(array& a)
    {
        array<t> temp;
        temp.value = a.value;
        temp.main_val = a.main_val;
        temp.arr = new t[value];

        for (int key = 0; key < value; key++)
        {
            temp.arr[key] = arr[key] + a.arr[key];
        }

        return temp;
    }

    array operator-(array& a)
    {
        array<t> temp;
        temp.value = a.value;
        temp.main_val = a.main_val;
        temp.arr = new t[value];

        for (int key = 0; key < value; key++)
        {
            temp.arr[key] = arr[key] - a.arr[key];
        }

        return temp;
    }

    friend std::ostream& operator<<(std::ostream& os, array& a)
    {
        a.show();

        return os;
    }

    friend t addition(array<t>& a1, array<t>& a2)
    {
        t temp_add = 0;

        for (int key = 0; key < a1.value; key++)
        {
            temp_add += a1.arr[key] + a2.arr[key];
        }

        return temp_add;
    }

    friend t subtraction(array<t>& a1, array<t>& a2)
    {
        t temp_add = 0;

        for (int key = 0; key < a1.value; key++)
        {
            temp_add += a1.arr[key] - a2.arr[key];
        }

        return temp_add;
    }

    friend t multiplication(array<t>& a1, array<t>& a2)
    {
        t temp_add = 0;

        for (int key = 0; key < a1.value; key++)
        {
            temp_add += a1.arr[key] * a2.arr[key];
        }

        return temp_add;
    }

    friend t division(array<t>& a1, array<t>& a2)
    {
        t temp_add = 0;

        for (int key = 0; key < a1.value; key++)
        {
            temp_add += a1.arr[key] / a2.arr[key];
        }

        return temp_add;
    }

    void append(int n)
    {
        if (value == main_val)
        {
            t* arr_ = new t[main_val + 1];
            main_val++; value++;

            for (int key = 0; key < value - 1; key++)
            {
                arr_[key] = arr[key];
            }

            arr_[value - 1] = n;

            delete[] arr;

            arr = new t[value];

            for (int key = 0; key < value; key++)
            {
                arr[key] = arr_[key];
            }

            delete[] arr_;

            iterator.settings(arr, &arr[value]);
        }
        else
        {
            arr[value++] = n;
            iterator.settings(arr, &arr[value]);
        }
    }

    void del(int n = -1) // -1 - flag
    {
        try
        {
            if (n > value)
            {
                throw "element is missing";
            }
        }
        catch (const char* str)
        {
            delete[] arr;
            std::cout << str << std::endl;
            exit(0);
        }

        if (n == -1)
        {
            arr[value--] = 0;
            iterator.settings(arr, &arr[value]);
        }
        else
        {
            for (int x = 0; x < n; x++)
            {
                if (x == n - 1)
                {
                    for (int y = x; x < value; x++)
                    {
                        arr[y] = arr[y + 1];
                    }
                }
            }

            arr[value--] = 0;
            iterator.settings(arr, &arr[value]);
        }
    }

    int size() const
    {
        return value;
    }

    void sort() const
    {
        for (int x = 0; x < value; x++)
        {
            for (int y = 0; y < value; y++)
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

    t sum() const
    {
        t sum = 0;

        for (int key = 0; key < value; key++)
        {
            sum += arr[key];
        }

        return sum;
    }

    t max() const
    {
        t max = arr[0];

        for (int key = 0; key < value; key++)
        {
            if (arr[key] > max)
            {
                max = arr[key];
            }
        }

        return max;
    }

    t min() const
    {
        t min = arr[0];

        for (int key = 0; key < value; key++)
        {
            if (arr[key] < min)
            {
                min = arr[key];
            }
        }

        return min;
    }

    t average() const
    {
        return sum() / value;
    }
};
