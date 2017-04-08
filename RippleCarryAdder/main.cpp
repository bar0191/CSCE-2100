//============================================================================
// Name        : main.cpp
// Author      : Brandon A. Reid
// Version     : V.1
// Copyright   : 2016
// Description : main.cpp of ripple carry adder, consisting of class obj, and
// function calls
//
// BITSET LIBRARY EXPLAINED:
//
// the bitset library allows you to convert sets of binary bits to longs and strings
// a clever way of adding two bitsets is converting them from a string of bits to its decimal value
// for example: if the two values were "101" and "11" this being 5 and 3 this equals 8
// after finding the decimal sum, the bitset library can convert the long value back to a string of binary bits
// resulting in "1000"
// ============================================================================


#include "adder_h.h"

int main(int argc, char** argv)
{
    
    bit obj;                    // class object
    string binInput;            // user input from terminal
    
    intro();                    // introduction to the program
    
    cmds();                     // menu of commands
    
    inputData(binInput, obj);   // runs through user inputs, error checks, and adds binary values
    
    return 0;
}
