#include <iostream>
#include <climits>
#include <vector>
#include <Windows.h>
#include <string>


#define E "\n"
#define T "\t"


/* iostream */
#define o   std::cout
#define i   std::cin
#define er  std::cerr
#define l   std::clog
#define e   std::endl
#define ee  (o << e)


#define Vi std::vector<int>
#define Vd std::vector<double>
#define Vl std::vector<long>
#define Vc std::vector<char>

#define Vi2D std::vector<std::vector<int>>


#define BAon     (o << std::boolalpha)
#define BAoff    (o << std::noboolalpha)

#define string std::string


/*Algorithms by Paradigm*/

/*Brute Force*/

#define LINEAR_SEARCH(_x_, _len_, _v_) ({ \   
int* a = (_x_); \
int c = 0; \
int res = 0; \
while (c < (_len_)) \
{ \
if (*(a + c) == _v_) {/*printf("%d ",*(a+c) );*/ res = c; } c++; \
} \
res; \
})


/*Data Structures*/

/*Linked list*/

#include "linkedlist.h"

/* Doubly Linked List */
#include "doublyLinkedList.h"

/* Queue */
#include "queue.h"





/* Bit Manipulation */

#include "bitManipulation.h"
