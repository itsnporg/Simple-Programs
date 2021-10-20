#pragma once

typedef struct {
    char *key;
    char *value;
} TableItem;

typedef struct {
    unsigned int size;
    unsigned int count;
    TableItem **items;
} HashTable;

HashTable *new_hashtable(size_t table_size);

void hashtable_insert(HashTable *table, const char *key, const char *value);
char *hashtable_search(HashTable *table, const char *key);
void hashtable_delete(HashTable *table, const char *key);
void debug_table(HashTable *table);

void delete_table(HashTable *table);
