//  Program 4
//  process.cpp
//  Naive Process Scheduler
//
//  Created by Brandon Reid on 8/3/16.
//
//  Refer to README for further comments on algorithm of the program
//

#include "Process.h"

/*
 ============================================================================
 Function    : Process()
 Parameters  : size
 Return      : nothing
 Description : Constructor for Process Class
 ============================================================================
 */

Process::Process(int size)
{
    procPriority = new int[size];
    procRunTime = new int[size];
}

/*
 ============================================================================
 Function    : ~Process()
 Parameters  : nothing
 Return      : nothing
 Description : De-Constructor for Process Class
 ============================================================================
 */

Process::~Process()
{
    delete [] procPriority;
    delete [] procRunTime;
}

/*
 ============================================================================
 Function    : getProcPriority()
 Parameters  : size
 Return      : process priority value in a position in "size"
 Description : getter for specific value in array of priority values
 ============================================================================
 */

int Process::getProcPriority(int size) const
{
    return procPriority[size];
}

/*
 ============================================================================
 Function    : getProcPriorityPtr()
 Parameters  : nothing
 Return      : pointer to start of priority value array
 Description : getter for ptr for front of array of priority values
 ============================================================================
 */

int* Process::getProcPriorityPtr() const
{
    return procPriority;
}

/*
 ============================================================================
 Function    : setProcPriority()
 Parameters  : size, priority
 Return      : nothing
 Description : setter for priority value
 ============================================================================
 */

void Process::setProcPriority(int size, int priority)
{
    procPriority[size] = priority;
}

/*
 ============================================================================
 Function    : getProcRunTime()
 Parameters  : size
 Return      : run time value in array of runtimes
 Description : getter for runtime values in an array
 ============================================================================
 */

int Process::getProcRunTime(int size) const
{
    return procRunTime[size];
}

/*
 ============================================================================
 Function    : setprocRunTime()
 Parameters  : size, runTime
 Return      : nothing
 Description : setter for specific position in array of run time values
 ============================================================================
 */

void Process::setProcRunTime(int size, int runTime)
{
    procRunTime[size] = runTime;
}

/*
 ============================================================================
 Function    : cmd()
 Parameters  : nothing
 Return      : cmd
 Description : command line function for user input
 ============================================================================
 */

string cmd()
{
    string cmd;             // delcare string for user cmd
    
    cout << endl;			// endline before printing new cmd line
    cout << "cmd> ";		// output cmd line
    getline(cin, cmd);		// get user input
    
    return cmd;             // return string input by user
}

/*
 ============================================================================
 Function    : cnvrt()
 Parameters  : incmd
 Return      : enum value
 Description : converts commands entered by user to enum value for switch
 ============================================================================
 */

cmdCode cnvrt(string const& incmd)
{
    if (incmd == "load") return loadfile;             // to enum value 0
    if (incmd == "add") return addproc;               // to enum value 1
    if (incmd == "print") return print;               // to enum value 2
    if (incmd == "priority") return priority;         // to enum value 3
    if (incmd == "run") return run;                   // to enum value 4
    if (incmd == "commands") return commands;         // to enum value 5
    if (incmd == "quit") return exitprog;             // to enum value 6
    else return invalid;                              // default
}

/*
 ============================================================================
 Function    : cmds()
 Parameters  : nothing
 Return      : nothing
 Description : Commands menu
 ============================================================================
 */

void cmds()
{
    cout << endl;
    cout << "+---\033[1;31mCommands\033[0m---+\n"
         << "| \033[1;31mLoad\033[0m         |\n"
         << "| \033[1;31mAdd\033[0m          |\n"
         << "| \033[1;31mPrint\033[0m        |\n"
         << "| \033[1;31mPriority\033[0m     |\n"
         << "| \033[1;31mRun\033[0m          |\n"
         << "| \033[1;31mCommands\033[0m     |\n"
         << "| \033[1;31mQuit\033[0m         |\n"
         << "+--------------+\n";
}

void intro()
{
    cout << "\nWelcome! Please refer to the README for details on each menu command." << endl;
}