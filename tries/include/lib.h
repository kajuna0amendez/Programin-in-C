#ifndef LIB_H
#define LIB_H
#include <stdbool.h>

typedef trie_node init_trie_node;

typedef struct{
    char *token;
    trie_node *array;
} trie_node;

int* init_trie_node();

void insert(char *token, trie_node *tree);

char* search(trie_node *tree);

void delete(char *token);

#endif