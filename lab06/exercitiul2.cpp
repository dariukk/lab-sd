#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#include "bst_node.h"
#include "helpers.h"

size_t max(size_t a, size_t b)
{
  if (a < b)
    return b;
  return a;
}

size_t tree_height(bst_node_t *const root)
{
  if (root == NULL)
    return 0;

  return 1 + max(tree_height(root->right), tree_height(root->left));
}

size_t node_height(bst_node_t *const node)
{
  if (node->parent == NULL)
    return 0;

  return 1 + node_height(node->parent);
}
