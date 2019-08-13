#include "z.h"

cl::cl(const char* n)
{
    len = strlen(n);

    name = new char[len + 1];

    for (int key = 0; n[key] != '\0'; key++)
    {
	name[key] = n[key];
    }
}

cl::~cl()
{
    delete [] name;
}

int cl::strlen(const char* string)
{
    int length = 0, ch = 0;

    while (string[length] != '\0')
    {
        if (string[length] == ' ')
        {
            ++ch;
        }

        ++length;
    }

    return length - ch;										
}

char cl::operator[](int num)
{
    if (num > len)
    {
	return 'n';
    }

    return name[num];
}

void cl::operator==(const cl& t2_)	
{
    int len1 = strlen(name);
    char* name_met1 = new char[len1];

    for (int key = 0; name[key] != '\0'; key++)
    {
	name_met1[key] = name[key];
    }
	
    int len2 = strlen(t2_.name);
    char* name_met2 = new char[len2];

    for (int key = 0; t2_.name[key] != '\0'; key++)
    {
	name_met2[key] = t2_.name[key];
    }

    int res = 0;

    if (len1 != len2)
    {
	std::cout << "false" << std::endl;

	delete [] name_met1;
	delete [] name_met2;
     }
     else if (len1 == len2)
     {
	for (int key = 0; name_met1[key] != '\0'; key++)
	{
	    if (name_met1[key] != name_met2[key])
	    {
		std::cout << "false" << std::endl;
	    }
	    else if (name_met1[key] == name_met2[key])
	    {
		res++;
	    }
	}

	if (res == len1) std::cout << "true" << std::endl;
	else std::cout << "false" << std::endl;
	    
	delete [] name_met1;
	delete [] name_met2;
     }
}

void cl::operator>(const cl& t2_)
{
    int len1 = strlen(name);
    int len2 = strlen(t2_.name);

    if (len1 > len2) std::cout << "true" << std::endl;
    else std::cout << "false" << std::endl;
}

void cl::operator<(const cl& t2_)
{
    int len1 = strlen(name);
    int len2 = strlen(t2_.name);

    if (len1 < len2) std::cout << "true" << std::endl;
    else std::cout << "false" << std::endl;
}
