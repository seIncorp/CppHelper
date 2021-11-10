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
	LINKED_LIST* list = NEW_LINKED_LIST();


	PREPEND_NODE(list, NEW_NODE(22));
	PREPEND_NODE(list, NEW_NODE(33));
	PREPEND_NODE(list, NEW_NODE(55));

	APPEND_NODE(list, NEW_NODE(11));


	o << "HEAD " << (*list).head->value << e;
	o << "TAIL " << (*list).tail->value << e;

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



}