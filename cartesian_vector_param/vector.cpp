#include "vector.hh"

#include <algorithm>
#include <ostream>
#include <initializer_list>
#include <cassert>
#include <cstring>
#include <stdlib.h>

#include <memory>

Vector& Vector::operator+=(const Vector& rhs)
    {
        for (std::size_t i = 0; i < rhs.size(); i++) {
            (*_list)[i] += rhs[i];

            // _list->push_back(rhs[i]);
        }
            

        return *this;
    }

    Vector& Vector::operator+=(value value)
    {
        _list->push_back(value);

        return *this;
    }

    Vector& Vector::operator-=(const Vector& rhs)
    {
        for (int i = 0; i < _list->size(); i++) 
            (*_list)[i] -= rhs[i];
        return *this;
    }

    value &Vector::operator[](int index) const
    {
        return (*_list)[index];
    }

    value &Vector::operator[](int index)
    {
        return (*_list)[index];
    }

    Vector Vector::operator+(const Vector &other)
    {
        Vector x{};
        int idx = 0;

        for (int i = 0; i < other.size(); i++, idx++) { 
            int l = other[i], r;

            if (idx >= _list->size())
                r = 0;
            else
                r = (*_list)[idx];

            x += (l + r);
        }

        return x;
    }

    Vector Vector::operator*(const int n)
    {
        Vector x{};
        
        for (std::size_t i = 0; i < _list->size(); i++) 
            x += (*_list)[i] * n;

        return x;
    }

    Vector &Vector::operator*=(const int n)
    {
        for (std::size_t i = 0; i < _list->size(); i++) 
            (*_list)[i] *= n;

        return *this;
    }

    int Vector::operator*(const Vector &other)
    {
        int idx = 0;
        int res = 0;
        
        for (std::size_t i = 0; i < _list->size(); i++, idx++) 
            res += (other[i] * (*_list)[idx]);

        return res;
    }

    bool Vector::isEmpty() const
    {
        return _list->isEmpty();
    }

    std::size_t Vector::size() const
    {
        return _list->size();
    }

std::ostream& operator<<(std::ostream& os, const Vector& vector)
{
    if (vector.isEmpty())
    {
        os << "{}";
        return os;
    }

    os << "{";

    for (int i = 0; i < vector.size(); i++) 
    {
        os << vector[i];
        if (i + 1 != vector.size()) os << ",";
    }

    os << "}";

    return os;
}
