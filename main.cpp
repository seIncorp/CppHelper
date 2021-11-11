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
}