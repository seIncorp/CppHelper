#pragma once

#include <iostream>
#include <climits>
#include <vector>


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


/*Algorithms by Paradigm*/

/*Brute Force*/

/*WARNINIG:  build on VS 2019 failed. On Codelite or using g++ work normaly.*/
#define LINEAR_SEARCH(x, len, v) ({ \ 
/*
	arg1: pointer to first element in array
	arg2: length of array
	arg3: value for search

	return: index of searched value
*/
	int* a = (x); \
	int c = 0; \
	int res = 0; \
	while (c < (len)) \
	{ \
		if (*(a + c) == v) {res = c; } c++; \
	} \
	res; \
})

/*Data Structures*/

/*Linked list*/

#include "linkedlist.h"

/* Bit Manipulation */

#include "bitManipulation.h"