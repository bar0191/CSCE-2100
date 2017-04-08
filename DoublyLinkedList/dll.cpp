//  Program Bonus
//  dls.cpp
//  Doubly Linked List
//
//  Created by Brandon Reid on 7/3/16.
//
//

#include "dll.hpp"

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
    string cmd;             // delcare string for user cmd
    
    cout << endl;			// endline before printing new cmd line
    cout << "cmd> ";		// output cmd line
    getline(cin, cmd);		// get user input
    
    return cmd;             // return string input by user
}

/*
 ============================================================================
 Function    : intro
 Parameters  : nothing
 Return      : nothing
 Description : Introduce User, refer to README
 ============================================================================
 */

void intro()
{
    cout << endl;
    cout << "Welcome to my simple doubly linked list! " << endl;
    cout << "Please take a look at the README.TXT file before going any further... " << endl;
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
    cout << "+---Commands---+\n"
         << "| Append       |\n"
         << "| InsertAt     |\n"
         << "| Remove       |\n"
         << "| RemoveAt     |\n"
         << "| Search       |\n"
         << "| Print        |\n"
         << "| Commands     |\n"
         << "| Clear        |\n"
         << "| Quit         |\n"
         << "+--------------+\n";
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
    if (incmd == "append") return appendnode;		// to enum value 0
    if (incmd == "insertat") return insertatnode; 	// to enum value 1
    if (incmd == "remove") return removenode;		// to enum value 2
    if (incmd == "removeat") return removeatnode;	// to enum value 3
    if (incmd == "search") return search;           // to enum value 4
    if (incmd == "print") return print;             // to enum value 5
    if (incmd == "commands") return commands;       // to enum value 6
    if (incmd == "quit") return exitprog;           // to enum value 7
    if (incmd == "clear") return clear;             // to enum value 8
    else return invalid;                            // default
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
 Function    : printList
 Parameters  : NodePtr head
 Return      : nothing
 Description : This function starts at the head and traverses through the list
 printing each node
 ============================================================================
 */

void printList(NodePtr head)
{
    NodePtr temp = head;            // start temp node at the head
    
    if (temp == nullptr)             // if head is null, list is empty
    {
        cout << "List is currently empty... " << endl;
    }
    
    while (temp != nullptr)         // while that value isnt null keep traversing
    {
        cout << temp->getData() << " ";
        temp = temp->getNext();     // getNext() value after printing node
    }
    
    cout << endl;
}

/*
 ============================================================================
 Function    : insertNode
 Parameters  : NodePtr head, NodePtr tail, NodePtr current, char c
 Return      : nothing
 Description : This function will append nodes at the end of the list
 BUGS        : None
 ============================================================================
 */

void insertNode(NodePtr& head, NodePtr& tail, NodePtr& current, char c)
{
    cout << "Enter a single character: ";
    cin  >> c;
    cin.ignore();
    
    current = new Node();           // creates memory for current new node
    current->setData(c);            // sets the class data
    current->setNext(nullptr);      // sets next value to nullptr since its adding at tail
    
    if (tail == nullptr)            // if tail equals null, append as first value
    {
        current->setPrev(nullptr);
        head = current;
    }
    
    else                            // if not null, then append at the end, set prev pointer
    {
        tail->setNext(current);
        current->setPrev(tail);
    }
    
    tail = current;
    cout << "Appended successfully... " << endl;
}

/*
 ============================================================================
 Function    : insertAt
 Parameters  : NodePtr head, NodePtr tail, NodePtr current, char c, pos p
 Return      : nothing
 Description : This function will add a node at nth position
 BUGS        : singly linked list implementation, still needs work
               it does not accurately move pointers to proper nodes
               when a node is added using this, it can't be removed
 Citation    : https://www.youtube.com/watch?v=IbvsNF22Ud0
http://stackoverflow.com/questions/21268034/insert-node-at-a-certain-position-in-a-linked-list-c
 ============================================================================
 */

void insertAt(NodePtr& head, NodePtr& tail, NodePtr& current, char c, position p)
{
    NodePtr nodeToInsert = new Node();              // create memory for new node
    NodePtr before;                                 // set a node for the value before
    
    cout << "Enter a single character: ";
    cin  >> c;
    cin.ignore();
    nodeToInsert->setData(c);                       // setData to new node
    
    cout << "Enter position to add character to list: ";
    cin  >> p;
    cin.ignore();
    
    int tempPos = 0;                                // use tempPos to meet pos value(traversal)
    
    current = head;                                 // start at the head to traverse
    if (head != nullptr)                            // if head doesnt equal null
    {
        // while loop used to iterate through nodes until pos is reached
        while (current->getNext() != nullptr && tempPos != p)
        {
            before = current;
            current = current->getNext();
            tempPos++;
        }
        // if position is head, output error
        if (p == 0)
        {
            cout << "ERROR: Position is the head of the list... " << endl;
            return;
        }
        // if position is tail, output error
        else if (current->getNext() == nullptr && p == tempPos + 1)
        {
            cout << "ERROR: Position is the tail of the list... " << endl;
            return;
        }
        // if position is outside link list size, output error
        else if (p > tempPos + 1)
        {
            cout << "ERROR: Position is out of list bounds... " << endl;
        }
        // insert otherwise
        else
        {
            before->setNext(nodeToInsert);
            nodeToInsert->setNext(current);
            cout << "Insert Success... " << endl;
        }
    }
    // will insert at head if nothing in list
    else
    {
        head = nodeToInsert;
        nodeToInsert->setNext(nullptr);
        cout << "Insert Success... " << endl;
    }
}

/*
 ============================================================================
 Function    : RemoveAt
 Parameters  : NodePtr head, NodePtr tail, NodePtr current, pos p
 Return      : nothing
 Description : This function will remove a node at nth position
 BUGS        : singly linked list implementation, still needs work, no major bugs atm
 Citation    : https://www.youtube.com/watch?v=Y0n86K43GO4
 ============================================================================
 */

void removeAt(NodePtr& head, NodePtr& tail, NodePtr& current, position p)
{
    NodePtr temp = head;                // start temp value at the head for iter
    
    cout << "Enter position to remove from list: ";
    cin  >> p;
    cin.ignore();
    
    if (p == 0)                         // if p is 0, head so remove head
    {
        head = temp->getNext();
        delete temp;
    }
    
    for (int i = 0; i < p-2; i++)       // for loop used to traverse nodes
    {
        temp = temp->getNext();         // traverses position - 2
    }
    
    NodePtr temp1 = temp->getNext();    // used to set up pointers to go around
    temp->setNext(temp1->getNext());    // removed node spot
    delete temp1;                       // this pointer area is flawed, prev pointers are
    cout << "Removal success " << endl; // in the ether, bugggy
        
}

/*
 ============================================================================
 Function    : searchNode
 Parameters  : NodePtr head, NodePtr tail, char target
 Return      : nothing
 Description : This function will search in one direction for a target and
 return true or false
 ============================================================================
 */

void searchNode(NodePtr head, NodePtr tail, char target)
{
    NodePtr current = head;             // start current value at the head

    cout << "Enter character you would like to search for: ";
    cin  >> target;
    cin.ignore();
    
    if (current == nullptr)             // if head is null, list is empty
    {
        cout << "List is currently empty... " << endl;
    }
    else                                // else start search
    {
        // while loop to traverse through nodes until target is reached
        // while current->data does not equal target and current->next is not null
        while (current->getData() != target && current->getNext() != nullptr)
        {
            current = current->getNext();   // continue to go to the next node
        }
        
        if (current->getData() == target)   // if target is found true
            cout << "True: " << target << endl;
        else                                // else never found false
            cout << "False: " << target << endl;
    }
}

/*
 ============================================================================
 Function    : removeNode
 Parameters  : NodePtr head, NodePtr tail, NodePtr current, char c
 Return      : nothing
 Description : this function will remove node entered by user
 Citation    : http://www.out4mind.com/en/doubly-linked-lists-in-c-part-ii/
 ============================================================================
 */

void removeNode(NodePtr& head, NodePtr& tail, NodePtr& current, char c)
{
    cout << "Enter character you would like to remove from the list: ";
    cin  >> c;
    cin.ignore();
    
    bool removable = false;                     // used to keep track
    current = tail;                             // traverse from tail
    
    if (current->getData() == c)                // if current data is equal to char
    {
        tail = current->getPrev();              // set tail to current->prev
        NodePtr before = current->getPrev();    // create a node for the value before the one
                                                // to be removed
        
        if (before == nullptr)                  // if the before value equals null
        {
            head = nullptr;                     // head is null
        }
        else                                    // else set before->next to null
        {
            before->setNext(nullptr);
        }
        
        delete current;                         // and finally delete after pointers are arranged
        removable = true;                       // set bool to true so show success of removal
    }
    else
    {
        // else traverse until nodeToRemove is equal to char
        while (current->getPrev() != nullptr)
        {
            NodePtr nodeToRemove = current->getPrev();
            
            if (nodeToRemove->getData() == c)
            {
                current->setPrev(nodeToRemove->getPrev());
                NodePtr before = nodeToRemove->getPrev();
                
                if (before == nullptr)
                {
                    head = current;
                }
                else
                {
                    before->setNext(nodeToRemove->getNext());
                }
                
                delete nodeToRemove;
                removable = true;
                break;
            }
            
            current = current->getPrev();
        }
    }
    
    // this only happens if value isn't found, error check
    if (!removable)
    {
        cout << "ERROR: character was not found in the list... " << endl;
    }
    else
    {
        cout << "Removal success... " << endl;
    }
}

/*
 ============================================================================
 Function    : quitprog
 Parameters  : NodePtr head
 Return      : nothing
 Description : this function will prompt an exit message and remove all nodes
 from memory
 ============================================================================
 */

void quitProg(NodePtr head)
{
    NodePtr temp = head;                // start temp at head for iter
    
    cout << "Removing all Nodes from memory... " << endl;
    
    while (temp != nullptr)             // while temp doesnt equal null
    {
        NodePtr nodeToDelete = temp;    // make another node for deletion
        temp = temp->getNext();         // go to next value
        
        delete nodeToDelete;            // delete
    }
    
    cout << "Exiting program... Goodbye! " << endl << endl;
}

