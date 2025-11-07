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

    std::cout << a.evenParity() << "\n";
    std::cout << b.isMin() << "\n";

    intc16_t c = a.rotateLeft(3);
    intc16_t d = a.rotateRight(3);

    std::cout << c.toBin() << "\n";
    std::cout << d.toBin() << "\n";

    intc16_t e = a.reverseBits();

    std::cout << e.toBin() << "\n";
    std::cout << a.leadingZero() << "\n";
    std::cout << a.trailingZero() << "\n";

    std::cout << "before swap: a=" << a.getValue() << ", b=" << b.getValue() << "\n";
    a.swap(b);
    std::cout << "after swap: a=" << a.getValue() << ", b=" << b.getValue() << "\n";

    a.appToBinFile("test/data.bin");
    b.appToBinFile("test/data.bin");

    uint16_t binVal0 = a.getValueFromBinFile("test/data.bin", 0);
    uint16_t binVal1 = b.getValueFromBinFile("test/data.bin", 1);

    std::cout << "bin file pos0: " << binVal0 << ", pos1: " << binVal1 << "\n";

    a.appToHexFile("test/data.hex");
    b.appToHexFile("test/data.hex");

    uint16_t hexVal0 = a.getValueFromHexFile("test/data.hex", 0);
    uint16_t hexVal1 = b.getValueFromHexFile("test/data.hex", 0);

    std::cout << "hex file pos0: " << hexVal0 << ", pos1: " << hexVal1 << "\n";

    intc16_t** arr = new intc16_t*[10];

    for (int i = 0; i < 10; ++i){
        arr[i] = new intc16_t(i);
    }

    intc16_t obj;
    obj.a_delptr(arr, 10);

    std::cout << a.isOdd() << a.isEven() << "\n";
    std::cout << b.isOdd() << b.isEven() << "\n";

    std::cout << a.isPalindromeB() << a.isPalindromeH() << "\n";
    std::cout << b.isPalindromeB() << b.isPalindromeH() << "\n";

    intc16_t f(200);
    intc16_t g(300);

    uint16_t h = 956;

    std::cout << a.equals(f) << "\n";
    std::cout << a.m_equals(f, g, '+') << "\n";
    std::cout << a.hasBitPatttern(h) << "\n";

    a.pow(2, 5);

    std::cout << a.val16 << "\n";

    std::cout << a.i_sqrt(10) << "\n";
}
