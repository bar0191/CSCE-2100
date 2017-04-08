//  Program 4
//  Process.h
//  Naive Process Scheduler
//
//  Created by Brandon Reid on 8/3/16.
//
//  Refer to README for further comments on algorithm of the program
//

#ifndef Process_h
#define Process_h

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <utility>
#include <queue>
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::istream;
using std::pair;
using std::make_pair;
using std::priority_queue;
using std::swap;
using std::numeric_limits;
using std::streamsize;
using std::get;

const int maxSize = 25; // max size of max-heap

/*
 ============================================================================
 Class             : Process
 Private Variables : process Prioritym process runtime
 Description       : This Class manages the priority values and run times
 ============================================================================
 */

class Process
{
private:
    int* procPriority;                                  // priority value
    int* procRunTime;                                   // run time value
public:
    Process(int size);                                  // constructor
    ~Process();                                         // deconstructor
    int getProcPriority(int size) const;                // getter
    int* getProcPriorityPtr() const;                    // setter
    void setProcPriority(int size, int priority);       // setter
    int getProcRunTime(int size) const;                 // getter
    void setProcRunTime(int size, int runTime);         // setter
};

typedef Process* ProcessPtr;    // typedef value to communicate to Process Class

enum cmdCode { loadfile, addproc, print, priority, run, commands, exitprog, invalid };

string cmd();
void cmds();
cmdCode cnvrt(string const& incmd);
void intro();

#endif