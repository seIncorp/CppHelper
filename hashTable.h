
#define DEFAULT_HASH_TABLE_SIZE 32

typedef struct {
    string key;
    int keyHash;
} KEYS;

class HASH_TABLE
{
public:

    std::vector<LINKED_LIST*> buckets;
    std::vector<KEYS> keys;

    int all_size;

    HASH_TABLE(int size = DEFAULT_HASH_TABLE_SIZE)
    {
        all_size = 0;

        for (int a = 0; a < size; a++)
            buckets.push_back(new LINKED_LIST());
    }

    int hash(string key)
    {
        int a = 0;
        int res = 0;
        for (auto c : key)
        {
            //            o << c ;
            res += a + int(c);
            a++;
        }

        return res % buckets.size();
    }

    set(string key, int value)
    {
        int keyHash = hash(key);
        keys.push_back({ key,keyHash });
        LINKED_LIST* bucketLinkedList = buckets[keyHash];

        // check if this key exists
        bool checks = FALSE;
        NODE* temp;
        if (bucketLinkedList->size_of_list > 0)
        {
            temp = bucketLinkedList->head;
            while (1)
            {
                if (key == temp->key)
                {
                    checks = TRUE;
                    break;
                }

                if (temp->next == NULL)
                {
                    break;
                }
                else
                    temp = temp->next;
            }
        }

        if (!checks)
        {
            bucketLinkedList->append(new NODE(value, key));
        }
        else
        {
            temp->value = value;
        }
    }

    int deleteK(string key)
    {
        int keyHash = hash(key);

        for (int a = 0; a < keys.size(); a++)
        {
            if (keys[a].key == key)
            {
                keys.erase(keys.begin() + a);
            }
        }

        LINKED_LIST* bucketLinkedList = buckets[keyHash];

        // check if this key exists
        bool checks = FALSE;
        NODE* temp;
        int temp_value = 0;
        int index_list = 0;
        if (bucketLinkedList->size_of_list > 0)
        {
            temp = bucketLinkedList->head;
            while (1)
            {
                if (key == temp->key)
                {
                    checks = TRUE;
                    temp_value = temp->value;
                    break;
                }

                if (temp->next == NULL)
                {
                    break;
                }
                else
                    temp = temp->next;

                index_list++;
            }
        }

        if (checks)
        {
            return bucketLinkedList->delete_node_v2(temp_value, 0);
        }

        return NULL;
    }

    int get(string key)
    {
        LINKED_LIST* bucketLinkedList = buckets[hash(key)];

        NODE* temp;
        int temp_value = 0;
        int index_list = 0;
        if (bucketLinkedList->size_of_list > 0)
        {
            temp = bucketLinkedList->head;
            while (1)
            {
                if (key == temp->key)
                {
                    temp_value = temp->value;
                    break;
                }

                if (temp->next == NULL)
                {
                    break;
                }
                else
                    temp = temp->next;

                index_list++;
            }
        }

        return temp_value;
    }

    bool has(string key)
    {
        bool res = FALSE;

        for (int a = 0; a < keys.size(); a++)
        {
            if (keys[a].key == key)
                res = TRUE;
        }

        return res;
    }

    std::vector<KEYS> getKeys()
    {

        return keys;
    }

    int* getValues()
    {
        all_size = 0;
        for (int a = 0; a < buckets.size(); a++)
            if (buckets[a]->size_of_list > 0)
                all_size += buckets[a]->size_of_list;

        int* values = new int[all_size];

        int count = 0;
        for (int a = 0; a < buckets.size(); a++)
        {
            if (buckets[a]->size_of_list > 0)
            {
                NODE* temp = buckets[a]->head;
                while (1)
                {
                    //o << T << "Value: " << temp->value << " --> Key: " << temp->key << e;
                    values[count] = temp->value;
                    count++;

                    if (temp->next == NULL)
                        break;
                    else
                        temp = temp->next;
                }
            }
        }

        return values;
    }

    printKeys()
    {
        o << "************************ KEYS list ************************" << e;
        for (int a = 0; a < keys.size(); a++)
        {
            o << "Key: " << keys[a].key << " --> keyHash: " << keys[a].keyHash << e;
        }
        o << "************************************************************" << e;
    }

    printBuckets()
    {
        o << "************************ KEYS list ************************" << e;
        for (int a = 0; a < buckets.size(); a++)
        {
            o << a << ". list:" << e;
            if (buckets[a]->size_of_list > 0)
            {
                NODE* temp = buckets[a]->head;
                while (1)
                {
                    o << T << "Value: " << temp->value << " --> Key: " << temp->key << e;

                    if (temp->next == NULL)
                        break;
                    else
                        temp = temp->next;
                }
            }
            else
            {
                o << T << "EMPTY" << e;
            }
        }
        o << "************************************************************" << e;
    }
};

// TODO: also in macro

#define NEW_HASH_TABLE() ({ \
    HASH_TABLE *_hh_ = new HASH_TABLE(); \
    _hh_; \
})

#define HASH_OF_HASH_TABLE(_ht_,_key_) ({ \
    HASH_TABLE *_hh_ = (_ht_); \
    string _ss_ = (_key_); \
    int _a_ = 0; \
    int _res_ = 0; \
    for(auto _c_: _ss_) \
    { \
       o << _c_ ; \
        _res_ += _a_ + int(_c_); \
        _a_++; \
    } \
     \
    int _r_ = _res_ % _hh_->buckets.size(); \
    _r_; \
})

#define PRINT_KEYS_HASH_TABLE(_ht_) ({ \
    HASH_TABLE *_hh_ = (_ht_); \
    o << "************************ KEYS list ************************"; \
    ee; \
    for(int a = 0; a < _hh_->keys.size(); a++ ) \
    { \
        o << "Key: " << _hh_->keys[a].key << " --> keyHash: " << _hh_->keys[a].keyHash << e; \
    } \
})

#define SET_HASH_TABLE(_ht_,_k_,_v_) ({ \
    HASH_TABLE *_hh_ = (_ht_); \
    string _ss_ = (_k_); \
    int _a_ = 0; \
    int _res_ = 0; \
    for(auto _c_: _ss_) \
    { \
        _res_ += _a_ + int(_c_); \
        _a_++; \
    } \
     \
    int keyHash = _res_ % _hh_->buckets.size(); \
    _hh_->keys.push_back({_ss_,keyHash}); \
    LINKED_LIST *bucketLinkedList = _hh_->buckets[keyHash]; \
         \
        bool checks = FALSE; \
        NODE *temp; \
        if(bucketLinkedList->size_of_list > 0) \
        { \
            temp = bucketLinkedList->head; \
            while(1) \
            { \
                if(_k_ == temp->key) \
                { \
                    checks = TRUE; \
                    break; \
                } \
 \
                if(temp->next == NULL) \
                { \
                    break; \
                } \
                else \
                    temp = temp->next; \
            } \
        }  \
         \
        if(!checks) \
        { \
            bucketLinkedList->append(new NODE(_v_,_k_)); \
        } \
        else \
        { \
            temp->value = _v_; \
        } \
})

#define PRINT_BUCKETS_HASH_TABLE(_ht_) ({ \
    HASH_TABLE *_hh_ = (_ht_); \
    o << "************************ KEYS list ************************" << e; \
    for(int a = 0; a < _hh_->buckets.size(); a++ ) \
    { \
        o << a << ". list:" << e; \
        if( _hh_->buckets[a]->size_of_list > 0  ) \
        { \
            NODE *temp = _hh_->buckets[a]->head; \
            while(1) \
            { \
                o << T << "Value: " << temp->value << " --> Key: " << temp->key << e; \
                 \
                if(temp->next == NULL) \
                    break; \
                else \
                    temp = temp->next; \
            } \
        } \
        else \
        { \
            o << T << "EMPTY" << e; \
        } \
    } \
})

#define DELETE_PART_HASH_TABLE(_ht_,_k_) ({ \
    HASH_TABLE *_hh_ = (_ht_); \
    int keyHash = _hh_->hash(_k_); \
    for(int a = 0; a < _hh_->keys.size(); a++ ) \
    { \
        if(_hh_->keys[a].key == _k_) \
        { \
            _hh_->keys.erase(_hh_->keys.begin()+a); \
        } \
    } \
    LINKED_LIST *bucketLinkedList = _hh_->buckets[keyHash]; \
    bool checks = FALSE; \
    NODE *temp; \
    int temp_value = 0; \
    int index_list = 0; \
    int ret = 0; \
    if(bucketLinkedList->size_of_list > 0) \
    { \
        temp = bucketLinkedList->head; \
        while(1) \
        { \
            if(_k_ == temp->key) \
            { \
                checks = TRUE; \
                temp_value = temp->value; \
                break; \
            } \
            if(temp->next == NULL) \
            { \
                break; \
            } \
            else \
                temp = temp->next; \
                 \
            index_list++; \
        } \
    } \
    if(checks) \
    { \
        ret = bucketLinkedList->delete_node_v2(temp_value,0); \
    } \
    else \
        ret = NULL; \
    ret; \
})

#define GET_HASH_TABLE(_ht_,_k_) ({ \
    HASH_TABLE *_hh_ = (_ht_); \
		LINKED_LIST *bucketLinkedList = _hh_->buckets[_hh_->hash(_k_)]; \
		NODE *temp; \
		int temp_value = 0; \
        int index_list = 0; \
        if(bucketLinkedList->size_of_list > 0) \
        { \
            temp = bucketLinkedList->head; \
            while(1) \
            { \
                if(_k_ == temp->key) \
                { \
                    temp_value = temp->value; \
                    break; \
                } \
 \
                if(temp->next == NULL) \
                { \
                    break; \
                } \
                else \
                    temp = temp->next; \
                     \
                index_list++; \
            } \
        } \
		 \
		temp_value; \
})

#define GET_VALUES_HASH_TABLE() ({})
#define GET_KEYS_HASH_TABLE() ({})
#define HAS_HASH_TABLE() ({})






















