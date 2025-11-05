#include "../include/intc16/intc16.hpp"

int main() {
    // create the objects
    intc16_t a(100);
    intc16_t b;

    std::cout << a.getValue() << "\n";
    std::cout << a.toInt() << "\n";

    std::cout << b.isZero() << "\n";
    std::cout << a.checkIfMax() << "\n";

    std::cout << a.bitCount() << "\n";
    std::cout << a.countsetbits() << "\n";
    std::cout << a.highestbit() << "\n";
    std::cout << a.lowestbit() << "\n";

    std::cout << a.isbitset(0) << "\n";

    b.setbit(0); // sets LSB
    b.setbit(3); // sets 4th bit

    std::cout << "b after setbit: " << b.toBin() << "\n";

    b.clearbit(0); // clears LSB

    std::cout << "b after clearbit: " << b.toBin() << "\n";

    b.togglebit(3);

    std::cout << "b after togglebit: " << b.toBin() << "\n";

    std::cout << a.toBin() << "\n";
    std::cout << b.toHex() << "\n";

    a.showMemAddress();
    b.showMemAddress();

    a.appToFile("test/records.txt"); // appends 100
    b.appToFile("test/records.txt"); // appends 0

    uint16_t val0 = a.getValueFromFile("test/records.txt", 0);
    uint16_t val1 = b.getValueFromFile("test/records.txt", 1);

    std::cout << "pos 0: " << val0 << ", pos 1: " << val1 << "\n";

    a.add(50);
    std::cout << "a+50: " << a.getValue() << "\n";

    a.subtract(20);
    std::cout << "a-50: " << a.getValue() << "\n";

    a.multiply(2);
    std::cout << "a*2: " << a.getValue() << "\n";

    a.divide(4);
    std::cout << "a/4: " << a.getValue() << "\n";

    std::cout << a.inRange(60, 200) << "\n";
    std::cout << a.inRange(20, 500) << "\n";
    std::cout << a.inRange(60, 120) << "\n";

    size_t lines = a.countRecords("test/records.txt");

    std::cout << lines;

    a.val16 = 500;
    a.overwriteFile("test/records.txt");

    size_t line2 = a.countRecords("test/records.txt");

    std::cout << line2;
}
