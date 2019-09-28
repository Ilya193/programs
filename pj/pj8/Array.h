template <typename type, int val>
class A
{
private:
    type arr[val];
    type copy_arr[val];
    int top;
    int min, max, sum, avg;

    int gb;
    int count;
    int j;
    int m;

public:
    A();

    void show() const;
    void del(int i = val);
    void append(int i = 0);
    void min_number();
    void max_number();
    void sum_numbers();
    void average();
    
    void sort();
    void un_sort();
    void irv(int);

    int operator[](int);
};

template <typename type, int val>
void A<type, val>::sort()
{
    for (int key = 0; key <= top; key++)
    {
        un_sort();
    }
}

template <typename type, int val>
void A<type, val>::un_sort()
{
    int num = gb + 1;
    int c;

    for (int key = 0; key < val; key++)
    {
        if (copy_arr[key] < num)
        {
            num = copy_arr[key];
            c = key;
        }
    }

    arr[j++] = num;

    irv(c);
}

template <typename type, int val>
void A<type, val>::irv(int n)
{
    for (int x = 0; x <= n; x++)
    {
        if (x == n)
        {
            for (int y = x; y < top; y++)
            {
                copy_arr[y] = copy_arr[y + 1];
            }
        }
    }

    copy_arr[count - 1] = gb + gb;
    count--;
    m--;
}

template <typename type, int val>
int A<type, val>::operator[](int n)
{
    return arr[n];
}

template <typename type, int val>
A<type, val>::A()
{
    top = val - 1;
    min = max = sum = avg = 0;

    type temp;

    int key = 0;
    while (key <= top && std::cin >> temp)
    {
        if (key <= top)
        {
            arr[key] = temp;
            key++;
        }
    }

    for (int key = 0; key <= top; key++)
    {
        copy_arr[key] = arr[key];
    }

    gb = 0;
    count = val;
    j = 0;
    m = val;

    for (int key = 0; key < val; key++)
    {
        if (arr[key] > gb)
        {
            gb = arr[key];
        }
    }
}

template <typename type, int val>
void A<type, val>::show() const
{
    std::cout << "arr: " << std::endl;
    for (int key = 0; key <= top; key++)
    {
        std::cout << arr[key] << std::endl;
    }
}

template <typename type, int val>
void A<type, val>::del(int i)
{
    if (i > val)
    {
        std::cout << ">" << std::endl;
    }

    if (i == val)
    {
        top--;
    }
    else
    {
        i--;

        for (int x = 0; x <= i; x++)
        {
            if (x == i)
            {
                for (int y = x; y <= top; y++)
                {
                    arr[y] = arr[y + 1];
                }
            }
        }
    }

        top--;
    }
}

template <typename type, int val>
void A<type, val>::append(int i)
{
    if (top == val - 1)
    {
        std::cout << "full" << std::endl;
    }
    else
    {
        top++;
        arr[top] = i;
    }
}

template <typename type, int val>
void A<type, val>::max_number()
{
    for (int key = 0; key <= top; key++)
    {
        if (arr[key] > max)
        {
            max = arr[key];
        }
    }

    std::cout << "max: " << max << std::endl;
}

template <typename type, int val>
void A<type, val>::min_number()
{
    min = arr[0];

    for (int key = 0; key <= top; key++)
    {
        if (arr[key] < min)
        {
            min = arr[key];
        }
    }

    std::cout << "min: " << min << std::endl;
}

template <typename type, int val>
void A<type, val>::sum_numbers()
{
    for (int key = 0; key <= top; key++)
    {
        sum += arr[key];
    }

    std::cout << "sum: " << sum << std::endl;
}

template <typename type, int val>
void A<type, val>::average()
{
    sum = 0;

    for (int key = 0; key <= top; key++)
    {
        sum += arr[key];
    }

    avg = sum / (top + 1);

    std::cout << "average: " << avg << std::endl;

    sum = 0;
}
