#ifndef HEADER_H
#define HEADER_H

#include <string>

class a
{
private:
    char* name_player;
    char* name_bot;
    static int win;
    static int lose;
public:
    a(const char*);
    virtual ~a();

    static void wn();
    static void ls();

    virtual void general() = 0;
protected:
    int len;
};

class gameplay : public a
{
private:
    std::string alphabet[11];
    int numbers[9];

    std::string implementation1[3][4];
    std::string implementation2[3][4];
    std::string implementation3[3][4]; // для теста бота

    int choise;
    int count;
    int access;
    std::string turn;

    int main_count;
public:
    gameplay(const char*);

    void general();
    void map();
    void player_turn();

    void imp1();
    void imp2();
    void imp3();

    void check();
};














#endif // HEADER_H
