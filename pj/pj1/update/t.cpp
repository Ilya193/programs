#include "z.h"

Pj::Pj()
{
	count = 0;
	cl = 0;
	ccs = 0;
	c = 0;
    count_f = 0;
    ts = 0;
    i = 0;

	name = new std::string[200];
	numbers = new int[200];
}

Pj::Pj(const Pj& t)
{
    name = new std::string[200];
    numbers = new int[200];
    count = t.count;
    cl = t.cl;
    ccs = t.ccs;
    c = t.c;

    for (int key = 0; key < t.count; key++)
    {
        name[key] = t.name[key];
        numbers[key] = t.numbers[key];
    }
}

Pj::~Pj()
{
	delete [] name;
	delete [] numbers;
}

std::ostream& operator<<(std::ostream& os, const Pj& t2_)
{
	for (int key = 0; key < t2_.count; key++)
	{
        os << "name: " << t2_.name[key] << std::endl;
		os << "number: " << t2_.numbers[key] << std::endl;
	}

	return os;
}

void Pj::general_fun()
{
    std::cout << "d - display\ni - input\nr - rewrite\nc - clear\ne - exit" << std::endl;
    std::cin >> ch;
    std::cin.get();

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
        i = 0;
    }
    else if (ch == 'c')
    {
        clear();
    }
    else
    {
        std::cout << "no ch" << std::endl;
        general_fun();
    }
}

void Pj::fill()
{
    file_o.open("contacts", std::ios::app);

    if (!file_o.is_open())
    {
        std::cout << "file is not open" << std::endl;

        file_o.close();

        exit(0);       
    }

    std::cout << "name -> number - > choise" << std::endl;

    while (content != ".")
    {
        getline(std::cin, content);
        file_o << content << std::endl;

        getline(std::cin, content);
        file_o << content << std::endl;

        std::cout << "choise: " << std::endl;
        getline(std::cin, content);
    }

    file_o.close();

    file_fill();
    general_fun();
}

void Pj::rewrite()
{
    file_read();

    std::cout << "n - number\ns - name\ne - exit" << std::endl;
    std::cin >> ch;
    std::cin.get();

    if (ch == 'n')
    {
        std::cout << "change the number: ";
        if (!(std::cin >> tempn))
        {
            std::cout << "not a number" << std::endl;
            general_fun();
        }

        for (int key = 0; key < count; key++)
        {
            if (tempn == numbers[key])
            {
                std::cout << "enter the new number: ";
                if (!(std::cin >> new_number))
                {
                    std::cout << "not a number" << std::endl;
                    rewrite();
                }
                std::cin.get();

                numbers[key] = new_number;

                spec_fun();
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
        getline(std::cin, temps);

        for (int key = 0; key < count; key++)
        {
            if (temps == name[key])
            {
                std::cout << "enter the new name: ";
                getline(std::cin, new_name);
                name[key] = new_name;
                spec_fun();

                general_fun();
             }

            if (cl == 0 && key == count - 1)
            {
                std::cout << "no name." << std::endl;

 		        std::cout << "coincidences: ";
                coincidences();

                if (c > 0)
                {
                    std::cout << "no" << std::endl;
                }

                rewrite();
             }
         }
    }
    else if (ch == 'e')
    {
 	    general_fun();
    }
    else
    {
        std::cout << "no ch" << std::endl;
        rewrite();
    }
}

void Pj::display()
{
	Pj t2 = Pj(*this);
	
	std::cout << t2;

    general_fun();
}

void Pj::clear()
{
    std::cout << "enter a name: ";
    std::cin.get();
    std::cin.get();
    getline(std::cin, t);

    for (int key = 0; key < count; key++)
    {
        if (t == name[key])
        {
            for (int x = key; x < count; x++)
            {
                numbers[x] = numbers[x + 1];
                name[x] = name[x + 1];
            }

            count--;
            spec_fun();
            break;
        }
        else if (t == name[key] && key + 1 == count)
        {
            count--;
            break;
        }
    }
    
    count--;

    spec_fun();
    general_fun();
}

void Pj::coincidences()
{
    for (int key = 0; key < count; key++)
    {
        t = name[key];

        ch_b_char();
    }
}

bool Pj::ch_b_char()
{
    if (temps.size() > t.size())
    {
        return 0;
    }
    else
    {
        for (int key = 0; key < temps.size(); key++)
        {
            for (int i = 0; i < t.size(); i++)
            {
                if (temps[key] == t[i])
                {
                    ccs += 1;
                }
            }

            if (ccs >= 2)
            {
                std::cout << t << std::endl;
                break;
            }
        }
    }

    if (ccs == 0)
    {
        c += 1;
    }

    ccs = 0;
}

void Pj::file_read()
{
    file_i.open("contacts");

    if (!file_i.is_open())
    {
        std::cout << "file is not open" << std::endl;

        file_i.close();

        exit(0);       
    }

    while (file_i >> content)
    {
        count_f++;
    }

    if (file_i.eof())
    {
        if (count_f == 0)
        {
            std::cout << "no contact" << std::endl;
            std::cout << "fill: ";
            std::cin >> ch;
            std::cin.get();

            if (tolower(ch) == 'y')
            {
                file_i.close();
                fill();
            }
            else
            {
                file_i.close();
                
                general_fun();
            }
        }
        else
        {
            file_o.open("contacts", std::ios::app);
            file_o << std::endl;
            file_o.close();

            i = 1;

            file_i.close();
            file_fill();
            //general_fun();
        }
    }
}

void Pj::file_fill()
{
    file_i.open("contacts");

    if (!file_i.is_open())
    {
        std::cout << "file is not open" << std::endl;

        file_i.close();

        general_fun();        
    }

    count_f = 1;
    count = 0;
    ts = 0;
    while (file_i >> content)
    {
        if (count_f % 2 == 0)
        {
            numbers[count - ts] = atoi(content.c_str());
        }
        else
        {
            name[count - ts] = content;
            ts++;
        }

        count_f++;
        count++;
    }
    
    file_i.close();

    count -= ts;
}

void Pj::spec_fun()
{
    int h = 1, l = 0, p = 0;

    file_o.open("contacts");
    if (!file_o.is_open())
    {
        std::cout << "file is not open" << std::endl;
        file_i.close();
        general_fun();        
    }

    for (int key = 0; key < count; key++)
    {
        file_o << name[key] << std::endl;
        file_o << numbers[key] << std::endl;
    }

    file_o.close();
}
