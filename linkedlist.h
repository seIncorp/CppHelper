
class NODE {
public:
    int value;
    NODE* next;
};


class LINKED_LIST {
public:
    NODE* head;
    NODE* tail;
};

#define NEW_LINKED_LIST() ({ \
    LINKED_LIST *_ll_ = new LINKED_LIST(); \
    _ll_; \
})

#define NEW_NODE(_x_) ({ \
    NODE *_nn_ = new NODE();   \
    _nn_->value = (_x_); \
    _nn_->next = NULL; \
    _nn_; \
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

#define TO_ARRAY_NODES() ()

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

#define REVERSE_LIST(_l_) ({ \
})