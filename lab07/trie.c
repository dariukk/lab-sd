#include "trie.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

trie_node *init_trie()
{
    trie_node *trie = (trie_node *)malloc(sizeof(trie_node));

    trie->is_end_of_word = 0;

    for (int i = 0; i < ALPHABET_SIZE; ++i)
        trie->children[i] = NULL;

    return trie;
}

void insert(trie_node *trie, char *word)
{
    if (strlen(word) == 0)
    {
        trie->is_end_of_word = 1;
        return;
    }

    int next = word[0] - 'a';

    if (!trie->children[next])
        trie->children[next] = init_trie();

    insert(trie->children[next], word + 1);
}

int contains(trie_node *trie, char *word)
{
    if (strlen(word) == 0)
    {
        if (trie == NULL)
            return 0;

        return trie->is_end_of_word;
    }

    if (trie == NULL)
        return 0;

    return contains(trie->children[word[0] - 'a'], word + 1);
}

void destroy_trie(trie_node *trie)
{
    if (trie == NULL)
        return;

    for (int i = 0; i < ALPHABET_SIZE; ++i)
        if (trie->children[i])
            destroy_trie(trie->children[i]);

    free(trie);
}

int main()
{
    trie_node *trie = init_trie();

    insert(trie, "a");
    insert(trie, "abcde");
    insert(trie, "clarinet");

    printf("abc: %d\n", contains(trie, "abc"));           // Should be 1
    printf("abcde: %d\n", contains(trie, "abcde"));       // Should be 1
    printf("abcdef: %d\n", contains(trie, "abcdef"));     // Should be 0
    printf("clarinet: %d\n", contains(trie, "clarinet")); // Should be 1
    printf("clar: %d\n", contains(trie, "clar"));         // Should be 0

    // TODO: Verificati functia destroy_tree folosind valgrind
    destroy_trie(trie);

    return 0;
}
