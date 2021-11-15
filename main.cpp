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

	/******************** LINKED LIST *************************/
	
	// MACRO STYLE
	int arr[3]{ 11,22,33 };

	LINKED_LIST* macro_style_list = NEW_LINKED_LIST();  // creating new linked list
	NODE* macro_style_node = NEW_NODE(1);               // creating new node    

	// PREPEND_NODE
	PREPEND_NODE(macro_style_list, NEW_NODE(arr[0]));
	PREPEND_NODE(macro_style_list, NEW_NODE(arr[1]));
	PREPEND_NODE(macro_style_list, NEW_NODE(arr[2]));
	PRINT_LIST(macro_style_list);

	ee;

	//DELETE_NODE
	DELETE_NODE(macro_style_list, 22);
	PRINT_LIST(macro_style_list);
	ee;

	//APPEND_NODE
	APPEND_NODE(macro_style_list, NEW_NODE(arr[0]));
	APPEND_NODE(macro_style_list, NEW_NODE(arr[1]));
	APPEND_NODE(macro_style_list, NEW_NODE(arr[2]));
	PRINT_LIST(macro_style_list);

	ee;

	//TO_ARRAY_NODES
	int* array_list = TO_ARRAY_NODES(macro_style_list);
	for (int a = 0; a < macro_style_list->size_of_list; a++)
		o << array_list[a] << " ";
	ee;

	// REVERSE_LIST
	REVERSE_LIST(macro_style_list);
	PRINT_LIST(macro_style_list);
	ee;

	//CLEAR_LIST
	CLEAR_LIST(macro_style_list);
	PRINT_LIST(macro_style_list);
	ee;

	//FROM_ARRAY_NODES
	macro_style_list = FROM_ARRAY_NODES(arr, (sizeof(arr) / sizeof(arr[0])));
	PRINT_LIST(macro_style_list);
	ee;

	// FIND_NODE
	NODE* searched = FIND_NODE(macro_style_list, 22);
	o << "RESULT: " << searched->value << e;
	ee;

	//TO_STRING_NODES
	string res = TO_STRING_NODES(macro_style_list);
	o << res << e;
	ee;

	//DELETE_HEAD_NODE
	DELETE_HEAD_NODE(macro_style_list);
	PRINT_LIST(macro_style_list);
	ee;

	//DELETE_TAIL_NODE
	DELETE_TAIL_NODE(macro_style_list);
	PRINT_LIST(macro_style_list);
	ee;

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