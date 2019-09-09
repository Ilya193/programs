#include <iostream>
#include "header.h"

int a::win = 0;
int a::lose = 0;

a::a(const char* name)
{
    len = strlen(name);

    name_player = new char[len + 1];
    strcpy(name_player, name);

    len = strlen("bot");
    name_bot = new char[len + 1];
    strcpy(name_bot, "bot");
}

a::~a()
{
    delete[] name_player;
    delete[] name_bot;
}

gameplay::gameplay(const char* n) : a(n)
{
    alphabet[0] = "a";
    alphabet[1] = "b";
    alphabet[2] = "c";
    alphabet[3] = "d";
    alphabet[4] = "e";
    alphabet[5] = "f";
    alphabet[6] = "g";
    alphabet[7] = "h";
    alphabet[8] = "i";
    alphabet[9] = "j";
    alphabet[10] = "k";

    for (int key = 0; key < 9; key++)
    {
        numbers[key] = key + 1;
    }

    access = 0;
    main_count = 0;
}

void gameplay::general()
{
    char ch;
    std::cout << "s - start, w - win, l - lose: ";
    std::cin >> ch;
    std::cin.get();

    if (ch == 's')
    {
        map();
        player_turn();
    }
    else if (ch == 'w')
    {

    }
    else if (ch == 'l')
    {

    }
}

void gameplay::map()
{
    std::cout << "choise numbers map: ";
    std::cin >> choise;
    std::cin.get();

    if (choise == 1)
    {
        imp1();
    }
    else if (choise == 2)
    {
        //imp2();
    }
    else if (choise == 3)
    {
        //imp3();
    }
}

void gameplay::player_turn()
{
    std::cout << "your turn: ";
    std::cin >> turn;

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            if (turn == implementation3[x][y])
            {
                std::cout << "yes!" << std::endl;
                implementation3[x][y] = " ";
                break;
            }
        }
    }

    check();
    // ход бота
}

void gameplay::check()
{

}

void gameplay::imp1()
{
    implementation3[0][0] = "a6"; // трехпалубный (a6, a7, a8)
    implementation3[0][1] = "a7";
    implementation3[0][2] = "a8";

    implementation3[1][0] = "e4"; // двухпалубный (e4, e5)
    implementation3[1][1] = "e5";

    implementation3[2][0] = "k5"; // четырехпалубный (k5, k6, k7, k8)
    implementation3[2][1] = "k6";
    implementation3[2][2] = "k7";

    std::cout << "map enemy's" << std::endl;
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            std::cout << alphabet[x];
            std::cout << numbers[y];
            std::cout << " ";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    implementation1[0][0] = "a1"; // трехпалубный
    implementation1[0][1] = "a2";
    implementation1[0][2] = "a3";

    implementation1[1][0] = "e2"; // двухпалубный
    implementation1[1][1] = "e3";

    implementation1[2][0] = "i6"; // четырехпалубный
    implementation1[2][1] = "i7";
    implementation1[2][2] = "i8";
    implementation1[2][3] = "i9";

    std::cout << "your map" << std::endl;
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            if (x == 0)
            {
                if (y == 0 || y == 1 || y == 2)
                {
                    std::cout << "t  ";
                }
                else
                {
                    std::cout << alphabet[x];
                    std::cout << numbers[y];
                    std::cout << " ";
                }
            }
            else if (x == 4)
            {
                if (y == 1 || y == 2)
                {
                    std::cout << "t  ";
                }
                else
                {
                    std::cout << alphabet[x];
                    std::cout << numbers[y];
                    std::cout << " ";
                }
            }
            else if (x == 8)
            {
                if (y == 5 || y == 6 || y == 7 || y == 8)
                {
                    std::cout << "t  ";
                }
                else
                {
                    std::cout << alphabet[x];
                    std::cout << numbers[y];
                    std::cout << " ";
                }
            }
            else
            {
                std::cout << alphabet[x];
                std::cout << numbers[y];
                std::cout << " ";
            }
        }

        std::cout << std::endl;
    }
}










