class Lesson
{
private:
    std::string* str_file;
    int key = 0;

public:
    Lesson();
    Lesson(int);
    ~Lesson();

    void operator<<(const std::string&);
    friend std::ostream& operator<<(std::ostream&, const Lesson&);
};
