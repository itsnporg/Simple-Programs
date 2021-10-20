#include <stdio.h>
#include "hash_table.h"

#define MAX_TABLE_SIZE 20

int main(int argc, char **argv)
{
    // create hash table
    HashTable *new_table = new_hashtable(MAX_TABLE_SIZE);
    
    hashtable_insert(new_table, "one", "one_value");
    hashtable_insert(new_table, "two", "two_value");
    hashtable_insert(new_table, "three", "three_value");
    hashtable_insert(new_table, "four", "four_value");
    hashtable_insert(new_table, "five", "five_value");
    hashtable_insert(new_table, "six", "six value");
    
    debug_table(new_table);
    hashtable_delete(new_table, "two");

    printf("\nafter updated.........\n");

    debug_table(new_table);
    hashtable_insert(new_table, "two", "two_value");
    debug_table(new_table);

    // search hash table
    printf("one value: %s", hashtable_search(new_table, "one"));

    delete_table(new_table);
}
