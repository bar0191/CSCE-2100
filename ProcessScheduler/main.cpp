//  Program 4
//  main.cpp
//  Naive Process Scheduler
//
//  Created by Brandon Reid on 8/3/16.
//
//  Refer to README for further comments on algorithm of the program
//

#include "Heap.h"

int main()
{
    string input;                               // user input
    
    HeapPtr h = new Heap();                     // ptr to Heap Class
    
    intro();                                    // intro
    
    cmds();                                     // Menu of commands
    
    do                                          //do-while/switch menu
    {
        
        input = cmd();                          // user cmd line
        
        transform(input.begin(), input.end(), input.begin(), tolower);
        
        switch (cnvrt(input))
        {
            case loadfile:                      // load
                h->loadProcs();
                break;
                
            case addproc:                       // add
                h->userAddProc();
                break;
                
            case print:                         // print
                h->printProcs();
                break;
                
            case priority:                      // priority
                h->runTimePriority();
                break;
                
            case run:                           // run
                h->runPriorityQueue();
                break;
                
            case commands:                      // commands
                cmds();
                break;
                
            case exitprog:                      // exit
                cout << "\033[0;32mExiting Process Scheduler... Goodbye!\033[0m" << endl;
                break;
                
            default:                            // default
                cout << "\033[0;31mERROR: Invalid input entered... Please try again.\033[0m" << endl;
                cin.clear();
                break;
        }
    } while (cnvrt(input) != exitprog);
    
    return 0;
}
