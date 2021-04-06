#include "helpers.h"
#include "bst_node.h"

void traverse_in_order(bst_node_t *const root, func_t func)
{
    if (root == NULL)
        return;

    if (root->left)
        traverse_in_order(root->left, func);

    func(root);

    if (root->right)
        traverse_in_order(root->right, func);
}

void traverse_pre_order(bst_node_t *const root, func_t func)
{
    if (root == NULL)
        return;

    func(root);

    if (root->left)
        traverse_pre_order(root->left, func);

    if (root->right)
        traverse_pre_order(root->right, func);
}

void traverse_post_order(bst_node_t *const root, func_t func)
{
    if (root == NULL)
        return;

    if (root->left)
        traverse_post_order(root->left, func);

    if (root->right)
        traverse_post_order(root->right, func);

    func(root);
}
