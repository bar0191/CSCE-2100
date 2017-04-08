//  Node Header/Class File
//  Skip List Implementation
//  Node.h
//
//
//  Created by Brandon Reid on 7/15/16.
//
//

#ifndef Node_h
#define Node_h

#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <ctime>
#include <limits>
#include <cctype>

using std::cout;
using std::endl;
using std::string;
using std::transform;
using std::cin;
using std::ostream;
using std::numeric_limits;

class Node
{
private:
    int data;       // int values to add to Node
    Node* next;     // next pointer for Node
    Node* down;     // downward pointer for Node
public:
    // NODE.CPP
    // the reason i didn't put these into a .cpp is because they are one line functions
    // this is how i was taught in 1030, and 1040 to make class functions
    // I find this way to be clean and thorough, even though it may confuse other coders
    // getters and setters
    Node() : data(0), next(nullptr), down(nullptr) {}
    ~Node() {}
    Node(int value, Node* nextValue, Node* downValue) : data(value), next(nextValue), down(downValue) {}
    int getData() { return data; }
    Node* getNext() const { return next; }
    Node* getDown() const { return down; }
    void setData(int value) { data = value; }
    void setNext(Node* nextValue) { next = nextValue; }
    void setDown(Node* downValue) { down = downValue; }
    friend ostream& operator << (ostream& output, Node& obj) { return output << obj.data; }
} NodeObj;

typedef Node* NodePtr; // used to communicate to class from main

// enum values for switch statement
enum cmdCode { add, removeNode, search, print, commands, clrScrn, exitprog, invalid };

string cmd();
void cmds();
cmdCode cnvrt(string const& incmd);
void intro();
void clrScreen();

#endif /* Node_h */