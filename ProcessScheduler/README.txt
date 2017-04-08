Program #4
Naive Process Scheduler
Brandon Reid

Welcome!

program uses c++11 please use makefile to compile
or
g++ -std=c++0x main.cpp heap.cpp process.cpp

you need a .txt file to load in data
you are welcome to use the one I provided in zip
or use your own

HOW TO USE:

- once file is zipped, cd to folder location
- make
- make run
- then type one of the following commands from the menu:

	Load     - will load a FILE with data in the form (2,20)
	Add      - insert priority/runtime manually *EXTRA*
	print    - print array and heap
	priority - swap process and runtime priority  *BONUS*
	run      - run deleteMax, output queue time
	commands - output commands
	quit     - exit

Bugs:
No major bugs

Algorithm reflections:

- choose option #2
- implemented an array, and did max heap with a logic tree implementation
- instead of making it complicated with keeping track of which process is with which runtime
I decided to heapify an array of “pairs” the pairs containing the process and its runtime
- heapifying an array of pairs in a logic tree manner became trivial as we had already discussed
the algorithm in class

- c++ has about 5 different ways to implement priority queues, max heaps, and binary heaps
	
