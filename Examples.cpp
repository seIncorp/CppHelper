#include "fast.h"

void bit_manipulation_examples()
{
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


}

void stack_examples()
{
    // MACRO style
    STACK* stack2 = NEW_STACK();
    ee;
    o << "IS EMPTY: " << (IS_EMPTY_STACK(stack2) == TRUE ? "TRUE" : "FALSE") << e;
    ee;
    o << "PEEK: " << PEEK_STACK(stack2) << e;
    ee;
    PUSH_STACK(stack2, 1);
    PUSH_STACK(stack2, 2);
    PUSH_STACK(stack2, 3);
    o << "PEEK: " << PEEK_STACK(stack2) << e;
    ee;
    o << "POP: " << POP_STACK(stack2) << e;
    ee;
    o << "PEEK: " << PEEK_STACK(stack2) << e;
    ee;
    PUSH_STACK(stack2, 4);
    int* arr77 = TO_ARRAY_STACK(stack2);
    for (int a = 0; a < stack2->stack->size_of_list; a++)
        o << arr77[a] << " ";
    ee;
    o << TO_STRING_STACK(stack2) << e;
    ee;


    // class style

    STACK* stack = new STACK();
    ee;
    o << "IS EMPTY: " << (stack->isEmpty() == TRUE ? "TRUE" : "FALSE") << e;
    ee;
    stack->push(1);
    stack->push(2);
    o << "PEEK: " << stack->peek() << e;
    ee;
    o << "POP: " << stack->pop() << e;
    ee;
    o << "PEEK: " << stack->peek() << e;
    ee;
    stack->push(3);
    stack->push(4);
    stack->push(5);
    int ar55[stack->stack->size_of_list]{ 0 };
    stack->toArray(ar55);
    for (int a = 0; a < stack->stack->size_of_list; a++)
        o << ar55[a] << " ";
    ee;
    o << "PEEK: " << stack->peek() << e;
    ee;
    o << stack->toString() << e;
    ee;

}

void queue_examples()
{
    //MACRO version
    QUEUE* q2 = NEW_QUEUE();
    ee;
    o << "IS EMPTY: " << (IS_EMPTY_QUEUE(q2) == 1 ? "TRUE" : "FALSE") << e;
    ee;
    o << "PEEK: " << PEEK_QUEUE(q2) << e;
    ee;
    ENQUEUE_QUEUE(q2, 1);
    ENQUEUE_QUEUE(q2, 2);
    o << "PEEK: " << PEEK_QUEUE(q2) << e;
    ee;
    o << "DEQUEUE: " << DEQUEUE_QUEUE(q2) << e;
    ee;
    o << "PEEK: " << PEEK_QUEUE(q2) << e;
    ee;
    ENQUEUE_QUEUE(q2, 3);
    o << TO_STRING_QUEUE(q2) << e;
    ee;


    // class version
    QUEUE* q = new QUEUE();
    ee;
    o << "IS EMPTY: " << (q->isEmpty() == 1 ? "TRUE" : "FALSE") << e;
    ee;
    o << "PEEK: " << q->peek() << e;
    ee;

    q->enqueue(1);
    q->enqueue(2);
    o << "PEEK: " << q->peek() << e;
    ee;

    o << "DEQUEUE: " << q->dequeue() << e;
    ee;
    o << "PEEK: " << q->peek() << e;
    ee;
    q->enqueue(3);

    o << q->toString() << e;
    ee;
}

void doublyLinkedList_examples()
{
    // CLASS FUNCTION STYLE
    int arr2[3]{ 11,22,33 };

    // MACRO STYLE

    D_LINKED_LIST* macro_style_doubly_list1 = D_NEW_LINKED_LIST();

    //    D_PREPEND_NODE
    D_PREPEND_NODE(macro_style_doubly_list1, D_NEW_NODE(arr2[0]));
    D_PREPEND_NODE(macro_style_doubly_list1, D_NEW_NODE(arr2[1]));
    D_PREPEND_NODE(macro_style_doubly_list1, D_NEW_NODE(arr2[2]));
    D_PRINT_LIST(macro_style_doubly_list1);
    ee;

    //    D_DELETE_NODE
    D_DELETE_NODE(macro_style_doubly_list1, 11, 0);
    D_DELETE_NODE(macro_style_doubly_list1, 33, 0);
    D_DELETE_NODE(macro_style_doubly_list1, 22, 0);
    D_PRINT_LIST(macro_style_doubly_list1);
    ee;

    //    D_APPEND_NODE
    D_APPEND_NODE(macro_style_doubly_list1, D_NEW_NODE(arr2[0]));
    D_APPEND_NODE(macro_style_doubly_list1, D_NEW_NODE(arr2[1]));
    D_APPEND_NODE(macro_style_doubly_list1, D_NEW_NODE(arr2[2]));
    D_PRINT_LIST(macro_style_doubly_list1);
    ee;

    //    D_TO_ARRAY_NODES
    int* array_list2 = D_TO_ARRAY_NODES(macro_style_doubly_list1);
    for (int a = 0; a < macro_style_doubly_list1->size_of_list; a++)
        o << array_list2[a] << " ";
    ee;

    //    D_REVERSE_LIST
    D_REVERSE_LIST(macro_style_doubly_list1);
    D_PRINT_LIST(macro_style_doubly_list1);
    ee;

    //    D_CLEAR_LIST
    D_CLEAR_LIST(macro_style_doubly_list1);
    D_PRINT_LIST(macro_style_doubly_list1);
    ee;

    //    D_FROM_ARRAY_NODES
    macro_style_doubly_list1 = D_FROM_ARRAY_NODES(arr2, 3);
    D_PRINT_LIST(macro_style_doubly_list1);
    ee;

    //    D_FIND_NODE
    D_NODE* searched4 = D_FIND_NODE(macro_style_doubly_list1, 11);
    o << "RESULT: " << searched4->value << e;
    ee;

    //    D_TO_STRING_NODES
    string lis = D_TO_STRING_NODES(macro_style_doubly_list1);
    o << lis << e;
    ee;

    //    D_DELETE_HEAD_NODE
    D_DELETE_HEAD_NODE(macro_style_doubly_list1);
    D_PRINT_LIST(macro_style_doubly_list1);
    ee;

    //    D_DELETE_TAIL_NODE
    D_DELETE_TAIL_NODE(macro_style_doubly_list1);
    D_PRINT_LIST(macro_style_doubly_list1);
    ee;


    // CLASS FUNCTION STYLE

    D_LINKED_LIST* class_style_doubly_list2 = new D_LINKED_LIST();

    //    prepend
    class_style_doubly_list2->prepend(new D_NODE(arr2[0]));
    class_style_doubly_list2->prepend(new D_NODE(arr2[1]));
    class_style_doubly_list2->prepend(new D_NODE(arr2[2]));
    class_style_doubly_list2->printList();
    ee;

    //    delete_node
    class_style_doubly_list2->delete_node(22, 0);
    class_style_doubly_list2->printList();
    ee;

    //    append
    class_style_doubly_list2->append(new D_NODE(arr2[0]));
    class_style_doubly_list2->append(new D_NODE(arr2[1]));
    class_style_doubly_list2->append(new D_NODE(arr2[2]));
    class_style_doubly_list2->printList();
    ee;

    //    to_array
    int array_list3[class_style_doubly_list2->size_of_list]{ 0 };
    class_style_doubly_list2->to_array(array_list3);
    for (int a = 0; a < class_style_doubly_list2->size_of_list; a++)
        o << array_list3[a] << " ";
    ee;

    //    reverse
    class_style_doubly_list2->reverse();
    class_style_doubly_list2->printList();
    ee;

    //    clear
    class_style_doubly_list2->clear();
    class_style_doubly_list2->printList();
    ee;

    //    from_array
    class_style_doubly_list2->from_array(arr2, (sizeof(arr2) / sizeof(arr2[0])));
    class_style_doubly_list2->printList();
    ee;

    //    find_node
    D_NODE* searched3 = class_style_doubly_list2->find_node(22);
    o << "RESULT: " << searched3->value << e;
    ee;

    //    to_string
    string res3 = class_style_doubly_list2->to_string();
    o << res3 << e;
    ee;

    //    delete_head
    class_style_doubly_list2->delete_head();
    class_style_doubly_list2->printList();
    ee;

    //    delete_tail
    class_style_doubly_list2->delete_tail();
    class_style_doubly_list2->printList();
    ee;
}

void linkedList_examples()
{
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


    // CLASS FUNCTION STYLE
    int arr1[3]{ 11,22,33 };

    LINKED_LIST* class_style_list2 = new LINKED_LIST();  // creating new linked list
    NODE* macro_style_node2 = new NODE(1);               // creating new node    

    // PREPEND_NODE
    class_style_list2->prepend(new NODE(arr1[0]));
    class_style_list2->prepend(new NODE(arr1[1]));
    class_style_list2->prepend(new NODE(arr1[2]));
    class_style_list2->printList();

    ee;

    //DELETE_NODE
    class_style_list2->delete_node(22, 0);
    class_style_list2->printList();
    ee;

    //APPEND_NODE
    class_style_list2->append(new NODE(arr1[0]));
    class_style_list2->append(new NODE(arr1[1]));
    class_style_list2->append(new NODE(arr1[2]));
    class_style_list2->printList();
    ee;

    //TO_ARRAY_NODES
    int array_list1[class_style_list2->size_of_list]{ 0 };
    class_style_list2->to_array(array_list1);
    for (int a = 0; a < class_style_list2->size_of_list; a++)
        o << array_list1[a] << " ";
    ee;

    // REVERSE_LIST
    class_style_list2->reverse();
    class_style_list2->printList();
    ee;

    //CLEAR_LIST
    class_style_list2->clear();
    class_style_list2->printList();
    ee;

    //FROM_ARRAY_NODES
    class_style_list2->from_array(arr1, (sizeof(arr1) / sizeof(arr1[0])));
    class_style_list2->printList();
    ee;

    // FIND_NODE
    NODE* searched2 = class_style_list2->find_node(22);
    o << "RESULT: " << searched2->value << e;
    ee;

    //TO_STRING_NODES
    string res2 = class_style_list2->to_string();
    o << res2 << e;
    ee;

    //DELETE_HEAD_NODE
    class_style_list2->delete_head();
    class_style_list2->printList();
    ee;

    //DELETE_TAIL_NODE
    class_style_list2->delete_tail();
    class_style_list2->printList();
    ee;
}

void linearSearch_examples()
{
    // Macro return index of searched value
    int ar[]{ 11, 22, 33, 55 };

    o << LINEAR_SEARCH(ar, sizeof(ar) / sizeof(ar[1]), 55) << e;
}

void shortCuts_examples()
{
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
}

void fibonacci_examples()
{
    Vi aa = FIBONACCI(7);

    for (int a = 0; a < aa.size(); a++)
        o << aa[a] << " ";
    ee;

    o << FIBONACCINth(7) << e;
    ee;
    o << FIBONACCIClosedForm(7) << e;
    ee;
}

void factorial_examples()
{
    o << FACTORIAL(5) << e;
}

void hash_table_examples()
{
    // class functions style
    HASH_TABLE* hh_1 = new HASH_TABLE();
    ee;
    o << hh_1->hash("TEST") << e;
    ee;

    hh_1->printKeys();
    ee;

    hh_1->set("TEST", 132);

    hh_1->printKeys();
    ee;
    hh_1->printBuckets();
    ee;

    o << hh_1->get("TEST") << e;

    o << "HAS: " << hh_1->has("TEST") << e;
    ee;

    int* arr = hh_1->getValues();
    for (int a = 0; a < hh_1->all_size; a++)
        o << *(arr + a) << " ";
    ee;

    // WARNING: IT MUST BE DELETED WHEN YOU GOT POINTER OF ARRAY FROM FUNCTION, BECAUSE IT IS OUT OF LOCAL SCOPE
    delete[] arr;

    std::vector<KEYS> tttt = hh_1->getKeys();
    for (int a = 0; a < tttt.size(); a++)
    {
        o << "Key: " << tttt[a].key << " --> keyHash: " << tttt[a].keyHash << e;
    }

    o << "DELETED: " << hh_1->deleteK("TEST") << e;
    ee;

    hh_1->printKeys();
    ee;



    // macro style

    HASH_TABLE* hh_2 = NEW_HASH_TABLE();
    ee;
    o << HASH_OF_HASH_TABLE(hh_2, "TEST") << e;
    ee;
    PRINT_KEYS_HASH_TABLE(hh_2);
    ee;
    SET_HASH_TABLE(hh_2, "TEST", 132);

    PRINT_KEYS_HASH_TABLE(hh_2);
    ee;
    PRINT_BUCKETS_HASH_TABLE(hh_2);
    ee;

    o << GET_HASH_TABLE(hh_2, "TEST") << e;

    o << "HAS: " << HAS_HASH_TABLE(hh_2, "TEST") << e;

    int* arr_2 = GET_VALUES_HASH_TABLE(hh_2);
    for (int a = 0; a < hh_2->all_size; a++)
        o << *(arr_2 + a) << " ";
    ee;

    // WARNING: IT MUST BE DELETED WHEN YOU GOT POINTER OF ARRAY FROM FUNCTION, BECAUSE IT IS OUT OF LOCAL SCOPE
    delete[] arr_2;

    std::vector<KEYS> tttt_2 = GET_KEYS_HASH_TABLE(hh_2);
    for (int a = 0; a < tttt_2.size(); a++)
    {
        o << "Key: " << tttt_2[a].key << " --> keyHash: " << tttt_2[a].keyHash << e;
    }

    o << "DELETED: " << DELETE_PART_HASH_TABLE(hh_2, "TEST") << e;
    ee;

    PRINT_KEYS_HASH_TABLE(hh_2);
    ee;
}

void math_examples()
{
    Vi ttttt = PRIME_FACTORS(147);
    for (int a = 0; a < ttttt.size(); a++)
        o << ttttt.at(a) << " ";
    ee;
    o << HARDYRAMANUJAN_MACRO(147) << e;

    ee;

    o << "2: " << (PRIMALITY_TEST_v1(2) == 1 ? "true" : "false") << e;
    o << "3: " << (PRIMALITY_TEST_v1(3) == 1 ? "true" : "false") << e;
    o << "4: " << (PRIMALITY_TEST_v1(4) == 1 ? "true" : "false") << e;
    o << "5: " << (PRIMALITY_TEST_v1(5) == 1 ? "true" : "false") << e;
    o << "6: " << (PRIMALITY_TEST_v1(6) == 1 ? "true" : "false") << e;
    o << "7: " << (PRIMALITY_TEST_v1(7) == 1 ? "true" : "false") << e;
    o << "8: " << (PRIMALITY_TEST_v1(8) == 1 ? "true" : "false") << e;
    o << "9: " << (PRIMALITY_TEST_v1(9) == 1 ? "true" : "false") << e;
    o << "10: " << (PRIMALITY_TEST_v1(10) == 1 ? "true" : "false") << e;

    ee;

    o << EUCLIDEANALGORITHMITERATIVE(1071, 462) << e;

    ee;
    o << LEASTCOMMONMULTIPLE(3, 5) << e;


    ee;
    Vi tttttt = SIEVE_OF_ERATOSTHENES(30);
    for (int a = 0; a < tttttt.size(); a++)
        o << tttttt.at(a) << " ";
    ee;



    o << (IS_POWER_OF_TWO(10) == 1 ? "true" : "false") << e;
    o << (IS_POWER_OF_TWO_BITWISE(10) == 1 ? "true" : "false") << e;

    ee;


    int test[5][5];
    PASCAL_TRIANGLE(5, test);
    ee;
    for (int a = 0; a < 5; a++)
    {
        for (int aa = 0; aa < 5; aa++)
        {
            test[a][aa] != 0 ? (o << test[a][aa] << " ") : (o << " ");

        }
        ee;
    }
    ee;

    o << "Radians: " << DEGREE_TO_RADIAN(15.0) << e;
    o << "Degrees: " << RADIAN_TO_DEGREE(0.261799) << e;

    ee;
    int aaaa = FAST_POWERING(2, 5);
    o << "FAST POWERING: " << FAST_POWERING(2, 10) << e;

    int arra[]{ 4, 3, 2 };
    int aaaa_3 = HORNER_METHOD(arra, 3, 3);
    o << "HORNER_METHOD: " << aaaa_3 << e;
    ee;


    int bbbb = CLASSIC_POLYNOME(arra, 3, 3);
    o << "CLASSIC_POLYNOME: " << bbbb << e;



}

void sets_examples()
{
    int arr[] = { 1, 2, 3, 4, 5 };
    int r = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    combinations_Without_Repetitions(arr, n, r);
    ee;
    combinations_With_Repetitions(arr, n, r);
    ee;



    int a[]{ 1,2,3 };
    int b[]{ 4,5,6 };
    int ret[3][3][2]{ {{}} };

    if (cartesianProduct(a, 3, 3, b, (int*)ret) == 1)
        o << "ERROR" << e;
    else
    {
        o << "OK" << e;
        ee;
        for (size_t ii = 0; ii < 3; ii++)
        {
            o << ii << ": ";

            for (size_t jj = 0; jj < 3; jj++)
            {
                for (size_t xx = 0; xx < 2; xx++)
                    o << ret[ii][jj][xx] << " ";
                o << '\t';
            }
            ee;
        }

    }


    // function style
    int set[]{ 1,2,3,4 };
    power_set(set, 4);

    // macro style
    std::vector<std::vector<int>> res;
    POWER_SET_MACRO(set, 4, &res);
    ee;
    for (int cc = 0; cc < res.size(); cc++)
    {
        for (int bb = 0; bb < res.at(cc).size(); bb++)
            o << "++ " << res.at(cc).at(bb) << " ";
        ee;
    }


    int originalArray[]{ 1,2,3,4,5 };
    int res_2[5];
    // function style
    fisherYates(originalArray, 5, res_2);

    for (int cc = 0; cc < 5; cc++)
        o << res_2[cc] << " ";

    // macro style
    int res_1[5];
    FISHER_YATES_MACRO(originalArray, 5, res_1);
    for (int cc = 0; cc < 5; cc++)
        o << res_1[cc] << " ";


    KNAPSACK_ITEM* tz[6]{
        new KNAPSACK_ITEM(1,10,1),
        new KNAPSACK_ITEM(2,9,9),
        new KNAPSACK_ITEM(3,8,3),
        new KNAPSACK_ITEM(4,7,4),
        new KNAPSACK_ITEM(5,6,8),
        new KNAPSACK_ITEM(6,5,2)
    };

    KNAPSACK* tt = new KNAPSACK(tz, 6, 11);

    tt->sortPossibleItemsByWeight();
    ee;
    tt->sortPossibleItemsByValue();
    ee;
    tt->sortPossibleItemsByValuePerWeightRatio();
    ee;
    tt->solveUnboundedKnapsackProblem();
    for (int ii = 0; ii < tt->selectedItems.size(); ii++)
        o << tt->selectedItems[ii]->to_string() << e;
    ee;
    tt->solveZeroOneKnapsackProblem();
    for (int ii = 0; ii < tt->selectedItems.size(); ii++)
        o << tt->selectedItems[ii]->to_string() << e;

    ee;
    ee;
    string test_1 = "AGGTABCC";
    string test_2 = "GXCTXAYBC";

    o << longest_common_subsequence(test_1, test_1.length(), test_2, test_2.length()) << e;



    int test[]{ 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
    int* res_55;
    int res_len = longest_increasing_subsequence_length(test, 16);
    res_55 = longest_increasing_subsequence(test, 16);
    for (int ii = 0; ii < res_len; ii++)
        o << res_55[ii] << " ";
    ee;
    delete[] res_55;




}

void sorts_examples()
{

    /* Top-down implementation */
    int aa[]{ 38, 27, 43, 3, 9, 82, 10 };
    int bb[7]{};

    top_down_merge_sort(aa, bb, 7);

    for (int cc = 0; cc < 7; cc++)
        o << aa[cc] << " ";
    ee;

    /* Bottom-up implementation */
    int aa_2[]{ 38, 27, 43, 3, 9, 82, 10 };
    int bb_2[7]{};

    bottom_up_merge_sort(aa_2, bb_2, 7);

    for (int cc = 0; cc < 7; cc++)
        o << aa_2[cc] << " ";
    ee;


}

