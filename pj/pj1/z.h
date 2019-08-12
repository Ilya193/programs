class Pj
{
private:
    std::string* name, new_name, temps, t;
    int* numbers, count, tempn, new_number, cl, ccs, c;
    char ch;

public:
    Pj();
    Pj(const Pj&);
    ~Pj();

    friend std::ostream& operator<<(std::ostream&, const Pj&);

    void fill();
    void display();
    void rewrite();
    void general_fun();
    void coincidences();
    bool ch_b_char();
    void clear();
};
