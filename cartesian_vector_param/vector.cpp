#include "vector.hh"

#include <iostream>
#include <ostream>

size_t Vector::get_size() const
{
    return size;
}

Vector::Vector()
{
    size = NDIM;
    for (size_t i = 0; i < size; i++)
    {
        data[i] = 0;
    }
}

Vector::Vector(std::initializer_list<value> list)
{
    size = list.size();
    size_t i = 0;
    for (auto &elem : list)
    {
        data[i++] = elem;
    }
}


Vector &Vector::operator+=(const Vector &rhs)
{
    for (size_t i = 0; i <  rhs.get_size(); i++)
    {
        data[i] = data[i] + rhs[i];
    }
    return *this;
}

Vector &Vector::operator-=(const Vector &rhs)
{
    for (size_t i = 0; i <  rhs.get_size(); i++)
    {
        data[i] = data[i] - rhs[i];
    }
    return *this;
}

Vector Vector::operator+(const Vector &rhs)
{
    auto v = Vector();
    for (size_t i = 0; i <  rhs.get_size(); i++)
    {
        v[i] = rhs[i] + (*this)[i];
    }
    return v;
}

Vector Vector::operator-(const Vector &rhs)
{
    auto v = Vector();
    for (size_t i = 0; i <  rhs.get_size(); i++)
    {
        v[i] = rhs[i] - (*this)[i];
    }
    return v;
}

value Vector::operator*(const Vector &rhs)
{
    value v = 0;
    for (size_t i = 0; i <  rhs.get_size(); i++)
    {
        v += rhs[i] * (*this)[i];
    }
    return v;
}

value Vector::operator[](size_t i) const
{
    return data[i];
}

value &Vector::operator[](size_t i)
{
    return data[i];
}

Vector operator*(Vector &rhs, const value n)
{
    auto v = Vector();
    for (size_t i = 0; i <  rhs.get_size(); i++)
    {
        v[i] = rhs[i] * n;
    }
    return v;
}

Vector operator*=(Vector &rhs, const value n)
{
    for (size_t i = 0; i <  rhs.get_size(); i++)
    {
        rhs[i] = rhs[i] * n;
    }
    return rhs;
}

Vector operator+=(Vector &rhs, const value n)
{
    for (size_t i = 0; i <  rhs.get_size(); i++)
    {
        rhs[i] = rhs[i] + n;    
    }
    return rhs;
}

std::ostream& operator<<(std::ostream &os, const Vector& rhs)
{
    os << "{";
    for (int i = 0; i < rhs.get_size(); i++)
    {
        os << rhs[i] << (i == rhs.get_size() - 1 ? "" : ",");
    }
    return os << "}";
}