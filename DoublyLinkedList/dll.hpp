//  Bonus Program
//  dls.hpp
//  Doubly Linked List
//
//  Created by Brandon Reid on 7/3/16.
//
//  

#ifndef dls_hpp
#define dls_hpp

#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cctype>
#include <limits>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::numeric_limits;
using std::streamsize;

// Node class to manage nodes in linked list
class Node
{
private:
    char data;
    Node* next;
    Node* prev;
public:
    Node() : data(0), next(nullptr), prev(nullptr) {}
    ~Node() {}
    Node(char value, Node* nextValue, Node* prevValue) : data(value), next(nextValue), prev(prevValue) {}
    char getData() { return data; }
    Node* getNext() const { return next; }
    Node* getPrev() const { return prev; }
    void setData(char value) { data = value; }
    void setNext(Node* nextValue) { next = nextValue; }
    void setPrev(Node* prevValue) { prev = prevValue; }
};

typedef Node* NodePtr;      // typedef Ptr to communicate to class
typedef int position;       // typedef value for position

// enum values used for user input
enum cmdCode { appendnode, insertatnode, removenode, removeatnode, search, print, commands, exitprog, clear, invalid };

// prototypes
void printList(NodePtr head);
void insertNode(NodePtr& head, NodePtr& tail, NodePtr& current, char c);
string cmd();
void cmds();
void newLine();
cmdCode cnvrt(string const& incmd);
void searchNode(NodePtr head, NodePtr tail, char target);
void clrScreen();
void removeNode(NodePtr& head, NodePtr& tail, NodePtr& current, char c);
void intro();
void quitProg(NodePtr head);
void insertAt(NodePtr& head, NodePtr& tail, NodePtr& current, char c, position p);
void removeAt(NodePtr& head, NodePtr& tail, NodePtr& current, position p);

#endif /* dls_hpp */
