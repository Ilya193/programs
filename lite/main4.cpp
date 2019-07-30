#include <iostream>
#include <fstream>

struct file
{
    std::ofstream file1;
    std::ifstream file2;
    char filename[15];
    double num;
    int count = 0;
};

void fun(file*);
void view(file*);

int main()
{
    fail s;
    
    fun(&s);

    view(&s);

    return 0;
}

void fun(file* s)
{
    std::cin >> s->filename;

    s->file1.open(s->filename);
    if (!s->file1.is_open()) exit(EXIT_FAILURE);

    for (int key = 0; key < 3; key++) 
    {
        std::cin >> s->num; 
        s->file1 << s->num << std::endl;
    }

    s->file2.open(s->filename);
    if (!s->file2.is_open()) exit(EXIT_FAILURE);

    for (int key = 0; key < 3; key++)
    {
        s->file2 >> s->num;
        ++s->count;
    }

    s->file1.close();
    s->file2.close();
}

void view(file* s)
{
    std::cout << "count: " << s->count << std::endl;
}
