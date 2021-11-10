#include "fast.h"

int main(int argc, char* av[])
{
	/* EXAMPLES */

	/******************** 1 *************************/
	// Old style
	std::cout << "Old style (Example 1)" << std::endl;

	// New style
	o << "New style (Example 1)" << e;
	/************************************************/

	/******************** 2 *************************/
	// Old style
	std::cout << "Old style (Example 2)";
	std::cout << std::endl;

	// New style
	o << "New style (Example 2)";
	ee;
	/************************************************/

	/******************** 3 *************************/
	// Old style
	std::vector<int> test_1;

	// New style
	Vi test_2; // for integers
	Vd test_3; // for doubles
	Vl test_4; // for longs
	Vc test_5; // for characters
	/************************************************/

	/******************** 3 *************************/
	// Old style
	std::cout << std::boolalpha;
	std::cout << (1 == 2) << std::endl;
	std::cout << std::noboolalpha;

	// New style
	BAon;
	o << (1 == 2) << e;
	BAoff;
	/************************************************/

	/******************** 4 *************************/
	int ar[]{ 11, 22, 33, 55 };
	
	o << LINEAR_SEARCH(ar, sizeof(ar) / sizeof(ar[1]), 55) << e;
	/************************************************/
}