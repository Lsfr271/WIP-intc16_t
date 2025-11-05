#ifndef INTC
#define INTC

#pragma once

#include <iostream>
#include <cstdint>
#include <sstream>
#include <iomanip>
#include <fstream>


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

        uint16_t getValue() const;
        uint16_t getValueFromFile(const std::string& filename,
        size_t position) const;


        bool isZero() const;
        bool checkIfMax() const;
        bool isbitset(int pos) const;

        void showMemAddress();
        void setbit(int pos);
        void clearbit(int pos);
        void togglebit(int pos);
        void appToFile(const std::string& filename) const;
        void overwriteFile(const std::string& filename) const;

        size_t countRecords(const std::string& filename) const;

        int toInt();
        int bitCount() const;
        int countsetbits();
        int highestbit() const;
        int lowestbit() const;

        std::string toBin();
        std::string toHex();



        /* TEMPLATE FUNCTIONS */
        template<class A>
        bool inRange(const A& v1, const A& v2) const {
            if ((val16 > v1) && (val16 < v2)){
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
};

#endif
