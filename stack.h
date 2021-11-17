
class STACK
{
public:
	LINKED_LIST* stack;

	STACK()
	{
		stack = new LINKED_LIST();
	}

	BOOL isEmpty()
	{
		return stack->head == NULL ? TRUE : FALSE;
	}

	int peek()
	{
		if (isEmpty() == 1)
			return NULL;

		return stack->head->value;
	}

	push(int value)
	{
		stack->prepend(new NODE(value));
	}

	int pop()
	{
		if (stack->head == NULL)
			return NULL;

		int res = stack->head->value;
		stack->delete_head();
		return res;
	}

	toArray(int arr[])
	{
		stack->to_array(arr);
	}

	string toString()
	{
		return stack->to_string();
	}
};

#define NEW_STACK() ({ \
	STACK *_s_ = new STACK(); \
	_s_; \
})

#define IS_EMPTY_STACK(_s_) ({ \
	STACK *_qq_ = (_s_); \
	BOOL _r_ = _qq_->stack->head == NULL ? TRUE : FALSE; \
	_r_; \
})

#define PEEK_STACK(_s_) ({ \
	STACK *_qq_ = (_s_); \
	int _res_ = 0; \
	if(_qq_->stack->head == NULL) \
		_res_ = NULL; \
	else \
		_res_ = _qq_->stack->head->value; \
	_res_; \
})

#define PUSH_STACK(_s_,_v_) ({ \
	STACK *_qq_ = (_s_); \
	_qq_->stack->prepend(new NODE(_v_)); \
})

#define POP_STACK(_s_) ({ \
	STACK *_qq_ = (_s_); \
	int _r_ = 0; \
	if(_qq_->stack->head == NULL) \
		_r_ = NULL; \
	 \
	_r_ = _qq_->stack->head->value; \
	_qq_->stack->delete_head(); \
	_r_; \
})

#define TO_ARRAY_STACK(_s_) ({ \
	STACK *_qq_ = (_s_); \
	int _a_[_qq_->stack->size_of_list] {0}; \
	_qq_->stack->to_array(_a_); \
	_a_; \
})

#define TO_STRING_STACK(_s_) ({ \
	STACK *_qq_ = (_s_); \
	string _s_ = _qq_->stack->to_string(); \
	_s_; \
})
