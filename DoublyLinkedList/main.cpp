//  Bonus Program
//  main.cpp
//  Doubly Linked List
//
//  Created by Brandon Reid on 7/5/16.
//
//  If for some reason not using makefile, compile with c++11

#include "dll.hpp"

int main()
{
    NodePtr head = nullptr;     //declare head and tail as null
    NodePtr tail = nullptr;
    NodePtr current;            // Node Ptr to keep track of current value
    string input;               // string for user input
    char c;
    position p;
    
    intro();                    // print intro
    
    cmds();                     // print cmds
    
    do
    {
        input = cmd();
        
        // transforms user input to lowercase
        transform(input.begin(), input.end(), input.begin(), tolower);
        
        // switch for menu
        switch (cnvrt(input))
        {
            case appendnode:
                insertNode(head, tail, current, c);
                break;
                
            case insertatnode:
                insertAt(head, tail, current, c, p);
                break;
                
            case removenode:
                removeNode(head, tail, current, c);
                break;
                
            case removeatnode:
                removeAt(head, tail, current, p);
                break;
                
            case search:
                searchNode(head, tail, c);
                break;
                
            case print:
                printList(head);
                break;
                
            case commands:
                cmds();
                break;
                
            case exitprog:
                quitProg(head);
                break;
                
            case clear:
                clrScreen();
                break;
                
            default:
                cout << "ERROR: Invalid command... " << endl;
                break;
        }
    }while (cnvrt(input) != exitprog);
    
    return 0;
}
