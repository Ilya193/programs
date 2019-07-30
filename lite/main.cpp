#include <iostream>

struct society
{
    char name[20];
    double sum = 0.0;	
};

int main()
{
    int count = 0;
    std::cin >> count;
    std::cin.get();

    society* user = new society[count];

    for (int key = 0; key < count; key++)
    {
        std::cin.getline(user[key].name, 20);
	std::cin >> user[key].sum;
	std::cin.get();
    }

    std::cout << "grand patrons: " << std::endl;

    for (int key = 0; key < count; key++)
    {
	if (user[key].sum >= 10000.0)
	{
	    std::cout << user[key].name << std::endl;
	    std::cout << user[key].sum << std::endl;
	}
	else std::cout << "none" << std::endl;
    }

    std::cout << "patrons: " << std::endl;

    for (int key = 0; key < count; key++)
    {
        if (user[key].sum >= 0.0 && user[key].sum < 10000.0)
	{
	    std::cout << user[key].name << std::endl;
	    std::cout << user[key].sum << std::endl;
	}
	else std::cout << "none" << std::endl;
    }

    return 0;
}
