#include "z.h"
//#include <string>

void Pj::general_fun()
{
    std::cout << "d - display\ni - input\nr - rewrite\ne - exit" << std::endl;
    std::cin >> ch;

    if (ch == 'd')
    {
        display();
    }
    else if (ch == 'i')
    {
        fill();
    }
    else if (ch == 'r')
    {
        rewrite();
    }
    else if (ch == 'e')
    {
	    exit(0);
    }
    else
    {
        std::cout << "no ch" << std::endl;
        general_fun();
    }
}

void Pj::fill()
{
    std::cout << "number: ";

    if (!(std::cin >> tempn))
    {
        std::cout << "not a number" << std::endl;
        exit(0);
    }

    std::cin.get();

    numbers[count] = tempn;

    std::cout << "name: ";
    getline(std::cin, temps);

    name[count] = temps;

    count++;

    general_fun();
}

void Pj::rewrite()
{
    std::cout << "n - number\ns - name" << std::endl;
    std::cin >> ch;

    if (ch == 'n')
    {
        std::cout << "change the number: ";
        std::cin >> tempn;
        std::cin.get();

        for (int key = 0; key < count; key++)
        {
            if (tempn == numbers[key])
            {
                std::cout << "enter the new number: ";
                std::cin >> new_number;
                std::cin.get();

                numbers[key] = new_number;

                general_fun();
            }

            if (cl == 0 && key == count - 1)
            {
                std::cout << "no number" << std::endl;
                rewrite();
	        }
	     }
     }
     else if (ch == 's')
     {
         std::cout << "change the name: ";
         std::cin.get();
         getline(std::cin, temps);

         for (int key = 0; key < count; key++)
         {
             if (temps == name[key])
             {
                 std::cout << "enter the new name: ";
                 getline(std::cin, new_name);

                 name[key] = new_name;

                 general_fun();
             }

             if (cl == 0 && key == count - 1)
             {
                 std::cout << "no name." << std::endl;
 		         std::cout << "coincidences: " << std::endl;
 		         coincidences();
                 rewrite();
             }
         }
     }
     else
     {
         std::cout << "no ch" << std::endl;
         rewrite();
     }
}

void Pj::display()
{
    for (int key = 0; key < count; key++)
    {
        std::cout << "number: " << numbers[key] << std::endl;
	    std::cout << "name: " << name[key] << std::endl;
    }

    general_fun();
}

void Pj::coincidences()
{
    for (int key = 0; key < count; key++)
    {
    	t = name[key];

        for (int i = 0; i < t.size(); i++)
        {
            if (temps[i] == t[i])
            {
                ++ccs;

                if (ccs >= 2)
                {
                    std::cout << t << std::endl;
                    break;
                }
            }
        }

	ccs = 0;
    }
}
