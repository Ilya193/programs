#include "z.h"

List::List(int n)
{
    numbers = new double[n];
    max = n;

    top = 0;
}

void List::general_fun()
{
    std::cout << "a - append\nr - remove\ne - isempty\nf - isfull\ns - show" << std::endl;
    std::cin >> ch;

    if (tolower(ch) == 'a')
    {
        isempty();
        isfull();

        std::cout << "true" << std::endl;
    }
}

void List::isempty()
{
    if (max == 0)
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
}
