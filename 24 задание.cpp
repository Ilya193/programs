#include <iostream>
#include <fstream>

int max(int n1, int n2)
{
    if (n1 > n2)
        return n1;
    
    return n2;
}

int main()
{
    std::string main_str;
    std::ifstream file("24.txt");
    int main_count = 0, count = 0;
    
    getline(file, main_str);
    
    for (int i = 0; i < main_str.length(); i++)
    {
        if (main_str[i] == 'Y')
        {
            count++;
        }
        else
        {
            main_count = max(main_count, count);
            count = 0;
        }
    }
    
    std::cout << main_count << std::endl;

    file.close();
    
    return 0;
}
