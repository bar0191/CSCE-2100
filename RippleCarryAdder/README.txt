Welcome to my Ripple-Carry Binary Adder

*USE MAKEFILE*

The traditional method of adding two binary values together would be the carry method of addition

While this method shows the mathematics behind how to add two binary values, I wanted to take the challenge
of trying to use the bitset library which comes standard in c++ standard library

The bitset library will read a string of 1s and 0s and convert them to a set of bits just as a proccessor does.

This essentially turns each bit into a boolean value of true or false. In memory manipulation methods and other memory
implimentations the bitset library is used to hand large sets of bits and bites

The bitset library allows for easy conversion between strings and unsigned longs, making it simple for user input of different bitset strings.

the DOWNSIDE of using the bitset library came to my realization once I attempted to take in command line arguements
The bitset function requires that a constant size_t value be determined at compile time in order to successful lay out the set of bits
this means that the const size_t value may not be determined at run time (eg. ./a.out 2) 

This program has every requirement made, except for taking in a parameter from the command line for a user specified bit set length.

Alternatives to this problem would include the original and tradition method of ripple carry math, or the use of a vector<bool>

but I found the bitset library to have its own challenges and found it quite useful to learn, and will take the point deduction for no 
command line arguement functionality. 

HOW TO RUN PROGRAM:

this program uses a simple make file, if you are fimiliar with this, simply cd to folder, and type "make" and after compilation, type "make run"

1. After unzipping the file
2. direct yourself to the folder in terminal
3. simply type "make"
4. if compilation is successful type "make run"
5. Program is running

NOTE: if you see garbage text in your terminal upon introduction in the program, your terminal is not supporting the colored text implemented in the program
I apologize for this, if this issue occurs.
