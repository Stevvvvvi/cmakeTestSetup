
#define MAX_KEY_LEN     128
#define MAX_VALUE_LEN   512

#if 1 
typedef struct kvPair_s
{
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
} kvPair_t;

// link + blockmemory
typedef struct kvStore_s
{
    kvPair_t *table;
} kvStore_t;


#else

#endif



