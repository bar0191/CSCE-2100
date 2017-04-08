README

included:
All source files (.cpp, .hpp)
this README
Makefile

Known Bugs:
InsertAt
RemoveAt

these functions are not implemented properly and need a rework


IF YOU ENTER A VALUE THAT IS NOT A INTEGER INTO THE POSITION VALUE THE PROGRAM WILL CRASH AND GO INTO INFINITE LOOP
PRESS CTRL-C TO ESCAPE THE LOOP AND GO BACK TO TERMINAL

Bonus Program:
How to use:

make sure to use makefile
this program uses c++11, so if you compile without makefile, be sure to do it in c++11

terminal> make 
terminal> make run

         +---Commands---+
         | Append       |
         | InsertAt     |
         | Remove       |
         | RemoveAt     |
         | Search       |
         | Print        |
         | Commands     |
         | Clear        |
         | Quit         |
         +--------------+

You will be prompted with a menu like this one.

simply type the command and you will be prompted to the commands functionality

Append - Append Node at the end of the list
InsertAt - will insert at a position

 0 - 1 - 2 - 3 - 4
head            tail

Remove - remove a node specified by user
RemoveAt - will remove a node at a certain position

 1 - 2 - 3 - 4 - 5
head            tail 

Search - search for node returning true or false
Print  - print nodes from head to tail
commands - will re-output command menu
clear - clear terminal 
quit - quit program

notes:

I started this the day it was due which was irresponsible on my part…there are many requirements and parameters 
that are flawed. 

As I stated in the known bugs, these functions cause bugs because their pointers are not set to point to the proper nodes
so when you try to delete a node that was added using the InsertAt function, the search function will not find this node

if you delete every single node, down to the nodes that are left from the InsertAt function, and try to delete these, segmentation fault: 11 error will occur

Under time constraints I was able to get about 75-80% of the program fully functioning, but is missing error checks in some cases

if you enter a value that is not an integer in the position input the error default in the switch statement will continue to loop until terminal is terminated
