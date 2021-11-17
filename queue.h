
class QUEUE {
public:
	LINKED_LIST* queue;

	QUEUE()
	{
		queue = new LINKED_LIST();
	}

	BOOL isEmpty()
	{
		return queue->head == NULL ? TRUE : FALSE;
	}

	int peek()
	{
		if (queue->head == NULL)
			return NULL;

		return queue->head->value;
	}

	enqueue(int value)
	{
		queue->append(new NODE(value));
	}

	int dequeue()
	{
		if (queue->head == NULL)
			return NULL;

		int ret_val = queue->head->value;
		queue->delete_head();
		return ret_val;
	}

	string toString()
	{
		return queue->to_string();
	}
};

#define TO_STRING_QUEUE(_q_) ({ \
	QUEUE *_qq_ = (_q_); \
	string _s_ = _qq_->queue->to_string(); \
	_s_; \
})

#define ENQUEUE_QUEUE(_q_,_v_) ({ \
	QUEUE *_qq_ = (_q_); \
	_qq_->queue->append(new NODE(_v_)); \
})

#define DEQUEUE_QUEUE(_q_) ({ \
	QUEUE *_qq_ = (_q_); \
	int _res_ = 0; \
	if(_qq_->queue->head == NULL) \
		_res_ = NULL; \
	else \
	{ \
		_res_ = _qq_->queue->head->value; \
		_qq_->queue->delete_head(); \
	} \
	_res_; \
})

#define NEW_QUEUE() ({ \
	QUEUE *_qq_ = new QUEUE(); \
	_qq_; \
})

#define IS_EMPTY_QUEUE(_q_) ({ \
	QUEUE *_qq_ = (_q_); \
	BOOL _r_ = _qq_->queue->head == NULL ? TRUE : FALSE; \
	_r_; \
})

#define PEEK_QUEUE(_q_) ({ \
	QUEUE *_qq_ = (_q_); \
	int _res_ = 0; \
	if(_qq_->queue->head == NULL) \
		_res_ = NULL; \
	else \
		_res_ = _qq_->queue->head->value; \
	_res_; \
})