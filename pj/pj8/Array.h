template <typename type, int val>
class A
{
private:
    type arr[val];
    int top;
    int min, max, sum, avg;

public:
    A();

    void show() const;
    void del(int i = val);
    void append(int i = 0);
    void min_number();
    void max_number();
    void sum_numbers();
    void average();

    int operator[](int);
};

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
