//  Program #2
//  main.cpp
//  Skip List
//
//  Created by Brandon Reid on 7/15/16.
//
//

#include "SkipList.h"

// used with nanosleep to make pauses on exit
// refer to exit prog in switch case #5
// I DO NOT TAKE CREDIT FOR CODING THE NANOSLEEP FUNCTION, THE STRUCT AND VARIABLES HAVE TO
// BE SET UP THIS WAY - refrences on cplusplus.com
struct timespec timeOut, remains;

int main()
{
    timeOut.tv_sec = 0;     // these values are used to put "pauses" when exiting prog
    timeOut.tv_nsec = 500000000;
    int target;
    
    string input;           // input from user
    
    srand((time(0)));       // randomize RAND
    
    intro();                // introduction
    
    cmds();                 // output commands to user
    
    do                      // run program based on user input
    {
        input = cmd();      // initialize user input from cmd();
        
        // transform any user input to lowercase, to avoid errors
        transform(input.begin(), input.end(), input.begin(), tolower);
        
        // switch statement for menu
        switch (cnvrt(input))
        {
            case add:           // add value
                sList.addElement();
                break;
                
            case removeNode:    // remove value
                sList.removeElement();
                break;
                
            case search:        // search for value
                // prompt user for target value
                cout << "Enter integer value you wish to search: ";
                cin  >> target;
                cin.ignore();
                
                sList.findElement(target);
                break;
                
            case print:         // print list
                sList.printLevels();
                break;
                
            case commands:      // print commands
                cmds();
                break;
                
            case clrScrn:         // clear terminal
                clrScreen();
                break;
                
            case exitprog:      // exit program
                cout << "Thank you for using my SkipList! " << endl;
                nanosleep(&timeOut, &remains);
                
                cout << "Exiting program... " << endl;
                nanosleep(&timeOut, &remains);
                
                cout << "Freeing memory... " << endl;
                NodeObj.~Node(); // deconstructor
                nanosleep(&timeOut, &remains);
                break;
                
            default: // error default
                cout << "ERROR: Invalid input... " << endl;
                cin.clear();    // clear cin buffer incase of wrong input
                break;
        }
    } while (cnvrt(input) != exitprog);
    // exit after user enters "exit"
    
    return 0;
}
