class List
{
private:
    double* numbers;
    int max, top, temp;
    char ch;

public:
    List(int);
    void isempty();
    void isfull();
    void out();
    void resize_list();
    void general_fun();
};
