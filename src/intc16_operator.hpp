#ifndef INTC_OPERATORS
#define INTC_OPERATORS

#pragma once

#include "intc16.hpp"

/* OPERATOR OVERLOADS */
std::ostream& operator<<(std::ostream& os, const intc16_t& obj){
    os << static_cast<int>(obj.val16);

    return os;
}

intc16_t operator>>(const intc16_t& lhs, int shift){
    return intc16_t(lhs.val16 >> shift);
}

intc16_t operator<<(const intc16_t& lhs, int shift){
    return intc16_t(lhs.val16 << shift);
}

bool operator==(const intc16_t& lhs, const intc16_t& rhs){
    return lhs.val16 == rhs.val16;
}

intc16_t operator&(const intc16_t& lhs, const intc16_t& rhs){
    return intc16_t(lhs.val16 & rhs.val16);
}

intc16_t operator~(const intc16_t& obj){
    return intc16_t(~obj.val16);
}

bool operator!=(const intc16_t& lhs, const intc16_t& rhs){
    return lhs.val16 != rhs.val16;
}

intc16_t& operator&=(intc16_t& lhs, const intc16_t& rhs){
    lhs.val16 &= rhs.val16;

    return lhs;
}

std::istream& operator>>(std::istream& is, intc16_t& obj){
    unsigned int temp;

    is >> temp; // read into temp uint
    obj.val16 = temp; // assign to val16

    return is;
}

intc16_t operator+(const intc16_t& lhs, const intc16_t& rhs){
    return intc16_t(lhs.val16 + rhs.val16);
}

intc16_t operator-(const intc16_t& lhs, const intc16_t& rhs){
    return intc16_t(lhs.val16 - rhs.val16);
}

intc16_t operator*(const intc16_t& lhs, const intc16_t& rhs){
    return intc16_t(lhs.val16 * rhs.val16);
}

intc16_t operator/(const intc16_t& lhs, const intc16_t& rhs){
    if (rhs.val16 == 0){
        throw std::invalid_argument("Division by zero error.");
    }
    else {
        return intc16_t(lhs.val16 / rhs.val16);
    }
}

bool operator>(const intc16_t& lhs, const intc16_t& rhs){
    return lhs.val16 > rhs.val16;
}

bool operator<(const intc16_t& lhs, const intc16_t& rhs){
    return lhs.val16 < rhs.val16;
}

intc16_t operator|(const intc16_t& lhs, const intc16_t& rhs){
    return intc16_t(lhs.val16 | rhs.val16);
}

intc16_t operator^(const intc16_t& lhs, const intc16_t& rhs){
    return intc16_t(lhs.val16 ^ rhs.val16);
}

intc16_t& operator+=(intc16_t& lhs, const intc16_t& rhs){
    int result = lhs.val16 + rhs.val16;

    if (result > 65535){
        lhs.val16 = 65535;
    }
    else {
        lhs.val16 = result;
    }

    return lhs;
}

intc16_t& operator-=(intc16_t& lhs, const intc16_t& rhs){
    int result = lhs.val16 - rhs.val16;

    if (result < 0){
        lhs.val16 = 0;
    }
    else {
        lhs.val16 = result;
    }

    return lhs;
}

intc16_t& operator*=(intc16_t& lhs, const intc16_t& rhs){
    int result = lhs.val16 * rhs.val16;

    if (result > 65535){
        lhs.val16 = 65535;
    }
    else {
        lhs.val16 = result;
    }

    return lhs;
}

intc16_t& operator/=(intc16_t& lhs, const intc16_t& rhs){
    if (rhs.val16 == 0){
        throw std::invalid_argument("Division by zero error.");
    }
    else {
        lhs.val16 = lhs.val16 / rhs.val16;
    }

    return lhs;
}

intc16_t& operator|=(intc16_t& lhs, const intc16_t& rhs){
    lhs.val16 |= rhs.val16;

    return lhs;
}

intc16_t& operator^=(intc16_t& lhs, const intc16_t& rhs){
    lhs.val16 ^= rhs.val16;

    return lhs;
}

intc16_t& operator<<=(intc16_t& lhs, int shift){
    lhs.val16 <<= shift;

    return lhs;
}

intc16_t& operator>>=(intc16_t& lhs, int shift){
    lhs.val16 >>= shift;

    return lhs;
}

intc16_t operator+(const intc16_t& obj){
    return obj; // unary plus
}

intc16_t operator-(const intc16_t& obj){
    return intc16_t(-static_cast<int>(obj.val16)); // returns signed negation
}

#endif
