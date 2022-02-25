#include<iostream>
#include<ostream>

class Str
{
public:
    Str();
    Str(const char*);
    Str(const Str&);
    Str& operator= (const Str&);
    Str(Str&&);
    Str& operator= (Str&&);
    const char operator[](size_t);
    ~Str();

public:
    size_t getline();
    char pop_back();
    void push_back(const char);
    void insert(size_t,const Str&);
    void at();
    size_t find(const char);

public:
    Str& operator+ (const Str&);
    friend std::ostream& operator<< (std::ostream& os,const Str& rvalue)
    {
        os << rvalue.m_ptr;
        return os;
    }
private:
    char* m_ptr{};
    size_t m_size{};
};



class Polar
{
public:
    Polar();
    Polar(double,double);
    ~Polar();
    
public:
    void set_info(double,double);
    void get_info();
    Polar& operator+(Polar&);
    
private:
    double m_radius {};
    double m_angle {};
};