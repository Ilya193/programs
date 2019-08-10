#include <fstream>
#include <string>
#include "cl.h"

C_file::C_file()
{
    count = 0;
    key_nm = 0;
    key_nr = 0;
    ct = 0;
    var = 0;
}

void C_file::read()
{
    file_i.open("g");
    if (!file_i.is_open())
    {
        std::cout << "no" << std::endl;
        exit(0);
    }

    while (file_i >> content)
    {
        count++;
    }

    if (file_i.eof())
    {
        if (count == 0)
        {
            std::cout << "the file is not empty" << std::endl;
            std::cout << "write: ";
            std::cin >> ch;
            std::cin.get();

            if (tolower(ch) == 'y')
            {
                file_i.close();
                
                write();
            }
	    else
	    {
	 	//TODO
	     }
        }
	else
	{
	    //TODO
	}
    }

    file_i.close();
}

void C_file::write()
{
    count = 0;

    file_o.open("g");
    if (!file_o.is_open())
    {
        std::cout << "no" << std::endl;
        exit(0);
    }

    std::cout << "name -> number" << std::endl;

    getline(std::cin, content);

    while (content != ".")
    {
	count++;
        file_o << content << std::endl;
        getline(std::cin, content);
	if (count % 2 == 0)
	{
	    var++;
	}
	//TODO if
    }

    name = new std::string[count - var];
    number = new std::string[count - var];

    file_o.close();

    fill();
}

void C_file::fill()
{
    ct = 1;
	
    file_i.open("g");
    if (!file_i.is_open())
    {
	std::cout << "no" << std::endl;
	exit(0);
    }

    while (file_i >> content)
    {
	if (ct % 2 == 0)
	{
	    number[key_nr] = content;
	    key_nr++;
	    ct++;
	}
	else
	{
	    name[key_nm] = content;
	    key_nm++;
	    ct++;
	}
    }
}
