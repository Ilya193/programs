class Pj
{
private:
    std::string* name, new_name, temps, t;
    int* numbers, count, tempn, new_number, cl, ccs, c, count_f, ts;

    std::string test_test;

    char ch;

    std::ofstream file_o;
    std::ifstream file_i;
    std::string content;

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

    void file_read();
    void file_write();
    void file_fill();
};
