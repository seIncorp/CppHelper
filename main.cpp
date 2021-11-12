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
	// Macro return index of searched value
	int ar[]{ 11, 22, 33, 55 };
	
	o << LINEAR_SEARCH(ar, sizeof(ar) / sizeof(ar[1]), 55) << e;
	/************************************************/

	/******************** 5 *************************/
	LINKED_LIST* test_list = NEW_LINKED_LIST();
	for (int a = 0; a < 5; a++)
	{
		o << arr[a] << e;

		NODE* nn = NEW_NODE(arr[a]);
		o << "v: " << nn->value << e;

		//APPEND_NODE(test_list,nn);
		// or
		PREPEND_NODE(test_list, nn);
	}


	NODE* temp = (*list).head;
	while (1)
	{
		o << temp->value << e;

		if (temp->next != NULL)
			temp = (NODE*)temp->next;
		else
			break;
	}
	/************************************************/

	/******************** 6 *************************/
	// From array

	int arr[]{ 5,4,3,2,1 };

	LINKED_LIST* test_list1 = FROM_ARRAY_NODES(arr, sizeof(arr) / sizeof(arr[1]));

	NODE* temp2 = (*test_list1).head;
	while (1)
	{
		o << temp2->value << e;

		if (temp2->next != NULL)
			temp2 = (NODE*)temp2->next;
		else
			break;
	}

	/************************************************/

	/******************** 7 *************************/
	// Search for one node
	NODE* rtd = FIND_NODE(test_list, 3);

	o << "SEARCHED:  " << rtd->value << e;

	/************************************************/

	/******************** 8 *************************/
	
	DELETE_NODE(test_list1, 2);
	// or
	DELETE_HEAD_NODE(test_list);
	// or
	DELETE_TAIL_NODE(test_list);

	/************************************************/

	/******************** 9 *************************/

	// Linkedlist to String
	string str = TO_STRING_NODES(test_list);
	o << str << e;
	/************************************************/


	/******************** BIT MANIPULATION *************************/

	// SHOW IN BITS
	int a = 4;
	SHOW_IN_BITS(1, a, int); // here you have RTL and length of bits is 32-bit, because int is 32-bit
	ee;

	// SET ONE BIT TO 1
	a = SET_BIT_INT(a, 3); // here you must add bit position

	// CLEAR BIT, changing from 1 to 0
	a = CLEAR_BIT_INT(a, 3); // here you must add bit position

	// CHECK IF NUMBER IS EVEN
	o << IS_EVEN(5) << e;

	// CHECK IF THE NUMBER IS POSITIVE
	o << IS_POSITIVE_NUMBER(-5, int) << e;	// here you must add type of number

	// MULTIPLY THE NUMBER BY TWO
	o << MULTIPLY_BY_TWO(8) << e;

	// DIVIDE THE NUMBER BY TWO
	o << DIVIDE_BY_TWO(8) << e;

	// CHANGE SIGN OF THE NUMBER FROM + TO - OR VICE VERSA
	o << SWITCH_SIGN(8) << e;

	// MULTIPLY TWO UNSIGNED NUMBERS
	o << MULTIPLAY_TWO_UNSIGNET_NUMBERS(8, 3) << e;

	// COUNT HOW MANY 1's ARE IN THE NUMBER
	o << COUNT_SET_BITS(8) << e;

	// COUNT HOW MANY DIFFERENT BITS ARE INT TWO NUMBERS
	o << COUNT_BITS_DIFF(8, 1) << e;

	// REAL BITS LENGTH OF THE NUMBER
	o << BITS_LENGTH(8) << e;	// 8 --> 1000 <-- this is real length and not lengt of int --> 32-bit


	/************************************************/
}