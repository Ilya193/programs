#ifndef Z_H_
#define Z_H_

class MyClass
{
private:
    int* numbers1;
    int* numbers2;
    int l;
    int t;

public:
    MyClass();
    ~MyClass();
    
    void fill(int);
    void show();
    
    friend std::ostream& operator<<(std::ostream&, const MyClass&);
};

#endif
