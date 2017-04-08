//  Program 4
//  Heap.cpp
//  Naive Process Scheduler
//
//  Created by Brandon Reid on 8/3/16.
//
//
//  Refer to README for further comments on algorithm of the program
//

#include "Heap.h"

/*
 ============================================================================
 Function    : Heap()
 Parameters  : nothing
 Return      : nothing
 Description : Constructor for Heap Class
 ============================================================================
 */

Heap::Heap()
{
    count = 1;
    position = 1;
    p = new Process(maxSize);
}

/*
 ============================================================================
 Function    : ~Heap()
 Parameters  : nothing
 Return      : nothing
 Description : De-Constructor for Heap Class
 ============================================================================
 */

Heap::~Heap()
{
    
}

/*
 ============================================================================
 Function    : getProcPair()
 Parameters  : size
 Return      : procPair[size]
 Description : getter for specific pair in array of processes/runtimes
 ============================================================================
 */

pair<int,int> Heap::getProcPair(int size) const
{
    return procPair[size];
}

/*
 ============================================================================
 Function    : setProcPair()
 Parameters  : size, pairValue
 Return      : nothing
 Description : Setter for pair of process/runtime in specific spot in array
 ============================================================================
 */

void Heap::setProcPair(int size, pair<int,int> pairValue)
{
    procPair[size] = pairValue;
}

/*
 ============================================================================
 Function    : bubbleUpPair()
 Parameters  : pos[], i
 Return      : nothing
 Description : this function bubbles up the logic tree array, this function
 is used everytime a new pair is added to the max-heap, needed to keep 
 max heap status after insertions.
 ============================================================================
 */

void Heap::bubbleUpPair(pair<int,int> pos[], int i)
{
    // value i will take in index value (size of array)
    // meaning i starts at the end of the array
    
    // pos[i] is the position depending on value of i;
    // pos[i/2] is the parent of pos[i]
    
    // while the parent of that position is less and index is greater then 1
    // greater then 1 meaning, it hasn't hit the front of the array
    
    // swap the values, and set i to next parent location, unless while is
    // satisfied
    
    while (pos[i/2] < pos[i] && i > 1)
    {
        swap(pos[i], pos[i/2]);
        i = i/2;
    }
}

/*
 ============================================================================
 Function    : heapifyPair()
 Parameters  : pairValue
 Return      : nothing
 Description : adds a new value to the heap, and bubbles it up to keep max
 heap status, hence the function name heapifyPair
 ============================================================================
 */

void Heap::heapifyPair(pair<int,int> pairValue)
{
    // a pairValue will be pulled each time a new process/runtime is added
    // after insertion of pair, bubbles up until max heap is satisfied
    
    procPair[++index] = pairValue;
    bubbleUpPair(procPair, index);
}

/*
 ============================================================================
 Function    : printMaxHeapPair()
 Parameters  : nothing
 Return      : nothing
 Description : print heapified array values
 ============================================================================
 */

void Heap::printMaxHeapPair()
{
    cout << "| ";
    for (int i = 1; i <= index; i++)
    {
        cout << procPair[i].first << ',' << procPair[i].second << " | ";
    }
    cout << endl << endl;
}

/*
 ============================================================================
 Function    : bubbleDownPair()
 Parameters  : pos[], size
 Return      : nothing
 Description : similar to BubbleUp, but compares with parent and if one or 
 both of the children are larger, then exchange it with the largerone of the 
 children.
 
 The root node must be replaced. We choose the rightmost node of the last
 level. (this is done in deleteMax())
 ============================================================================
 */

void Heap::bubbleDownPair(pair<int,int> pos[], int size)
{
    int i = 1;  // i is the start of the array
    
    // children elements of parents in an array based heap are as followed:
    // if index starts at 1 and not 0
    // left child = 2*i
    // right child = (2*i) + 1
    
    // while loop will continue until child position (i) surpases size
    // of heap (gets to the end of heap)
    
    while(2*i <= size)
    {
        int leftChild = 2*i;
        int rightChild = leftChild + 1;
        
        // if left child is less then index, and left child is less then right child
        // increment to next left child
        if (leftChild < size && pos[leftChild] < pos[rightChild])
        {
            leftChild++;
        }
        
        // if parent is less then its left child
        // swap to obtain max heap
        if (pos[i] < pos[leftChild])
        {
            swap(pos[i], pos[leftChild]);
            
            //after swap, set i to the parent value that went below its swapped value
            i = leftChild;
        }
        // if max heap is satisfied
        else
        {
            return;
        }
    }
}

/*
 ============================================================================
 Function    : deleteMaxPair()
 Parameters  : nothing
 Return      : nothing
 Description : delete max element, swaps root with right most value in heap
 then bubble down until max heap is satisfied
 ============================================================================
 */

pair<int,int> Heap::deleteMaxPair()
{
    // swap last value in the heap, with the root
    swap(procPair[index], procPair[1]);
    bubbleDownPair(procPair, index - 1);
    
    return procPair[index--];
}

/*
 ============================================================================
 Function    : isEmpty()
 Parameters  : nothing
 Return      : true or false
 Description : check if index is empty (index is size of heap)
 ============================================================================
 */

bool Heap::isEmpty()
{
    return index == 0;
}

/*
 ============================================================================
 Function    : loadProcs()
 Parameters  : nothing
 Return      : nothing
 Description : this function will prompt user for a file name, read in file
 data, add data to an array, heapify a seperate array of pairs of data
 ============================================================================
 */

void Heap::loadProcs()
{
    // used for system pause, nanosleep
    struct timespec timeOut, remains;
    timeOut.tv_sec = 0;
    timeOut.tv_nsec = 999999999;
    
    
    string fileName;
    
    // prompt user for file name
    cout << "Enter file to load into scheduler: ";
    cin  >> fileName;
    cin.ignore();
    
    fin.open(fileName);
    
    if (fin.fail())
    {
        cout << "\033[0;31mERROR: File does not exist... make sure file is in the same folder as this program.\033[0m " << endl;
        return;
    }
    else
    {
        cout << "\033[0;32mFile: " << fileName << " opened successfully.\033[0m " << endl;
        cout << "Obtaining data from file... " << endl;
        nanosleep(&timeOut, &remains);
    }
    
    // getline to obtain strings of each process and run time
    while (getline(fin, proc, ',') && getline(fin, runTime))
    {
        // convert string to int using stoi(), set values
        p->setProcPriority(position, stoi(proc));
        p->setProcRunTime(position, stoi(runTime));
        
        // set pair value for heap
        setProcPair(position, make_pair (p->getProcPriority(position),p->getProcRunTime(position)));
        
        pq.emplace(p->getProcPriority(position),p->getProcRunTime(position));
        
        // used to clean up outputs
        if (position < 10)
        {
            if (p->getProcPriority(position) < 10)
            {
                cout << "[ " << position << "]: " << "Process #" << p->getProcPriority(position) << "  added to Scheduler..." << endl;
            }
            else
            {
                cout << "[ " << position << "]: " << "Process #" << p->getProcPriority(position) << " added to Scheduler..." << endl;
            }
        }
        else
        {
            if (p->getProcPriority(position) < 10)
            {
                cout << "[" << position << "]: " << "Process #" << p->getProcPriority(position) << "  added to Scheduler..." << endl;
            }
            else
            {
                cout << "[" << position << "]: " << "Process #" << p->getProcPriority(position) << " added to Scheduler..." << endl;
            }

        }
        // increment position everytime something is added, runs along side index
        position++;
    }
    
    // loop through array pairs and heapify them
    for (int i = count; i < position; i++)
    {
        heapifyPair(getProcPair(i));
    }
    
    // close file
    cout << "Closing file... " << endl;
    nanosleep(&timeOut, &remains);
    fin.close();
    cout << "\033[0;32mFile: " << fileName << " closed successfully.\033[0m " << endl;
}

/*
 ============================================================================
 Function    : runPriorityQueue()
 Parameters  : nothing
 Return      : nothing
 Description : this function will run the delete max process, store each 
 max outputted value into a list to putput queue times
 ============================================================================
 */

void Heap::runPriorityQueue()
{
    // used for system pauses, nanosleep
    struct timespec timeOut, remains;
    timeOut.tv_sec = 0;
    timeOut.tv_nsec = 900000000;
    
    
    int totalQueueTime = 0;
    
    if (isEmpty())
    {
        cout << "\033[0;31mERROR: Process Scheduler is empty...\033[0m " << endl;
        return;
    }
    
    cout << endl;
    
    // Running deleteMax process
    cout << "Running DeleteMax... " << endl;
    nanosleep(&timeOut, &remains);
    printMaxHeapPair();
    for (int i = 2; i < position; i++)
    {
        cout << "Running DeleteMax... " << endl;
        nanosleep(&timeOut, &remains);
        deleteMaxPair();
        printMaxHeapPair();
    }
    
    // output success after remove max is complete
    cout << "\n\033[0;32mDeleteMax successful...\033[0m " << endl << endl;
    nanosleep(&timeOut, &remains);
    
    // output queue times
    while (!pq.empty())
    {
        const auto& procPairTemp = pq.top();
        int waitTime = 0;
        
        waitTime = procPairTemp.second;
        if (procPairTemp.first < 10)
        {
            cout << "Process # " << procPairTemp.first << ": " << "Total queue time: " << totalQueueTime << "sec. " << endl;
        
        }
        else
        {
            cout << "Process #" << procPairTemp.first << ": " << "Total queue time: " << totalQueueTime << "sec. " << endl;
        }
        pq.pop();
        totalQueueTime = totalQueueTime + waitTime;
    }
    
    // output queuetimes for bonus
    while (!runTimePq.empty())
    {
        const auto& procPairTemp = runTimePq.top();
        int waitTime = 0;
        
        waitTime = procPairTemp.first;
        if (procPairTemp.second < 10)
        {
            cout << "Process # " << procPairTemp.second << ": " << "Total queue time: " << totalQueueTime << "sec. " << endl;
        }
        else
        {
            cout << "Process #" << procPairTemp.second << ": " << "Total queue time: " << totalQueueTime << "sec. " << endl;
        }
        runTimePq.pop();
        totalQueueTime = totalQueueTime + waitTime;
    }
    
    // after running priority queue, variables are re-initalized since queue is now empty
    index = 0;
    position = 1;
    totalQueueTime = 0;
    count = 1;
}

/*
 ============================================================================
 Function    : printProcs()
 Parameters  : nothing
 Return      : nothing
 Description : prints out array of procs added before heapifying, and then
 a configured list of the heap
 ============================================================================
 */

void Heap::printProcs()
{
    if (isEmpty())
    {
        cout << "\033[0;31mERROR: Process Scheduler is empty...\033[0m " << endl;
        return;
    }
    
    // print array and heap
    //cout << "========================================================================"<< endl;
    cout << "Entered Processes: " << endl;
    cout << "| ";
    for (int i = 1; i < position; i++)
    {
        cout << p->getProcPriority(i) << "," << p->getProcRunTime(i) << " | ";
    }
    cout << endl << endl;
    cout << "Configured/Heapified Priorities: " << endl;
    printMaxHeapPair();
    //cout << "========================================================================"<< endl;
}

/*
 ============================================================================
 Function    : userAddProc()
 Parameters  : nothing
 Return      : nothing
 Description : this function allows the user to manually add a process and 
 its runtime, also adds to heap and re-heapify
 ============================================================================
 */

void Heap::userAddProc()
{
    int procTemp;
    int runTimeTemp;
    
    // prompt user
    cout << "Enter Process priority #: ";
    cin  >> procTemp;
    cin.ignore();
    
    if (!cin)
    {
        cout << "\033[0;31mERROR: Value entered is not a integer value...please try again.\033[0m " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    
    // set process priority
    p->setProcPriority(position, procTemp);
    
    // prompt user
    cout << "Enter Process run-time (in seconds): ";
    cin  >> runTimeTemp;
    cin.ignore();
    
    if (!cin)
    {
        cout << "\033[0;31mERROR: Value entered is not a integer value...please try again.\033[0m " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    
    // set process runtime
    p->setProcRunTime(position, runTimeTemp);
    
    cout << "\033[0;32mAdded: " << p->getProcPriority(position) << "," << p->getProcRunTime(position) << "\033[0m" << endl;
    
    // set queue
    pq.emplace(p->getProcPriority(position),p->getProcRunTime(position));
    
    // set pair
    setProcPair(position, make_pair (p->getProcPriority(position),p->getProcRunTime(position)));
    
    // heapify
    heapifyPair(getProcPair(position));
    
    position++;
    count++;
}

/*
 ============================================================================
 Function    : runTimePriority() ****BONUS*****
 Parameters  : nothing
 Return      : nothing
 Description : this bonus function will run if user wanted priority over run
 times, and will swap values accordly and re-heapify the heap to satisfy the 
 swaps
 ============================================================================
 */

void Heap::runTimePriority()
{
    if (isEmpty())
    {
        cout << "\033[0;31mERROR: Process Scheduler is empty...\033[0m " << endl;
        return;
    }
    
    // print pre-configured heap
    cout << "Process priorities to be swapped with run-time priority: " << endl;
    printMaxHeapPair();
    
    while (!pq.empty())
    {
        pq.pop();
    }
    
    while (!runTimePq.empty())
    {
        runTimePq.pop();
    }
    
    // loop through size of heap
    for (int i = 1; i < position; i++)
    {
        // swap values insides each pair in the heap
        // (2,12) -> (12,2)
        swap(get<0>(procPair[i]),get<1>(procPair[i]));
        
        // re-add values to back-up queue and re-heap the above swaps
        runTimePq.emplace(procPair[i].first, procPair[i].second);
        bubbleUpPair(procPair, i);
        
    }
    
    // print new configured heap
    cout << "Run-time priority swap successful: " << endl;
    printMaxHeapPair();
}