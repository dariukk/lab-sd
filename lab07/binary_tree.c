#include "binary_tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_pre_order(bt_node *node)
{
    if (node == NULL)
    {
        return;
    }

    printf("%c", node->value);
    print_pre_order(node->left);
    print_pre_order(node->right);
}

bt_node *create_node(char value)
{
    bt_node *new_node = malloc(sizeof(*new_node));
    new_node->left = new_node->right = NULL;
    new_node->value = value;

    return new_node;
}

int whereisRoot(char *in_order, char value)
{
    int len = strlen(in_order);

    for (int i = 0; i < len; ++i)
        if (value == in_order[i])
            return i;

    return -1;
}

bt_node *build_tree(char *in_order, char *pre_order, int in_start, int in_end, int *pre_idx)
{
    if (in_start > in_end)
        return NULL;

    if (*pre_idx >= strlen(pre_order))
        return NULL;

    bt_node *new_node = create_node(pre_order[*pre_idx]);

    *pre_idx = *pre_idx + 1;

    int pos = whereisRoot(in_order, pre_order[*pre_idx - 1]);

    bt_node *left = build_tree(in_order, pre_order, in_start, pos - 1, pre_idx);
    bt_node *right = build_tree(in_order, pre_order, pos + 1, in_end, pre_idx);

    new_node->left = left;
    new_node->right = right;

    return new_node;
}

int main()
{
    char *pre_order = "abcdefg";
    char *in_order = "cbdafeg";
    int pre_idx = 0;
    bt_node *tree = build_tree(in_order, pre_order, 0, strlen(in_order) - 1, &pre_idx);
    print_pre_order(tree); // Should be abcdefg
}