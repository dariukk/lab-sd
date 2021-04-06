#include "helpers.h"
#include "bst_node.h"

void createNode(bst_node_t **root_ptr, double value)
{
  *root_ptr = (bst_node *)malloc(sizeof(bst_node_t));
  (*root_ptr)->value = value;
  (*root_ptr)->left = NULL;
  (*root_ptr)->right = NULL;
}

void insert(bst_node_t **root_ptr, const double value)
{
  if (*root_ptr == NULL)
  {
    createNode(root_ptr, value);
    return;
  }

  if (value <= (*root_ptr)->value && (*root_ptr)->left == NULL)
  {
    createNode(&(*root_ptr)->left, value);
    (*root_ptr)->left->parent = (*root_ptr);

    return;
  }
  
  if (value > (*root_ptr)->value && (*root_ptr)->right == NULL)
  {
    createNode(&(*root_ptr)->right, value);
    (*root_ptr)->right->parent = (*root_ptr);

    return;
  }

  if (value <= (*root_ptr)->value)
    insert(&(*root_ptr)->left, value);
  else
    insert(&(*root_ptr)->right, value);
}

bst_node_t *search(bst_node_t *const root, const double value)
{
  if (root == NULL)
    return NULL;

  if (root->value == value)
    return root;

  if (value < root->value)
    return search(root->left, value);

  return search(root->right, value);
}

bst_node_t *minValue(bst_node *root)
{
  bst_node_t *node = root;

  while (node && node->left)
    node = node->left;

  return node;
}

void remove(bst_node_t **root_ptr, const double value)
{
  if ((*root_ptr) == NULL)
    return;

  if (value < (*root_ptr)->value)
  {
    remove(&(*root_ptr)->left, value);
    return;
  }

  if (value > (*root_ptr)->value)
  {
    remove(&(*root_ptr)->right, value);
    return;
  }

  if ((*root_ptr)->left == NULL)
  {
    // nu are fiu stang
    struct bst_node *node = (*root_ptr)->right;
    free(*root_ptr);
    *root_ptr = node;

    return;
  }

  if ((*root_ptr)->right == NULL)
  {
    // nu are fiu drept
    struct bst_node *node = (*root_ptr)->left;
    free(*root_ptr);
    *root_ptr = node;

    return;
  }

  // nod cu doi fii

  struct bst_node *node = minValue((*root_ptr)->right);
  (*root_ptr)->value = node->value;

  remove(&(*root_ptr)->right, node->value);
}
