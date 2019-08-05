#include "z.h"

List::List(int n)
{
    numbers = new double[n];
    max = n;

    top = 0;
}

void List::general_fun()
{
    std::cout << "a - append\nr - remove\ne - isempty\nf - isfull\no - out\ns - size" << std::endl;
    std::cin >> ch;

    if (tolower(ch) == 'a')
    {
        isempty();
        isfull();

        if (top < max)
        {
            std::cin >> temp;
            std::cin.get();
            numbers[top] = temp;

            top++;
        }
        else
        {
            std::cout << "list is full." << std::endl;
            general_fun();
        }

        general_fun();
    }
    else if (tolower(ch) == 'r')
    {
        isempty();

        top--;

        std::cout << "last item removed." << std::endl;

        general_fun();
    }
    else if (tolower(ch) == 'e')
    {
        isempty();
    }
    else if (tolower(ch) == 'f')
    {
        isfull();
    }
    else if (tolower(ch) == 's')
    {
        resize_list();
    }
    else if (tolower(ch) == 'o')
    {
        out();
    }
}

void List::isempty()
{
    if (top == 0)
    {
        std::cout << "it's is empty list." << std::endl;

        std::cout << "resize: ";
        std::cin >> ch;

        if (tolower(ch) == 'y')
        {
            resize_list();
        }
        else
        {
            general_fun();
        }
    }
}

void List::isfull()
{
    if (top == max)
    {
        std::cout << "list is full." << std::endl;
        general_fun();
    }
    else
    {
        std::cout << "the list is not filled." << std::endl;
        general_fun();
    }
}

void List::resize_list()
{
    std::cout << "enter the new size: ";
    std::cin >> temp;
    std::cin.get();

    delete [] numbers;

    numbers = new double[temp];
    max = temp;

    std::cout << "new size: " << temp << std::endl;

    general_fun();
}

void List::out()
{
    isempty();

    std::cout << "the contents of the list: ";

    for (int key = 0; key < top; key++)
    {
        if (key + 1 == top) std::cout << numbers[key] << std::endl;
        else std::cout << numbers[key] << ", ";
    }

    general_fun();
}
