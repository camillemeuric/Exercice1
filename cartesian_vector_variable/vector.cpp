#include "vector.hh"

#include <iostream>
#include <ostream>

Vector::Vector(const Vector &v) {
    data = std::make_unique<value[]>(v.size());
    for (size_t i = 0; i < v.size() ; ++i) {
        data[i] = v[i];
    }
    size_v = v.size();
}

Vector& Vector::operator=(const Vector &v) {
    data = std::make_unique<value[]>(v.size());
    for (size_t i = 0; i < v.size() ; ++i) {
        data[i] = v[i];
    }
    size_v = v.size();
    return *this;
}


Vector::Vector(size_t N)
{
    size_v = N;
    data = std::make_unique<value[]>(N);
    for (size_t i = 0; i < size_v; i++) {
        data[i] = 0;
    }
   
}

Vector::Vector(std::initializer_list<value> list)
{
    size_v = list.size();
    data = std::make_unique<value[]>(list.size());
    size_t i = 0;
    for (auto elem : list) {
        data[i++] = elem;
    }
}
size_t Vector::size() const {
    return size_v;
}

// Public Member functions here
Vector& Vector::operator+=(const Vector& rhs) {
    if (size_v != rhs.size())
        std::runtime_error("Incompatible size");
    for (size_t i = 0; i < rhs.size(); i++) {
        data[i] = data[i] + rhs[i];
    }

    return *this;
}

Vector& Vector::operator-=(const Vector& rhs){
    if (size_v != rhs.size())
        std::runtime_error("Incompatible size");
    for (size_t i = 0; i < rhs.size(); i++) {
        data[i] =data[i] - rhs[i];
    }
    return *this;
}

Vector& Vector::operator+=(value v) {
    for (size_t i = 0; i < size_v; i++) {
        data[i] += v;
    }
    return *this;
}

Vector& Vector::operator*=(value v){
    for (size_t i = 0; i < size_v; i++) {
        data[i] *= v;
    }
    return *this;
}

Vector Vector::operator+(const Vector& rhs) const {
    if (size_v != rhs.size())
        std::runtime_error("Incompatible size");
    for (size_t i = 0; i < rhs.size(); i++) {
        data[i] += rhs[i];
    }
    return *this;
}

Vector Vector::operator+(value v) const {
    for (size_t i = 0; i < size_v; i++) {
        data[i] += v;
    }
    return *this;
}

value Vector::operator*(const Vector& rhs) const {
    if (size_v != rhs.size())
        std::runtime_error("Incompatible size");
    value v = 0;
    for (size_t i = 0; i < rhs.size(); i++) {
        v += data[i] * rhs[i];
    }
    return v;
}

Vector Vector::operator*(value v) const {
    for (size_t i = 0; i < size_v; i++) {
        data[i] *= v;
    }
    return *this;

}

value& Vector::operator[](size_t idx) {
    if (size_v < idx)
        std::runtime_error("Incompatible size");
    return data[idx];
}

value Vector::operator[](size_t idx) const {
    if (size_v < idx)
        std::runtime_error("Incompatible size");
    return data[idx];
}



// Nonmember function operators go here
Vector operator*(const value& s, const Vector& v) {
    Vector vv = Vector(v.size());
    for (size_t i = 0; i < v.size(); i++) {
        vv[i] = v[i] * s;
    }
    return vv;
}

Vector operator+(const value& s, const Vector& v) {
    Vector vv = Vector(v.size());
    for (size_t i = 0; i < v.size(); i++) {
        vv[i] = v[i] + s;
    }
    return vv;
}

std::ostream& operator<<(std::ostream& o, const Vector& v) {
    o << '{';
    int i;
    for (i = 0; i < v.size() - 1; i++) {
        o << v[i] << ',';
    }
    return o << v[i] << "}";
}