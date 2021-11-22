#ifndef FAST_H
#define FAST_H

#include <iostream>
#include <climits>
#include <vector>
#include <Windows.h>
#include <string>
#include <math.h>
#include <functional>



#define E "\n"
#define T "\t"


/* iostream */
#define o   std::cout
#define i   std::cin
#define er  std::cerr
#define l   std::clog
#define e   std::endl
#define ee  (o << e)


#define string std::string


#define Vi std::vector<int>
#define Vd std::vector<double>
#define Vl std::vector<long>
#define Vc std::vector<char>
#define Vs std::vector<string>

#define Vi2D std::vector<std::vector<int>>


#define BAon     (o << std::boolalpha)
#define BAoff    (o << std::noboolalpha)




/*Algorithms by Paradigm*/

/*Brute Force*/

#define LINEAR_SEARCH(_x_, _len_, _v_) ({ \   
int* _a_ = (_x_); \
int _c_ = 0; \
int _res_ = 0; \
while (_c_ < (_len_)) \
{ \
if (*(_a_ + _c_) == _v_) {/*printf("%d ",*(a+c) );*/ _res_ = _c_; } _c_++; \
} \
_res_; \
})


/*Algorithms*/

/* Math */
#include "macroMath.h"








/*Data Structures*/

/*Linked list*/
#include "linkedlist.h"
/* Doubly Linked List */
#include "doublyLinkedList.h"
/* Queue */
#include "queue.h"
/* Stack */
#include "stack.h"
/* Heap */
#include "heap.h"
/* Hash Table */
#include "hashTable.h"



/* Bit Manipulation */

#include "bitManipulation.h"


#include "Examples.h"



#endif