#include "prototype.h"

Str::Str() : m_ptr{new char[1]}, m_size{}
{
    m_ptr[0] = '\0';
};

Str::Str(const char* ptr)
{
    if(ptr == nullptr)
    {
        m_ptr = new char[1];
        m_ptr[0] = '\0';
        m_size = 0;
    }
    else
    {
        size_t count_str{};
        while(ptr[count_str] != '\0')
        {
            ++count_str;
        }

        m_ptr = new char[count_str + 1];
        for(int i{}; i < count_str; ++i)
        {
            m_ptr[i] = ptr[i];
            ++m_size;
        }

        m_ptr[count_str] = '\0';
    }
}

Str::Str(const Str& rhs)
{
    this->m_ptr = new char[rhs.m_size];
    for(int i{}; i < rhs.m_size; ++i)
    {
        this->m_ptr[i] = rhs.m_ptr[i];
    }
    this->m_size = rhs.m_size;
}

Str& Str::operator= (const Str& rhs)
{
    if(this == &rhs)
    {
        return *this;
    }
    this->m_ptr = new char[rhs.m_size];
    for(int i{}; i < rhs.m_size; ++i)
    {
        this->m_ptr[i] = rhs.m_ptr[i];
    }
    this->m_size = rhs.m_size;
    return *this;
}

Str::Str(Str&& rhs)
{
    this->m_ptr = rhs.m_ptr;
    this->m_size = rhs.m_size;
    rhs.m_ptr = nullptr;
}

Str& Str::operator= (Str&& rhs)
{
    if(this == &rhs)
    {
        return *this;
    }
    this->m_ptr = rhs.m_ptr;
    this->m_size = rhs.m_size;
    rhs.m_ptr = nullptr;
    return *this;
}

Str::~Str()
{
    delete this->m_ptr;
    m_ptr = nullptr;
}

Str& Str::operator+(const Str& rhs)
{
    for(int i{}; i < rhs.m_size; ++i)
    {
        this->m_ptr[m_size] = rhs.m_ptr[i];
        this->m_size++;
    }
    this->m_ptr[m_size] = '\0';
    return *this;
}

const char Str::operator[] (size_t index)
{
    return this->m_ptr[index];
}

size_t Str::find(const char elem)
{
    size_t index{};
    for(int i{}; i < this->m_size; ++i)
    {
        if(this->m_ptr[i] == elem)
        {
            return index;
        }
        index++;
    }
    return -1;
}

char Str::pop_back()
{
    if(m_size)
    {   
        char tmp = this->m_ptr[m_size - 1];
        --m_size;
        this->m_ptr[m_size] = '\0';
        return tmp;
    }
    return '\0';
}

size_t Str::getline()
{
    return this->m_size;
}

void Str::push_back(const char elem)
{
    this->m_ptr[m_size] = elem;
    m_size++;
    this->m_ptr[m_size] = '\0';
}


Polar::Polar(){};

Polar::Polar(double x,double y)
{
    m_angle = y;
    m_radius = x;
}

Polar::~Polar(){};


void Polar::set_info(double x,double y)
{
    this->m_radius = x;
    this->m_angle = y;
}

void Polar::get_info()
{
    std::cout << "radius is: " << m_radius << std::endl;
    std::cout << "angle is: " << m_angle << std::endl;
}


Polar& Polar::operator+(Polar& other)
{
    Polar tmp;
    tmp.m_angle = this->m_angle += other.m_angle;
    tmp.m_radius = this->m_radius += other.m_radius;
    return tmp;
}


class Employee
{
    public:
    Employee();
    void set_data();
    void put_data();


    private:
        std::string m_name;
        static long m_id;
        int count_id {};

};


//composition

class Person{
    public:
        Person(){};
        Person(int){};
    private:
        int m_x;
        class Name{
            Name(){};
            ~Name(){};
        };
};



//aggregation


class Person{
    public:
        Person();
        Person(int);
    private:
        int m_x;
        Name obj;
        
};

class Name{
            Name(){};
            ~Name(){};
        };


//association


class Person{
    public:
        Person(){};
        Person(int){};
    private:
        int m_x;
        Name& foo(Name&){};
        
};

class Name{
            Name(){};
            ~Name(){};
        };