#include "intc16.hpp"

void intc16_t::showMemAddress(){
    void* address = static_cast<void*>(&val16);

    std::cout << "(16) Memory address: " << address << "\n";
}

uint16_t intc16_t::getValue() const {
    return val16;
}

bool intc16_t::isZero() const {
    if (val16 == 0){
        return true;
    }

    return false;
}

int intc16_t::toInt(){
    return static_cast<int>(val16);
}

bool intc16_t::checkIfMax() const {
    if (val16 >= MAXIMUM_SIZE16){
        return true;
    }

    return false;
}

int intc16_t::bitCount(){
    int count = 0;
    auto n = val16;

    while (n > 0){
        count++;
        n >>= 1;
    }

    return count;
}

bool intc16_t::isbitset(int pos){
    if ((val16 & (1 << pos)) != 0){
        return true;
    }

    return false;
}


void intc16_t::setbit(int pos){
    val16 |= (1 << pos);
}

void intc16_t::clearbit(int pos){
    val16 &= ~(1 << pos);
}

void intc16_t::togglebit(int pos){
    val16 ^= (1 << pos);
}

int intc16_t::countsetbits(){
    int count = 0;
    int n = val16;

    while (n){
        count += n & 1;
        n >>= 1;
    }

    return count;
}

int intc16_t::highestbit(){
    int pos = -1;
    int n = val16;

    while (n){
        n >>= 1;
        pos++;
    }

    return pos;
}

int intc16_t::lowestbit(){
    for (int i = 0; i < 16; i++){
        if (val16 & (1 << i)){
            return i;
        }
    }

    return -1;
}


std::string intc16_t::toBin(){
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

std::string intc16_t::toHex(){
    std::stringstream ss;

    ss << std::hex << std::setw(4) << std::setfill('0') << val16;

    return ss.str();
}
