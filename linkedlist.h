class NODE {
public:
	int value;
	NODE* next;
	int print_flag;

	NODE()
	{
		value = 0;
		next = NULL;
		print_flag = 0;

		if (print_flag)
			printNode();
	}

	NODE(int x)
	{
		value = x;
		next = NULL;
		print_flag = 0;

		if (print_flag)
			printNode();
	}

	printNode()
	{
		o << "******** NODE ********" << e;
		o << "VALUE: " << value << e;

		if (next != NULL)
			o << "NEXT: " << next->value << e;
		else
			o << "NEXT: NULL" << e;
	}

	clear()
	{
		value = 0;
		next = NULL;
		print_flag = 0;
	}
};

#define NEW_LINKED_LIST() ({ \
    LINKED_LIST *_ll_ = new LINKED_LIST(); \
    _ll_; \
})

#define NEW_NODE(_x_) ({ \
    NODE *_nn_ = new NODE((_x_));   \
    _nn_; \
})

class LINKED_LIST {
public:
	NODE* head;
	NODE* tail;
	int size_of_list;

	LINKED_LIST()
	{
		printList();
		head = NULL;
		tail = NULL;
		size_of_list = 0;
	}

	printList()
	{
		o << "******** LIST ********" << e;

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
			NODE* temp = head;

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

	prepend(NODE* n)
	{
		if (head != NULL)
		{
			NODE* temp = head;
			head = n;
			head->next = temp;
		}
		else
		{
			head = n;
			tail = n;
		}

		size_of_list++;
	}

	append(NODE* n)
	{
		if (head == NULL)
		{
			head = n;
			tail = n;
		}
		else
		{
			NODE* temp = tail;

			temp->next = n;

			tail = n;
		}

		size_of_list++;
	}

	delete_node(int value, int onlyFirst)
	{
		if (head != NULL)
		{
			if (head->value == value)
				delete_head();
			else if (tail->value == value)
				delete_tail();
			else
			{
				if (onlyFirst == 0)
				{
					NODE* temp1 = head;

					while (1)
					{
						if (temp1->next->value == value)
						{
							temp1->next = temp1->next->next;
							size_of_list--;

							onlyFirst = 1;
							break;
						}

						if (temp1->next != NULL)
							temp1 = temp1->next;
						else
							break;
					}
				}
			}
		}
	}

	NODE* find_node(int value)
	{
		NODE* temp1 = head;

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
			append(NEW_NODE(arr[II]));
	}

	delete_head()
	{
		head = head->next;
		size_of_list--;
	}

	delete_tail()
	{
		NODE* temp1 = head;

		while (1)
		{
			if (temp1->next->next == NULL)
			{
				temp1->next = NULL;
				tail = temp1;

				break;
			}
			else
				temp1 = temp1->next;
		}

		size_of_list--;
	}

	to_array(int arr[])
	{
		NODE* temp1 = head;
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

		NODE* temp1 = head;
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
			prepend(NEW_NODE(seznam[aa]));
	}

	clear()
	{
		head = NULL;
		tail = NULL;
		size_of_list = 0;
	}
};

#define TO_ARRAY_NODES(_l_) ({  \
    LINKED_LIST *_ll_ = (_l_); \
	int _aa_[_ll_->size_of_list] {0}; \
	\
	NODE *_temp1_ = _ll_->head; \
	int _ii_ =0; \
	while(1) \
	{ \
		_aa_[_ii_] = _temp1_->value; \
 \
		if(_temp1_->next != NULL) \
			_temp1_ = _temp1_->next; \
		else \
		{ \
			_temp1_ = NULL; \
			break; \
		} \
		 \
		_ii_++; \
	} \
	_aa_; \
})

#define REVERSE_LIST(_l_) ({ \
    LINKED_LIST *_ll1_ = (_l_); \
	 \
	int _lem1_ = _ll1_->size_of_list; \
	int _aa_[_ll1_->size_of_list] {0}; \
	\
	NODE *_temp1_ = _ll1_->head; \
	int _ii_ =0; \
	while(1) \
	{ \
		_aa_[_ii_] = _temp1_->value; \
 \
		if(_temp1_->next != NULL) \
			_temp1_ = _temp1_->next; \
		else \
		{ \
			_temp1_ = NULL; \
			break; \
		} \
		 \
		_ii_++; \
	} \
	 \
	int _xx_ = 0; \
	 \
	_ll1_->head = NULL; \
	_ll1_->tail = NULL; \
	_ll1_->size_of_list = 0; \
	 \
	while( _xx_ < _lem1_ ) \
	{ \
		NODE* _n_ = NEW_NODE(_aa_[_xx_]); \
		if((*_ll1_).head == NULL) \
		{ \
			(*_ll1_).head = (_n_); \
			(*_ll1_).tail = (_n_); \
		} \
		else \
		{ \
			NODE *_tt_ = (*_ll1_).head; \
			(*_ll1_).head = (_n_); \
			(*_ll1_).head->next = _tt_; \
		} \
		_ll1_->size_of_list++; \
		_xx_++; \
		\
	} \
})

#define CLEAR_LIST(_l_) ({  \
    LINKED_LIST *_ll_ = (_l_); \
	_ll_->head = NULL; \
	_ll_->tail = NULL; \
	_ll_->size_of_list = 0; \
})

#define PREPEND_NODE(_l_,_n_) ({  \
    LINKED_LIST *_ll_ = (_l_); \
    if((*_ll_).head == NULL) \
    { \
        (*_ll_).head = (_n_); \
        (*_ll_).tail = (_n_); \
    } \
    else \
    { \
        NODE *_tt_ = (*_ll_).head; \
        (*_ll_).head = (_n_); \
        (*_ll_).head->next = _tt_; \
    } \
 })

#define APPEND_NODE(_l_,_n_) ({  \
    LINKED_LIST *_lla_ = (_l_); \
    NODE* _nn_ = (_n_); \
    if(_lla_->head == NULL)  \
        {  \
            _lla_->head = _nn_;  \
            _lla_->tail = _nn_;  \
        }  \
        else  \
        {  \
            NODE *_temp_ = _lla_->head;  \
            while(_temp_->next != NULL)  \
            {  \
                _temp_ = _temp_->next; \
            }  \
            _temp_->next = _nn_; \
            _lla_->tail = _temp_->next; \
        }  \
 })

#define DELETE_NODE(_l_,_v_) ({ \
    LINKED_LIST *_ll_ = (_l_); \
    if( (*_ll_).head->value == (_v_) ) \
    { \
         NODE *_tt_= (NODE *)(*_ll_).head->next; \
         (*_ll_).head = _tt_; \
    } \
    else if( (*_ll_).tail->value == (_v_) ) \
    { \
        NODE *_tt_=(*_ll_).head; \
        while(1) \
        { \
            if(((NODE *)_tt_->next)->next == NULL) \
            { \
                _tt_->next = NULL; \
                (*_ll_).tail = _tt_; \
                break; \
            }    \
            else \
                _tt_ = (NODE *)_tt_->next; \
        } \
    } \
    else \
    { \
        NODE *_tt_=(*_ll_).head; \
        while(1) \
        { \
            if( ((NODE *)_tt_->next)->value == (_v_) ) \
            { \
                NODE *_tt2_= (NODE *)_tt_->next; \
                _tt_->next = (NODE *)((NODE *)_tt_->next)->next; \
                 \
                _tt2_->next = NULL; \
                break; \
            } \
            else \
                _tt_ = (NODE *)_tt_->next; \
        } \
    } \
})

#define FIND_NODE(_l_,_v_) ({ \
    LINKED_LIST *_ll_ = (_l_); \
    NODE *_tt_=(*_ll_).head; \
    while(1) \
    { \
        if( _tt_->value == (_v_) ) \
        { \
            break; \
        } \
        else \
            _tt_ = (NODE *)_tt_->next; \
    } \
    _tt_; \
})

#define FROM_ARRAY_NODES(_a_,_len_) ({ \
    LINKED_LIST *_ll1_ = NEW_LINKED_LIST(); \
    int *_arr1_ = (_a_); \
    int _i_ = 0; \
    while(_i_ < _len_) \
    { \
            NODE* _nn1_ = new NODE();   \
            _nn1_->value = *(_arr1_ + _i_); \
            _nn1_->next = NULL; \
            APPEND_NODE(_ll1_,_nn1_); \
            _i_++; \
    } \
    _ll1_; \
})

#define DELETE_HEAD_NODE(_l_) ({ \
    LINKED_LIST *_ll_ = (_l_); \
    NODE *_tt_= (NODE *)(*_ll_).head->next; \
    (*_ll_).head = _tt_; \
})

#define DELETE_TAIL_NODE(_l_) ({ \
    LINKED_LIST *_ll_ = (_l_); \
    NODE *_tt_ = (NODE *)(*_ll_).head; \
    while(1) \
    { \
        if(((NODE *)_tt_->next)->next == NULL) \
        { \
            _tt_->next = NULL; \
            (*_ll_).tail = _tt_; \
            break; \
        }    \
        else \
            _tt_ = (NODE *)_tt_->next; \
    } \
})

#define TO_STRING_NODES(_l_) ({ \
    string _str_ = ""; \
    LINKED_LIST *_ll_ = (_l_); \
    NODE *_tt_ = (NODE *)(*_ll_).head; \
    int _count_ = 0; \
    while(1) \
    { \
        if(_tt_->next == NULL) \
        { \
            if(_count_ > 0) \
                _str_ += ", "; \
            _str_ += std::to_string(_tt_->value); \
            break; \
        } \
        else \
        { \
            if(_count_ > 0) \
                _str_ += ", "; \
            _str_ += std::to_string(_tt_->value); \
            _tt_ = _tt_->next; \
            _count_++; \
        } \
    } \
    _str_; \
})
