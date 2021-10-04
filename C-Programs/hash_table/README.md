# Hash Table

It's written in C and only expose basic API functions. It's not feature complete but for basic prgram you can use it.

# Building

Place `hash_table.c` and `hash_table.h` file in your project and compile it.
If you want to compile it from your terminal install `clang` and `make` then run `./build.sh`. It will build the binary on `bin` directory.

Also please note that the table will not grow by itself once after table is created. So for that you need to pass the fixed table size as your need.

# Usage

You can also inspect the `src/main.c` file for full usage.

```c
#include "hash_table.h"
#include <stdio.h>

int main(void)
{
    size_t MAX_TABLE_SIZE = 100;

    HashTable *contact_list = new_hashtable(MAX_TABLE_SIZE);

    // insert
    hashtable_insert(contact_list, "prajwal", "981500");
    hashtable_insert(contact_list, "ram", "99887766");

    // search
    printf("prajwal num: %s\n", hashtable_search(contact_list, "prajwal"));
    printf("ram num: %s\n", hashtable_search(contact_list, "ram"));

    // update the value
    hashtable_insert(contact_list, "prajwal", "9815009744");

    // delete the value and key
    hashtable_delete(contact_list, "ram");

    // delete table
    delete_table(contact_list);
}
```

# API

```c
HashTable *new_hashtable(size_t table_size);

void hashtable_insert(HashTable *table, const char *key, const char *value);
char *hashtable_search(HashTable *table, const char *key);
void hashtable_delete(HashTable *table, const char *key);
void debug_table(HashTable *table);

void delete_table(HashTable *table);
```
