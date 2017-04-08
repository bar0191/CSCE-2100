//============================================================================
// Name        : adder_h.h
// Author      : Brandon A. Reid
// Version     : V.1
// Copyright   : 2016
// Description : header file consisting of libraries, std, and class def
// ============================================================================

#ifndef adder_h_
#define adder_h_

#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>
#include <limits>
#include <cstdlib>

using std::string;
using std::cout;
using std::cin;
using std::bitset;
using std::endl;
using std::min;
using std::transform;

const size_t MAXSIZE = 6; // bitset library requires a const maximum size upon compile time

// BITSET LIBRARY EXPLAINED:
//
// the bitset library allows you to convert sets of binary bits to longs and strings
// a clever way of adding two bitsets is converting them from a string of bits to its decimal value
// for example: if the two values were "101" and "11" this being 5 and 3 this equals 8
// after finding the decimal sum, the bitset library can convert the long value back to a string of binary bits
// resulting in "1000"

// class definition
class bit
{
private:        // private values for binary sets, and sum of the sets
    unsigned long binValue1;
    unsigned long binValue2;
    unsigned long sumValue;
public:         // functions to manage private data publicly
    bit() : binValue1(0), binValue2(0) {}
    bit(unsigned long binNum1, unsigned long binNum2, unsigned long binSum) : binValue1(binNum1), binValue2(binNum2), sumValue(binSum) {}
    unsigned long getBinValue1() const { return binValue1; }
    unsigned long getBinValue2() const { return binValue2; }
    unsigned long getSumValue() const { return sumValue; }
    void setBinValue1(unsigned long binNum1) { binValue1 = binNum1; }
    void setBinValue2(unsigned long binNum2) {binValue2 = binNum2; }
    void setSumValue(unsigned long binSum) {sumValue = binSum; }
};

enum cmdCode { add, exitprog, invalid }; // enumerated values for string commands entered by the user

// function prototypes
string cmd();
void cmds();
cmdCode cnvrt(string const& incmd);
void inputData(string binInput, bit obj);
void intro();

//adder_h.h

#endif // adder_h_