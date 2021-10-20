#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "hash_table.h"

#define PRIME_1 137
#define PRIME_2 139

static TableItem DELETED_ITEM = {NULL, NULL};

static TableItem *create_new_item(const char *key, const char *value)
{
    TableItem *item = malloc(sizeof(TableItem));
    item->key = strdup(key);
    item->value = strdup(value);

    return item;
}

static void delete_item(TableItem *item)
{
    free(item->key);
    free(item->value);
    free(item);
}

static int hash(const char *key,
                const int primary_num,
                const int table_size)
{
    //const int primary_num = 'a';
    long hash = 0;
    const int key_length = strlen(key);

    for (int index = 0; index < key_length; index++) {
        hash += (long)pow(primary_num, key_length - (index + 1)) * key[index];
        hash = hash % table_size;
    }

    return (int)hash;
}

static int hash2(const char *key, const int table_size)
{
    unsigned long hash = 5381;
    int c = 0;

    while ((c = *key++))
        hash = ((hash << 5) + hash) + c;

    return hash % table_size;
}

static int hash_function(const char *key, const int table_size, const int offset)
{
    const int hash_a = hash(key, PRIME_1, table_size);
    const int hash_b = hash(key, PRIME_2, table_size);

    return (hash_b + (offset * (hash_a + 1))) % table_size;
}

HashTable *new_hashtable(size_t size)
{
    HashTable *new_table = malloc(sizeof(HashTable));

    new_table->size = size;
    new_table->count = 0;
    new_table->items = calloc(new_table->size, sizeof(TableItem *));

    return new_table;
}

void delete_table(HashTable *table)
{
    for (size_t index = 0; index < table->size; index++) {
        TableItem *item = table->items[index];
        if (item != NULL && item != &DELETED_ITEM) {
            delete_item(item);
        }
    }

    free(table->items);
    free(table);
}

void hashtable_insert(HashTable *table, const char *key, const char *value)
{
    float load_factor = (float)table->count / (float)table->size;

    if (load_factor ==  0.7f) {
        printf("Table filled up with 70%% \n");
        //return;
    }

    TableItem *new_item = create_new_item(key, value);
    int index = hash_function(key, table->size, 0);
    TableItem *current_item = table->items[index];

    int offset = 1;
    while ( (current_item != NULL) && (current_item != &DELETED_ITEM) ) {
        if (strcmp(current_item->key, key) == 0) {
            delete_item(current_item);
            table->items[index] = new_item;
            return;
        }

        index = hash_function(key, table->size, offset);
        current_item = table->items[index];
        offset++;
    }

    table->items[index] = new_item;
    table->count++;
}

char *hashtable_search(HashTable *table, const char *key)
{
    int index = hash_function(key, table->size, 0);
    TableItem *item = table->items[index];

    int offset = 1;
    while (item != NULL) {
        if (item != &DELETED_ITEM) {
            if (strcmp(item->key, key) == 0) {
                return item->value;
            }
        }

        index = hash_function(key, table->size, offset);
        item = table->items[index];
        offset++;
    }

    return NULL;
}

void hashtable_delete(HashTable *table, const char *key)
{
    int index = hash_function(key, table->size, 0);
    TableItem *found_item = table->items[index];

    int offset = 1;
    while (found_item != NULL) {
        if (found_item != &DELETED_ITEM) {
            if (strcmp(found_item->key, key) == 0) {
                delete_item(found_item);
                table->items[index] = &DELETED_ITEM;
                table->count--;
            }
        }

        index = hash_function(key, table->size, offset);
        found_item = table->items[index];
        offset++;
    }

    return;
}

void debug_table(HashTable *table)
{
    for (size_t i = 0; i < table->size; i++) {
        TableItem *item = table->items[i];

        if (item != NULL) {
            printf("%i. (%p) %s --> %s\n", i, item, item->key, item->value);
        } else {
            printf("%i. x\n", i);
        }
    }
}
