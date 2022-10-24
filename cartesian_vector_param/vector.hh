#pragma once

#include <ostream>
#include "config.h"

class Vector{
public:
// DO NOT CHANGE THIS
    Vector(const Vector&) = default;
    Vector& operator=(const Vector&) = default;
    ~Vector() = default;
//

// Add suitable constructors
    Vector();
    Vector(std::initializer_list<value> list);
    // possibly more

// Public Member functions here
    Vector &operator+=(const Vector &rhs);
    Vector &operator-=(const Vector &rhs);
    // More to go
    size_t get_size() const;
    Vector operator+(const Vector &rhs);
    Vector operator-(const Vector &rhs);
    value operator*(const Vector &rhs);
    value operator[](size_t i) const;
    value& operator[](size_t i);

private:
    // Private Member functions here
    value data[NDIM];
    size_t size;
    // Member variables are ALWAYS private, and they go here
};

// Nonmember function operators go here
Vector operator*(Vector &rhs, const value n);
Vector operator*=(Vector &rhs, const value n);
Vector operator+=(Vector &rhs, const value n);
std::ostream& operator<<(std::ostream &os, const Vector &rhs);