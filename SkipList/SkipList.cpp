//  Skip List class function implementations
//  SkipList.cpp
//  
//
//  Created by Brandon Reid on 7/15/16.
//
//

#include "SkipList.h"
//#include "Node.h"

/*
 ============================================================================
 Function    : coinToss
 Parameters  : nothing
 Return      : nothing
 Description : This function flips heads and tails bool - true or false
 ============================================================================
 */
bool coinToss()
{
    bool randCoinToss;
    
    // this is a crappy coin toss, and not accurate in many ways
    // but was told by prof a simple rand % 2 will be fine for this
    randCoinToss = rand() % 2;
    
    return randCoinToss;
}

/*
 ============================================================================
 Function    : randLevelGen()
 Parameters  : nothing
 Return      : nothing
 Description : generates a level depending on heads or tails coinToss()
 ============================================================================
 */
int randLevelGen()
{
    int level = 1;          // wouldn't make sense to have a 0 level size
    
    // while coinToss does not equal true, continue to increment level size up
    while (coinToss() != true)
    {
        level++;
    }
    
    return level;           // return level height
}

/*
 ============================================================================
 Function    : addElement()
 Parameters  : nothing
 Return      : nothing
 Description : adds an element into the list - makes each head = -oo
 
 ============================================================================
 */
void addElement()
{
    // initializers
    int inputValue;
    Node* iter = head;
    Node* temp = nullptr;
    int index;
    
    // prompt user for input and value to enter to list
    cout << "Enter integer value to store to list: ";
    cin  >> inputValue;
    cin.ignore(); // ignore anything else in buffer
    
    while (cin.fail())
    {
        cout << "ERROR: Invalid value was entered... " << endl;
        cin.clear();
        return;
    }
    
    // if any value is alpha output error message
    if (isalpha(inputValue))
    {
        cout << "ERROR: Invalid value was entered... " << endl;
        return;
    }
    
    // if all is well, randomize level size
    int level = randLevelGen();
    
    // if randomized level is greater then current levelsize
    if (level > levelSize)
    {
        // continue to add a head up to that level size
        // since head is an int, i made it an negitive infinity value
        // since this value will never be reached
        head = new Node(-numeric_limits<int>::infinity(), nullptr, head);
        levelSize++;
    }
    
    // Once heads are added or appropriate level size is made, increment through the levels
    for (index = levelSize; iter != nullptr; index--)
    {
        // while the next value is not null and the target value is greater then the data
        // associated with that pointer
        // continue to iterate to the next value
        while (iter->getNext() != nullptr && inputValue > iter->getNext()->getData())
        {
            iter = iter->getNext();
        }
        
        // if current level size is less then randomized level
        if (index <= level)
        {
            // if next value is equal to null or target value does not equal itself
            if (iter->getNext() == nullptr || inputValue != iter->getNext()->getData())
            {
                // allocate memory for node to insert, by setting the next value
                iter->setNext(new Node(inputValue, iter->getNext(), nullptr));
            }
            
            // if the temporary node does not equal null
            // continue to set the down pointer to the next value added
            if (temp != nullptr)
            {
                temp->setDown(iter->getNext());
            }
            
            // finally set that temp value to the next value
            temp = iter->getNext();
        }
        
        // set the iterator to next value downwards
        iter = iter->getDown();
    }
    
    // output success
    cout << "Added: " << inputValue << endl;
    
}

/*
 ============================================================================
 Function    : findElement(target)
 Parameters  : target
 Return      : target or error value
 Description : search does a sort of L shaped search goes to the bottom and
 runs over, I know this is not the fastest and most optimal implementation
 but this is very simple and easy
 
 can also use this function in a different format is print each value, and
 how many levels are in each node
 
 still trying to figure out how to print full list using different methods
 ============================================================================
 */
int findElement(int target)
{
    // initializers
    Node* iter = head;
    
    // check if list is empty
    if (iter == nullptr)
    {
        cout << "List is empty... " << endl;
        return -1;
    }
    else
    {
        // go all the way down the heads
        while(iter->getDown() != nullptr)
        {
            iter = iter->getDown();
        }
        
        // the iterate over while target value is NOT reached
        while(iter->getNext() != nullptr && iter->getData() != target)
        {
            // keep moving to next value
            iter = iter->getNext();
        }
        
        // if value is found true, else its false
        if (iter->getData() == target)
        {
            cout << "True: " << target << endl;
            return iter->getData();
        }
        else
        {
            cout << "False: " << target << endl;
            return -1;
        }
    }
    
}

/*
 ============================================================================
 Function    : removeElement()
 Parameters  : nothing
 Return      : nothing
 Description : remove element in list, memory allocations for pointers are
 flawed in this function, you WILL exprience segmentation faults after removing
 something from the list
 ============================================================================
 */
void removeElement()
{
    // initializers
    Node* iter = head;
    Node* temp = nullptr;
    int inputValue;
    
    // check if list is empty
    if (iter == nullptr)
    {
        cout << "List is empty... " << endl;
        return;
    }
    
    // prompt user for input value
    cout << "Enter integer value you with to remove: ";
    cin  >> inputValue;
    cin.ignore();
    
    // if value other then an int is entered
    while (cin.fail())
    {
        cout << "ERROR: Invalid value was entered... " << endl;
        cin.clear();
        return;
    }
    
    // check if value exists or not
    if(checkElements(inputValue) != inputValue)
    {
        cout << "ERROR: Value does not exist in current list... " << endl;
        return;
    }
    
    // while head does not equal null
    while (iter != nullptr)
    {
        // continue over to next highest level to find value before target
        while (iter->getNext() != nullptr && inputValue > iter->getNext()->getData())
        {
            iter = iter->getNext();
        }
        
        // continue over until target is reached
        if (iter->getNext() != nullptr && inputValue == iter->getNext()->getData())
        {
            // right here is were memory allocations arent working properly, but im not sure
            // reroute pointers to next values over the one to be deleted
            // and delete
            temp = iter->getNext();
            iter->setNext(temp->getNext());
            delete temp;
            
        }
        
        //iter is iterating down each time while loop iterates
        iter = iter->getDown();
    }
    
    cout << "Removed: " << inputValue << endl;
    
    
}

/*
 ============================================================================
 Function    : checkElements(target)
 Parameters  : target
 Return      : target or error value
 Description : used for error checks, traversal of list in L shape
 ============================================================================
 */
int checkElements(int target)
{
    // initializers
    Node* iter = head;
    
    // go all the way down the heads
    while(iter->getDown() != nullptr)
    {
        iter = iter->getDown();
    }
    
    // the iterate over while target value is NOT reached
    while(iter->getNext() != nullptr && iter->getData() != target)
    {
        // keep moving to next value
        iter = iter->getNext();
    }
    
    // if value is found true, else its false
    if (iter->getData() == target)
    {
        return iter->getData();
    }
    else
    {
        return -1;
    }
}
/*
 ============================================================================
 Function    : printLevels()
 Parameters  : nothing
 Return      : nothing
 Description : prints each level of the list
 ============================================================================
 */
void printLevels()
{
    //initializers
    Node* iter = head;
    Node* iterArr[16];
    
    // initializes array of head pointers in list for each level
    for (int j = levelSize; iter != nullptr; j--)
    {
        // initializes then increments down
        arr[j] = iter;
        iter = iter->getDown();
    }
    
    // initializes another set of pointer arrays to iterate through each level
    for (int i = 1; i <= levelSize; i++)
    {
        iterArr[i] = arr[i];
    }
    
    // iterate each level in sort of a half-ass matrix form while loop inside for loop
    for (int i = levelSize; i > 0; i--)
    {
        cout << "Level[" << i << "] : ";
        while (iterArr[i] != nullptr)
        {
            // print each element and iterate to the next
            cout  << iterArr[i]->getData() << " ";
            iterArr[i] = iterArr[i]->getNext();
            
        }
        cout << endl;
    }
    cout << endl;
    
}