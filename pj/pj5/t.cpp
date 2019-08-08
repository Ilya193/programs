#include "z.h"

Lesson::Lesson()
{
    str_file = new std::string[0];
}

Lesson::Lesson(int size)
{
    str_file = new std::string[size];
}

Lesson::~Lesson()
{
    delete [] str_file;
}

void Lesson::operator<<(const std::string& ipt)
{
    this->str_file[key] = ipt;

    key++;
}

std::ostream& operator<<(std::ostream& os, const Lesson& l)
{
    int temp = 0;

    if (temp < l.key)
    {	
    	os << l.str_file[temp];
    }

    temp++;

    return os;
}
