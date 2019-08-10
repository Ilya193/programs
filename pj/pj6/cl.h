class C_file
{
private:
    std::ofstream file_o;
    std::ifstream file_i;

    std::string* name;
    std::string* number;

    char ch;

    std::string content;
    int count;
    int ct;
    int key_nm;
    int key_nr;
    int var;

public:
    C_file();

    void read();
    void write();
    void fill();
};
