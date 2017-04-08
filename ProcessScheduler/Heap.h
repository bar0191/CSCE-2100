//  Program 4
//  Heap.h
//  Naive Process Scheduler
//
//  Created by Brandon Reid on 8/3/16.
//
//
//  Refer to README for further comments on algorithm of the program
//

#ifndef Heap_h
#define Heap_h

#include "Process.h"

/*
 ============================================================================
 Class             : Heap
 Private Variables : process class ptr, pair, index, pos, count, queue, fin
 Description       : This Class manages the max heap, and functionality of
 the program, adds, deletes, prints, communicates with process data by ptr
 ============================================================================
 */

class Heap
{
private:
    Process* p;                                             // ptr to process
    pair <int, int> procPair[maxSize];                      // pair for procs
    ifstream fin;                                           // file type
    int index;                                              // index - sizeOf()
    int position;                                           // positions
    int count;                                              // user counts
    string proc;                                            // user string
    string runTime;                                         // user string
    priority_queue<pair<int, int>> pq, runTimePq;           // queues
public:
    Heap();                                                 // constructor
    ~Heap();                                                // deconstructor
    pair<int,int> getProcPair(int size) const;              // getter
    void setProcPair(int size, pair<int,int> pairValue);    // setter
    void bubbleUpPair(pair<int,int> pos[], int i);          // BubbleUp
    void heapifyPair(pair<int,int> pairValue);              // Heapify (insert)
    void printMaxHeapPair();                                // print Heap
    void printProcs();                                      // print array
    void bubbleDownPair(pair<int,int> pos[], int size);     // BubbleDown
    pair<int,int> deleteMaxPair();                          // DeleteMax
    bool isEmpty();                                         // isEmpty
    void loadProcs();                                       // load file
    void runPriorityQueue();                                // run prior queue
    void userAddProc();                                     // user insert
    void runTimePriority();                                 // swap prior/runtime
};

typedef Heap* HeapPtr;                                      // communcation ptr

#endif