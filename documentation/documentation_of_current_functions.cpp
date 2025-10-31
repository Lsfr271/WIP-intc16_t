/*
DOCUMENTATION OF ALL FUNCTIONS CURRENTLY IN intc16_t.hpp

You can spread this software anywhere you like and you can modify it.
*/

/* (Operator overloading wont be explained here) */

/* includes:
{
iostream,
cstdint,
sstream,
iomanip
}
*/

// the datatype is called intc16_t.

/*
So we will first start with the maximum size for the entire datatype, its 65535 because its 16-bit
and its unsigned so no negative numbers allowed.

If your wondering why its static constexpr instead of const because variables which use
intc16_t gain static storage duration, meaning they exist for the lifetime of the program.

The main value for now is called val16. It can be changed manually or changed when enclosed in parantheses,
constructor exists as well.

You can either do:

intc16_t ex(10); // to set the val16 amount

OR 

intc16_t ex;

ex.val16 = 10; // set the val16 amount manually.

Next we got showMemAddress(). What it does it basically shows the memory address of val16 by casting it as a void pointer to a variable then printing
the memory address.

Next we have getValue(). Pretty simple, it returns the value of val16 as an uint16_t because intc16_t is based on uint16_t.

Next we have isZero(). It checks if val16 is 0. Returns true if val16 is 0. (1). Returns false is val16 is NOT 0. (0).

Next we have inRange() which takes in two templated arguments, which means any number of any datatype is supported. It checks if val16
is bigger than the first argument and lower than the second argument, thus its in range. If the statement is true, it returns true (1).
If not it returns false (0)

Next we have toInt(). It returns the integer version of val16. Since val16 is an UNSIGNED int which cannot be negative, it can be returned as an INTEGER which can be
negative.

Next we have checkIfMax(). It checks if val16 is 65535(MAXIMUM_SIZE16 in this case). If its 65535 it returns true (1). If not it returns false (0).

Next we have arithmetic operations, i wont explain all of them but they clamp val16 if its higher than 65535. (sets val16 to 65535). And division does not allow
the templated argument (which applies to all arithmetic operations) to be 0.

Next we have bitCount(). It counts how much bits are needed to represent the number in binary.

Next we have isbitset(). It turns the bit at the position argument. (sets it to 1)

Next we have clearbit(). It turns off the bit at the position argument. (sets it to 0)

Next we have togglebit(). It flips  the bit at the position argument. (if its 1 turns it to 0. Vice versa)

Next we have countsetbits(). It counts how much 1's are in the number.

Next we have highestbit(). It finds the position of the most significant 1 bit. (starting from 0)

Next we have lowestbit(). It finds the position of the least significant 1 bit. (starting from 0)

Next we have toBin(). It converts the current val16 of an object to a binary version. (its returned as a string)

Next we have to toHex(). It converts the current val16 of an object to a hex version. (its returned as a string)

/---------------------------------------------------------------------------------------------------/

These are the current functions  available, expect this file to be changed as more functions are added.
*/
