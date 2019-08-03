#include "z.h"
#include <cmath>

void Disc::ipt()
{
    std::cout << "ax², bx, c: " << std::endl;

    while (std::cin >> a && std::cin >> b && std::cin >> c)
    {
        break;
    }

    calc_disk();
}

void Disc::calc_disk()
{
    if (a >= 0)
    {
        d = (b * b) - (4 * a * c);
        root = sqrt(d);

        if (root > 0)
        {
            std::cout << "D = " << b << " * " << b << " - " << "4 * " << a << " * " << c << " = " << "√" << d << ", " << root << std::endl;
            more();
        }
        else if (root == 0)
        {
            std::cout << "D = " << b << " * " << b << " - " << "4 * " << a << " * " << c << " = " << "√" << d << ", " << root << std::endl;
            equal();
        }
        else
        {
            std::cout << "D = " << b << " * " << b << " - " << "4 * " << a << " * " << c << " = " << "√" << d << std::endl;
            std::cout << "no" << std::endl;
        }
    }
    if (a < 0)
    {
        temp_a = a * (-1);
        temp_b = b * (-1);
        temp_c = c * (-1);

        d = (b * b) - (4 * a * c);
        root = sqrt(d);

        if (root > 0)
        {
            std::cout << "D = " << b << " * " << b << " - " << "4 * " << a << " * " << c << " = " << "√" << d << ", " << root << std::endl;
            more();
        }
        else if (root == 0)
        {
            std::cout << "D = " << b << " * " << b << " - " << "4 * " << a << " * " << c << " = " << "√" << d << ", " << root << std::endl;
            equal();
        }
        else
        {
            std::cout << "D = " << b << " * " << b << " - " << "4 * " << a << " * " << c << " = " << "√" << d << std::endl;
            std::cout << "no" << std::endl;
        }
    }
}

void Disc::more()
{
    if (b >= 0)
    {
        numerator = -b + root;
        denominator = 2 * a;
        x1 = numerator / denominator;
        std::cout << "        " << -b << " + " << root << std::endl;
        std::cout << "x1 = ------------ = " << x1 << std::endl;
        std::cout << "        2 * " << a << std::endl;

        std::cout << std::endl;

        numerator = -b - root;
        denominator = 2 * a;
        x2 = numerator / denominator;
        std::cout << "        " << -b << " - " << root << std::endl;
        std::cout << "x2 = ------------ = " << x2 << std::endl;
        std::cout << "        2 * " << a << std::endl;
    }

    if (b < 0)
    {
        numerator = (b * (-1)) + root;
        denominator = 2 * a;
        x1 = numerator / denominator;
        std::cout << "        " << b << " + " << root << std::endl;
        std::cout << "x1 = ------------ = " << x1 << std::endl;
        std::cout << "        2 * " << a << std::endl;

        std::cout << std::endl;

        numerator = (b * (-1)) - root;
        denominator = 2 * a;
        x2 = numerator / denominator;
        std::cout << "        " << b << " - " << root << std::endl;
        std::cout << "x2 = ------------ = " << x2 << std::endl;
        std::cout << "        2 * " << a << std::endl;
    }
}

void Disc::equal()
{
    if (b >= 0)
    {
        numerator = -b + root;
        denominator = 2 * a;
        x1 = numerator / denominator;
        std::cout << "        " << -b << " + " << root << std::endl;
        std::cout << "x1 = ------------ = " << x1 << std::endl;
        std::cout << "        2 * " << a << std::endl;
    }

    if (b < 0)
    {
        numerator = (b * (-1)) + root;
        denominator = 2 * a;
        x1 = numerator / denominator;
        std::cout << "        " << b << " + " << root << std::endl;
        std::cout << "x1 = ------------ = " << x1 << std::endl;
        std::cout << "        2 * " << a << std::endl;
    }
}
