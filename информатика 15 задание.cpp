#include <iostream>
#include <string>

std::string fun()
{
    std::string temp;
    getline(std::cin, temp);
    return temp;
}

int main()
{
    std::string input_str;
    int res = 0;
    
    while((input_str = fun()) != ".")
    {
        res += atoi(input_str.c_str());
    }
    
    std::cout << "res: " << res << std::endl;
    
    return 0;
}
