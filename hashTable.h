
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

    HASH_TABLE(int size = DEFAULT_HASH_TABLE_SIZE)
    {
        for (int a = 0; a < size; a++)
            buckets.push_back(new LINKED_LIST());

    }

    int hash(string key)
    {
        int a = 0;
        int res = 0;
        for (auto c : key)
        {
            o << a << ": " << int(c) << e;

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

    deleteK() {}

    get() {}

    has() {}

    getKeys() {}

    getValues() {}
};