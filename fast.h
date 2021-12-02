#ifndef FAST_H
#define FAST_H

#include <iostream>
#include <climits>
#include <vector>
#include <Windows.h>
#include <string>
#include <math.h>
#include <functional>
#include <cmath>
#include <array>


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
#include "macroSearches.h"




/*Algorithms*/

/* Math */
#include "macroMath.h"

/* Sets */
#include "macroSets.h"

/* Sorting */
#include "macroSorting.h"






/*Data Structures*/
#include "macroDataStructure.h"







#include "Examples.h"



#endif