class D_NODE {
public:
	int value;
	D_NODE* next;
	D_NODE* previous;

	int print_flag;

	D_NODE()
	{
		value = 0;
		next = NULL;
		previous = NULL;
		print_flag = 0;

		if (print_flag)
			printNode();
	}

	D_NODE(int x)
	{
		value = x;
		next = NULL;
		previous = NULL;
		print_flag = 0;

		if (print_flag)
			printNode();
	}

	~D_NODE();

	printNode()
	{
		o << "******** NODE ********" << e;
		o << "VALUE: " << value << e;

		if (next != NULL)
			o << "NEXT: " << next->value << e;
		else
			o << "NEXT: NULL" << e;

		if (previous != NULL)
			o << "PREVIOUS: " << previous->value << e;
		else
			o << "PREVIOUS: NULL" << e;
	}

	clear()
	{
		value = 0;
		next = NULL;
		previous = NULL;
		print_flag = 0;
	}
};

#define D_NEW_LINKED_LIST() ({ \
    D_LINKED_LIST *_ll_ = new D_LINKED_LIST(); \
    _ll_; \
})

#define D_NEW_NODE(_x_) ({ \
	D_NODE *_dd_ = new D_NODE( (_x_) ); \
	_dd_; \
})

class D_LINKED_LIST {
public:
	D_NODE* head;
	D_NODE* tail;
	int size_of_list;

	D_LINKED_LIST()
	{
		printList();
		head = NULL;
		tail = NULL;
		size_of_list = 0;
	}

	~D_LINKED_LIST();

	printList()
	{
		o << "******** D_LIST ********" << e;

		if (head != NULL)
			o << "HEAD: " << head->value << e;
		else
			o << "HEAD: NULL" << e;

		if (tail != NULL)
			o << "TAIL: " << tail->value << e;
		else
			o << "TAIL: NULL" << e;

		if (head != NULL)
		{
			D_NODE* temp = head;

			while (1)
			{
				o << temp->value << e;

				if (temp->next != NULL)
					temp = temp->next;
				else
					break;
			}
		}
	}

	prepend(D_NODE* n)
	{
		if (head != NULL)
		{
			D_NODE* temp = head;
			head = n;
			head->next = temp;
			temp->previous = head;
		}
		else
		{
			head = n;
			tail = n;
		}

		size_of_list++;
	}

	append(D_NODE* n)
	{
		if (head == NULL)
		{
			head = n;
			tail = n;
		}
		else
		{
			D_NODE* temp = tail;

			temp->next = n;
			n->previous = temp;

			tail = n;
		}

		size_of_list++;
	}

	delete_node(int value, int onlyFirst)
	{
		if (head != NULL)
		{
			D_NODE* temp1 = head;

			// TODO: add for more than one node to delete

			while (1)
			{
				if (temp1->value == value)
				{
					if (onlyFirst == 0)
					{
						temp1->next->previous = temp1->previous;
						temp1->previous->next = temp1->next;

						size_of_list--;

						onlyFirst = 1;
					}
				}

				if (temp1->next != NULL)
					temp1 = temp1->next;
				else
					break;
			}
		}
	}

	D_NODE* find_node(int value)
	{
		D_NODE* temp1 = head;

		while (1)
		{
			if (temp1->value == value)
			{
				break;
			}

			if (temp1->next != NULL)
				temp1 = temp1->next;
			else
			{
				temp1 = NULL;
				break;
			}
		}

		return temp1;
	}

	from_array(int arr[], size_t n)
	{
		for (int II = 0; II < n; II++)
			append(D_NEW_NODE(arr[II]));
	}

	delete_head()
	{
		head = head->next;
		head->previous = NULL;
		size_of_list--;
	}

	delete_tail()
	{
		tail = tail->previous;
		tail->next = NULL;
		size_of_list--;
	}

	to_array(int arr[])
	{
		D_NODE* temp1 = head;
		int II = 0;
		while (1)
		{
			arr[II] = temp1->value;

			if (temp1->next != NULL)
				temp1 = temp1->next;
			else
			{
				temp1 = NULL;
				break;
			}

			II++;
		}
	}

	string to_string()
	{
		string ss = "";

		D_NODE* temp1 = head;
		int II = 0;
		while (1)
		{
			ss += std::to_string(temp1->value);

			if (temp1->next != NULL)
			{
				temp1 = temp1->next;
				ss += ", ";
			}
			else
			{
				temp1 = NULL;
				break;
			}

			II++;
		}

		return ss;
	}

	reverse()
	{
		int seznam[size_of_list]{ 0 };

		to_array(seznam);

		clear();

		for (int aa = 0; aa < (sizeof(seznam) / sizeof(seznam[0])); aa++)
			prepend(D_NEW_NODE(seznam[aa]));
	}

	clear()
	{
		head = NULL;
		tail = NULL;
		size_of_list = 0;
	}
};



#define D_PREPEND_NODE(_l_,_n_) ({ \
    D_LINKED_LIST *_ll1_ = (_l_); \
	D_NODE *_nn_ = (_n_); \
	if(_ll1_->head != NULL) \
		{ \
			D_NODE *_tt_ = _ll1_->head; \
			_ll1_->head = _nn_; \
			_ll1_->head->next = _tt_; \
			_tt_->previous = _ll1_->head; \
		} \
		else \
		{ \
			_ll1_->head = _nn_; \
			_ll1_->tail = _nn_; \
		} \
		 \
		_ll1_->size_of_list++; \
})

#define D_APPEND_NODE(_l_,_n_) ({ \
    D_LINKED_LIST *_ll1_ = (_l_); \
	D_NODE *_nn_ = (_n_); \
	if(_ll1_->head == NULL) \
	{ \
		_ll1_->head = _nn_; \
		_ll1_->tail = _nn_; \
	} \
	else \
	{ \
		D_NODE *_tt_ = _ll1_->tail; \
		 \
		_tt_->next = _nn_; \
		_nn_->previous = _tt_; \
		 \
		_ll1_->tail = _nn_; \
	} \
	 \
	_ll1_->size_of_list++; \
})

#define D_DELETE_NODE(_l_,_v_) ({})

#define D_FIND_NODE(_l_,_v_) ({})

// TODO: dodaj še za drugo smer
#define D_FROM_ARRAY_NODES(_a_,_len_) ({ \
	D_LINKED_LIST *_ll1_ = D_NEW_LINKED_LIST(); \
	int *_arr_ = (_a_); \
	int _xx_ = 0; \
	while( _xx_ < (_len_)) \
	{ \
		D_NODE *_nn_ = D_NEW_NODE(_arr_[_xx_]); \
		if(_ll1_->head == NULL) \
		{ \
			_ll1_->head = _nn_; \
			_ll1_->tail = _nn_; \
		} \
		else \
		{ \
			D_NODE *_tt_ = _ll1_->tail; \
			 \
			_tt_->next = _nn_; \
			_nn_->previous = _tt_; \
			 \
			_ll1_->tail = _nn_; \
		} \
		 \
		_ll1_->size_of_list++; \
		_xx_++; \
	} \
	_ll1_; \
})

#define D_DELETE_HEAD_NODE(_l_) ({ \
    D_LINKED_LIST *_ll1_ = (_l_); \
	_ll1_->head = _ll1_->head->next; \
	_ll1_->head->previous = NULL; \
	_ll1_->size_of_list--; \
})

#define D_DELETE_TAIL_NODE(_l_) ({ \
    D_LINKED_LIST *_ll1_ = (_l_); \
	_ll1_->tail = _ll1_->tail->previous; \
	_ll1_->tail->next = NULL; \
	_ll1_->size_of_list--; \
})

#define D_TO_ARRAY_NODES(_l_) ({ \
    D_LINKED_LIST *_ll1_ = (_l_); \
	D_NODE *_tt_ = _ll1_->head; \
	int _aa_[_ll1_->size_of_list]{0}; \
	int _xx_ =0; \
	while(1) \
	{ \
		_aa_[_xx_] = _tt_->value; \
 \
		if(_tt_->next != NULL) \
			_tt_ = _tt_->next; \
		else \
		{ \
			_tt_ = NULL; \
			break; \
		} \
		 \
		_xx_++; \
	} \
	_aa_; \
})

#define D_TO_STRING_NODES(_l_) ({})

#define D_REVERSE_LIST(_l_) ({})