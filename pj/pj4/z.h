class List
{
private:
    double* numbers;
    int max, top, temp;
    char ch;

public:
    List(int);
    void append(int);
    void isempty();
    void isfull();
    void show();
    void resize_list();
    void general_fun();
};
