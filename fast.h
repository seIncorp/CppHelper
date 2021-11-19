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

/*Factorial*/
// TODO: recursive with function
#define FACTORIAL(_n_) ({ \
	int _res_ = 1; \
	int _i_ = 2; \
	while(_i_ <= (_n_) ) \
	{ \
		_res_ *= _i_; \
		_i_++; \
	} \
	_res_; \
})

/*fibonacci*/
// return whole array of every step
#define FIBONACCI(_n_) ({ \
	std::vector<int> _a_ ; \
	int _c_ = 1; \
	int _p_ = 0; \
	 \
	if(_n_ == 1)  \
	{ \
	 _a_.push_back(1); \
	} \
	else \
	{ \
		int _i_ = _n_ - 1; \
		_a_.push_back(1); \
		while (_i_) \
		{ \
			_c_ += _p_; \
			_p_ = _c_ - _p_; \
			_a_.push_back(_c_); \
			_i_--; \
		} \
	} \
	_a_; \
})

// return only the last step
#define FIBONACCINth(_n_) ({ \
	int _c_ = 1; \
	int _p_ = 0; \
	if (_n_ == 1)  \
	{ \
		_c_ = 1; \
	} \
	else \
	{ \
		int _i_ = _n_ - 1; \
		while (_i_)  \
		{ \
			_c_ += _p_; \
			_p_ = _c_ - _p_; \
			_i_--; \
		} \	
	} \
	_c_; \
})

#define FIBONACCIClosedForm(_n_) ({ \
	int topMaxValidPosition = 70; \
	int res = 0; \
	if (_n_ < 1 || _n_ > topMaxValidPosition) { \
		er << "Can't handle position smaller than 1 or greater than ${topMaxValidPosition}"; \
	} \
	double sqrt5 = sqrt(5); \
	double phi = (1 + sqrt5) / 2; \
	res = floor(( pow(phi, _n_) ) / sqrt5 + 0.5); \
	res; \
})








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
