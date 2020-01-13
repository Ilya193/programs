#include <iostream>

template <typename t>
class pointer_
{
private:
    t* p;
    static int count;

    static void settingsi()
    {
        count++;
    }

    static void settingsd()
    {
        count--;
    }

public:
    pointer_(t* m)
    {
        p = m;
        settingsi();
    }

    pointer_(pointer_& p2)
    {
        p2.settingsi();

        p = p2.p;
    }

    ~pointer_()
    {   
        if (count == 1)
        {
            delete[] p;
        }
        else
        {
            settingsd();
        }
    }

    t* operator&() const
    {
        return p;
    }

    t& operator*() const
    {
        return *p;
    }

    void operator=(t n)
    {
        *p = n;
    }

    t* operator->() const
    {
        return p;
    }

    friend std::ostream& operator<<(std::ostream& os, pointer_& point)
    {
        os << *point.p;

        return os;
    }
};

template <typename t>
int pointer_<t>::count = 0;
