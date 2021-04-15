#ifndef _TRIE_H
#define _TRIE_H

#define ALPHABET_SIZE 26

typedef struct trie_node {
    int is_end_of_word;
    struct trie_node * children [ALPHABET_SIZE];
} trie_node;

// Initializeaza structura de trie.  (1 punct)
trie_node* init_trie();

// Insereaza un nou cuvant. (3 puncte)
void insert(trie_node *trie, char *word);

// Verifica daca un cuvant a fost deja inserat in trie. (1 punct)
int contains(trie_node *trie, char *word);

// Sterge si dezaloca intregul trie. (1 punct)
void destroy_trie(trie_node *trie);

#endif