Program #2
SkipList
By: Brandon Reid

Program runs on c++11 -std=c++0x
USES MAKEFILE

HOW TO USE:

1. After unzipping, cd your way to the folder
2. USE MAKEFILE
	- once in the folder type “make” (this will compile)
	- after compilation is successful type “make run”
	- at the moment the first value entered is not added to the list
	— please enter the value 0 first like you see in the example below
	- then continue, this does not have to be done, will still work either way

  +——-—CMDS————-—————+		example commands:
  | Add(WORKING)     |		
  | Remove(WORKING)  |		> add
  | Search(WORKING)  |		Enter Value: 0
  | Print(FIXED!)    |
  | Commands(WORKING)|		> print
  | Quit(WORKING)    |		0 1 2 3 4 5 6 7 8 9	<—— the zeros are head nodes
  +———————————-——————+		0 2 4 6
				0 6
				0

THINGS YOU SHOULD KNOW:
1. For a successful list, add the first element in your list as 0 for some reason first insertion isn’t added to list
I believe this is due to the first initialization of the head.

KNOWN BUGS:

1. Memory Allocations seem weird, but not getting anymore segmentation faults
	UPDATE 7/20/16
	- Seems all fixed up!

2. Insertion working, but doesn’t add the first element added by user to list (still looking for solution)

3. Searching the classic skip list way from the top head directly over and down until target was found.. gave me troubles
so i decided to make an L shape style search where it goes down the heads and searches the full list iteratively along the bottom

The parameters of the program did not require a optimal runtime, so I implemented the search this way, though it is very sloppy and slower then O(logn)
H
H  |
H  |
H  v
H  ——————>
H 0 1 2 3 4 5 6

Over all reflections on program:

Before the professor went over skip lists I had never heard of them, and found this program to be quite the challenge.

I struggle with keeping track of how each pointer is being declared and allocated throughout the program and through each iteration.

I understand how the code SHOULD be implemented, but actually implementing it in this way was extremely challenging. (was able to overcome the challenge)

I’ve realized that I have been hindering my programming abilities over the last year by always using STL and containers. Since these are readily available in the C++ library I came accustomed to using them right away.

But with using these libraries I don’t fully understand the science of how these containers are implemented.

these containers include, lists, trees, stacks, queues, etc.

While I know these containers will always be available, and in the real world these are what would be used.. it’s better that i know how to implement these data structures from scratch to gather a better understand of how these things work.

UPDATE:
7/20/16

I have really started to grasp the understanding of skip lists, and lists alike, this assignment really helped me better understand memory allocation and pointers

I spent all day today working on the program and have really gotten a lot of the bulk working now, and am happy with my results. I have a lot better understanding of skip list implementations now, and other lists alike. 
