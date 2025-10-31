#ifndef INTC
#define INTC

#pragma once

#include <iostream>
#include <cstdint>
#include <sstream>
#include <iomanip>

struct intc16_t {
    private:
        static constexpr uint16_t MAXIMUM_SIZE16 = 65535;
        /*
        MAXIMUM_SIZE16 must be private because it can be changed if its public.
        */

    public:
        uint16_t val16 = 0; // public if it needs to be changed manually.

        intc16_t(uint16_t u) : val16(u) {};
        intc16_t() {};

        void showMemAddress(){
            void* address = static_cast<void*>(&val16);

            std::cout << "(16) Memory address: " << address << "\n";
        }

        uint16_t getValue() const {
            return val16;
        }

        bool isZero() const {
            if (val16 == 0){
                return true;
            }

            return false;
        }

        template<class A>
        bool inRange(const A& v1, const A& v2) const {
            if ((val16 > v1) && (val16 < v2)){
                return true;
            }

            return false;
        }

        int toInt(){
            return static_cast<int>(val16);
        }

        bool checkIfMax() const {
            if (val16 >= MAXIMUM_SIZE16){
                return true;
            }

            return false;
        }

        template<class T>
        void add(T other) {
            int result = val16 + other;

            if (result > MAXIMUM_SIZE16) {
                val16 = MAXIMUM_SIZE16;
            }
            else {
                val16 = result;
            }
        }

        template<class T>
        void subtract(T other) {
            int result = val16 - other;

            if (result < 0) {
                val16 = 0;
            }
            else {
                val16 = result;
            }
        }

        template<class T>
        void multiply(T other) {
            int result = val16 * other;

            if (result > MAXIMUM_SIZE16) {
                val16 = MAXIMUM_SIZE16;
            }
            else {
                val16 = result;
            }
        }

        template<class T>
        void divide(T other) {
            if (other == 0) {
                throw std::invalid_argument("Cannot divide by zero.");
            }
            else {
                val16 = val16 / other;
            }
        }

        int bitCount(){
            int count = 0;
            auto n = val16;

            while (n > 0){
                count++;
                n >>= 1;
            }

            return count;
        }

        bool isbitset(int pos){
            if ((val16 & (1 << pos)) != 0){
                return true;
            }

            return false;
        }


        void setbit(int pos){
            val16 |= (1 << pos);
        }

        void clearbit(int pos){
            val16 &= ~(1 << pos);
        }

        void togglebit(int pos){
            val16 ^= (1 << pos);
        }

        int countsetbits(){
            int count = 0;
            int n = val16;

            while (n){
                count += n & 1;
                n >>= 1;
            }

            return count;
        }

        int highestbit(){
            int pos = -1;
            int n = val16;

            while (n){
                n >>= 1;
                pos++;
            }

            return pos;
        }

        int lowestbit(){
            for (int i = 0; i < 16; i++){
                if (val16 & (1 << i)){
                    return i;
                }
            }

            return -1;
        }

        std::string toBin(){
            std::string binString = "";

            for (int i = 15; i >= 0; --i){
                // iterate from (bit 15) to bit 0
                // right shift and check the least significant bit
                if ((val16 >> i) & 1){
                    binString += '1';
                }
                else {
                    binString += '0';
                }
            }

            return binString;
        }

        std::string toHex(){
            std::stringstream ss;

            ss << std::hex << std::setw(4) << std::setfill('0') << val16;

            return ss.str();
        }
};

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

#endif
