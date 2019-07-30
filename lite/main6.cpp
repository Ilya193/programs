#include <iostream>
#include <fstream>

struct file
{
    char filename[15];
    std::ofstream file1;
    std::ifstream file2;
};

void fill(file*, double* numbers, int size);
void show(file*, double* numbers, int size);
void (*ps)(file*, double* numbers, int size);

int main()
{
    file t1;

    int size;
    std::cin >> size;
    std::cin.get();

    double* numbers = new double[size];

    fill(&t1, numbers, size);
 
    return 0;
}

void fill(file* t2, double* numbers, int size)
{
    file* t3 = t2;

    double temp;

    int x = 0;
    while (x < size && std::cin >> temp)
    {
        if (x < size)
        {
            numbers[x] = temp;
            ++x;
        }
    }
    
    std::cin.get();
    std::cin.getline(t3->filename, 15);
    
    t3->file1.open(t3->filename);

    if (!t3->file1.is_open()) exit(EXIT_FAILURE);

    int count = 0;
    while (count < size)
    {
        t3->file1 << numbers[count] << std::endl;
        ++count;
    }

    ps = show;
    (*ps)(t3, numbers, size);

    t3->file1.close();
}

void show(file* t3, double* numbers, int size)
{
    t3->file2.open(t3->filename);

    double temp;
    std::cout << "file: " << std::endl;
    while (t3->file2 >> temp)
    {
        std::cout << temp << std::endl;
    }

    std::cout << "arr: " << std::endl;
    for (int x = 0; x < size; x++)
    {
        std::cout << numbers[x] << std::endl;
    }

    t3->file2.close();
}
