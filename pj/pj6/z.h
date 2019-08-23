class cl
{
private:
    char* name;
    int len;

public:
    cl(const char*);
    ~cl();

    int strlen(const char*);

    char operator[](int);
    void operator==(const cl&);
    void operator>(const cl&);
    void operator<(const cl&);
};

void copy(const char*, const char*);
