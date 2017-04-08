//  Program #2
//  Node.cpp
//  Skip List
//
//  Created by Brandon Reid on 7/15/16.
//
//

//#include "Node.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
using std::cin;

enum cmdCode { add, removeNode, search, print, commands, clrScrn, exitprog, invalid };

/*
 ============================================================================
 Function    : intro
 Parameters  : nothing
 Return      : nothing
 Description : Introduction
 ============================================================================
 */

void intro()
{
    cout << "\n\033[1;31mWelcome to my Linked Skip List Implementation!\033[1;31m\n" << endl;
    cout << "Please refer to the attached README.txt " << endl;
    cout << "Simply type one of the following commands below to get started! " << endl << endl;
    
    cout << "\033[1;31mNOTE:\033[0m When starting a new list, please insert the value 0 first, followed by the rest of your list.. " << endl;
    cout << "For now this is the only non user friendly bug... I apologize for the inconvenience. " << endl;
    
}

/*
 ============================================================================
 Function    : clrScreen
 Parameters  : nothing
 Return      : nothing
 Description : This function clears screen with ASCII escape codes
 ============================================================================
 */

void clrScreen()
{
    cout << "\033[2J\033[1;1H";		// ASCII escape codes to clear screen
}

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
    cout << "> ";
    getline(cin, cmd);
    
    return cmd;
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
    cout << "+--Commands--+\n"
         << "| Add        |\n"
         << "| Remove     |\n"
         << "| Search     |\n"
         << "| Print      |\n"
         << "| Commands   |\n"
         << "| Clear      |\n"
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
    if (incmd == "add") return add;             // 0
    if (incmd == "remove") return removeNode;   // 1
    if (incmd == "search") return search;       // 2
    if (incmd == "print") return print;         // 3
    if (incmd == "commands") return commands;   // 4
    if (incmd == "clear") return clrScrn;         // 5
    if (incmd == "quit") return exitprog;       // 6
    else return invalid;                        // 7
}