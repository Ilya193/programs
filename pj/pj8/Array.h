#pragma once

template <typename type, int val>
class A
{
private:
    type arr[val];
    int top;

public:
    A();

    void show() const;
    void del(int i = val);
    void append(int i = 0);
};

template <typename type, int val>
A<type, val>::A()
{
    top = val - 1;

    for (int key = 0; key <= top; key++)
    {
        arr[key] = key;
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
