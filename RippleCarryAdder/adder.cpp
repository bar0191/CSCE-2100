//============================================================================
// Name        : adder.cpp
// Author      : Brandon A. Reid
// Version     : V.1
// Copyright   : 2016
// Description : .cpp file containing ripple carry adder function definitions
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

/*
 ============================================================================
 Function    : cmd
 Parameters  : nothing
 Return      : cmd (user command)
 Description : This function takes in user input as a command line and will
 return the string user has entered (command)
 ============================================================================
 */

string cmd()
{
    string cmd;
    
    cout << endl;
    cout << "ripple_carry> ";   // prompt for user
    getline(cin, cmd);
    
    return cmd;                 // return whatever string entered by the user
}

/*
 ============================================================================
 Function    : intro
 Parameters  : nothing
 Return      : nothing
 Description : This function prints out a friendly introduction to the adder
 ============================================================================
 */

void intro()
{
    // ascii codes used to color text
    cout << "\n\033[1;31mWelcome to my Ripple-Carry Binary Adder!\033[0m\n\n";
    
    cout << "To start using the Ripple-Carry Binary Adder, please type one of the following\ncommands below, followed by the two binary sets you would like to add." << endl;
    
    cout << "(eg. add 101 11)" << endl << endl;
    
    cout << "\033[1;31mNOTE:\033[0m This adder has a maximum of 6 bits per set." << endl;
}

/*
 ============================================================================
 Function    : cmds
 Parameters  : nothing
 Return      : nothing
 Description : This function prints out list of commands for user to use in
 cmd function
 ============================================================================
 */

void cmds()
{
    cout << endl;
    cout << "+--\033[1;31mCommands\033[0m--+\n"
    << "| Add        |\n"
    << "| Quit       |\n"
    << "+------------+\n";
}

/*
 ============================================================================
 Function    : cnvrt (convert)
 Parameters  : incmd (takes in string command for cmd func)
 Return      : enum value of specific string
 Description : This function will convert a incoming string command to an
 enumerated value for switch-case statement
 ============================================================================
 */

cmdCode cnvrt(string const& incmd)
{
    if (incmd == "add") return add;
    if (incmd == "quit") return exitprog;
    else return invalid;
}

/*
 ============================================================================
 Function    : inputData
 Parameters  : binInput, obj(class obj)
 Return      : void
 Description : This function is the meat of the program, it takes user inputs, 
 converts inputs, does error checks, and adds the binary values
 
 Do-While loop used to run menu function atleast once, until quit is initiated
 ============================================================================
 */

void inputData(string binInput, bit obj)
{
    do
    {
        
        binInput = cmd();                   // takes in entire string entered by user
        string binInput2;                   // second binary value (string)
        string binSumValue;                 // longs to hold converted bitset values
        unsigned long binDecimalValue1;
        unsigned long binDecimalValue2;
        unsigned long binDecimalSum;
        string delimiter = " ";             // delimiter is used to split input string from user
        size_t pos = 0;                     // initializing the pos in string to 0; (first char)
        string parityBit;                   // not actually a paritybit, initialization for left most bit
        
        // this holds the original string entered by user, because binInput will be split into multiple strings
        string originalInput = binInput.substr(0, binInput.size());
        
        // while loop will split the string up by the delimiter, which is spaces
        while ((pos = binInput.find(delimiter)) != string::npos)
        {
            // this will essentially leave two remaining strings, both entered binary values
            binInput2 = binInput.substr(0, pos);
            binInput.erase(0, pos + delimiter.length());
        }
        
        // initializing the left most bit in the set, used to check for '-'
        parityBit = binInput2[0];
        
        // if this bit does not equal zero and one, run a check
        if (parityBit != "0" && parityBit != "1")
        {
            // if the user entered quit, exit_successfully (exit(0))
            if (binInput == "quit")
            {
                cout << "\033[1;31mExiting Ripple-Carry Binary Adder...Have a nice day!\033[0m" << endl;
                exit(0);
            }
            
            // else if the left most bit is a '-', output ERROR
            else if (parityBit == "-")
            {
                cout << "\033[1;31mERROR:\033[0m This adder does not support negative values... " << endl;
                inputData(binInput, obj);   // go back to the beginning of the input function to start over
            }
            
            //else if the left most bit is greater then 1 or less then zero, output ERROR
            else if (parityBit > "1")
            {
                cout << "\033[1;31mERROR:\033[0m This adder only supports Binary values..." << endl;
                inputData(binInput, obj);
            }
            
            // same check as above, if greater then 1 or less then 0, not a binary value
            else if (parityBit < "0")
            {
                cout << "\033[1;31mERROR:\033[0m Invalid command..." << endl;
                inputData(binInput, obj);
            }
            
            return;
        }
        
        // if the binary values are greater then maxsize of 6, output error
        if (binInput2.length() > MAXSIZE)
        {
            cout << "\033[1;31mERROR:\033[0m One of the Binary values exceeds the maximum bitset length..." << endl;
            inputData(binInput, obj);
            return;
        }
        
        // same as above if statement
        if (binInput.length() > MAXSIZE)
        {
            cout << "\033[1;31mERROR:\033[0m One of the Binary values exceeds the maximum bitset length..." << endl;
            inputData(binInput, obj);
            return;
        }
        
        //for loop used to iterate through each bit to make sure its a 1 or 0
        for (int i = 0; i < binInput2.length(); i++)
        {
            // if the bit is greater then 1, output ERROR
            if (binInput2[i] > '1')
            {
                cout << "\033[1;31mERROR:\033[0m This adder only supports Binary values..." << endl;
                inputData(binInput, obj);
                break;
            }
            
            // if the bit is less then 0, output ERROR
            if (binInput2[i] < '0')
            {
                cout << "\033[1;31mERROR:\033[0m This adder only supports Binary values..." << endl;
                inputData(binInput, obj);
                break;
            }
        }
        
        // same as above, iterate though each bit in binary value to make sure its a 1 or 0
        for (int i = 0; i < binInput.length(); i++)
        {
            // if the bit is greater then 1, output ERROR
            if (binInput[i] > '1')
            {
                cout << "\033[1;31mERROR:\033[0m This adder only supports Binary values..." << endl;
                inputData(binInput, obj);
                break;
            }
            
            // if the bit is less then 0, output ERROR
            if (binInput[i] < '0')
            {
                cout << "\033[1;31mERROR:\033[0m This adder only supports Binary values..." << endl;
                inputData(binInput, obj);
                break;
            }
        }
        
        // after above error checks are made, at this point we should have legitimate binary values
        // now the values will be converted and stored in private area of class
        
        binDecimalValue1 = bitset<MAXSIZE>(binInput2).to_ulong();   // first Binary value is converted to unsigned long
        binDecimalValue2 = bitset<MAXSIZE>(binInput).to_ulong();    // second Binary value is converted to unsigned long
        
        obj.setBinValue1(binDecimalValue1);             // set private values in class
        obj.setBinValue2(binDecimalValue2);
        
        // after data has been stored, extract the add or quit command from the orignal user input string
        string command = originalInput.substr(0, originalInput.size() - binInput.size() - binInput2.size() - 2);
        
        // converts command string to lowercase to avoid syntax errors (using algorithm, and transform library)
        transform(command.begin(), command.end(), command.begin(), ::tolower);
        
        // switch statement for each command case
        switch (cnvrt(command))
        {
            // add binary values
            case add:
                
                //Sum value accesses private data to add binary values (still as unsigned long value)
                binDecimalSum = (obj.getBinValue1() + obj.getBinValue2());
                
                // once values are added, store private data in class of sum
                obj.setSumValue(binDecimalSum);
                
                // access private data of the sum, and convert it back to a string of binary bits using bitset
                binSumValue = bitset<MAXSIZE>(obj.getSumValue()).to_string();
                
                // using std::min to erase leading zeros
                // str.find_first_not_of('0') will find the first value going to the right that does not equal 0
                // once it finds that value, str.size() - 1 will make sure the zeros, but NOT the value that is not
                // equal to the zero is erased.
                binSumValue.erase(0, min(binSumValue.find_first_not_of('0'), binSumValue.size() - 1));
                
                // finally output the added binary value
                cout << binSumValue << endl;
                break;
                
            // quit program, exit_successful
            case exitprog:
                cout << "Exiting Ripple-Carry Binary Adder...Have a nice day! " << endl;
                exit(0);
                
            // if any command other then add or quit is used, output default error
            default:
                cout << "ERROR: invalid command... " << endl;
                inputData(binInput, obj);
        }
        
    } while (cnvrt(binInput) != exitprog); // while input does not equal quit, keep running loop
}