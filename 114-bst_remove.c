#include "binary_trees.h"

/**
 * bst_min - finds the smallest node from a bst
 * @root: a pointer to the root node of the tree
 * Return: a pointer to the smallest node
 */
bst_t *bst_min(bst_t *root)
{
	bst_t *tmp = root;

	while (tmp->left)
		tmp = tmp->left;

	return (tmp);
}
/**
 * bst_remove - removes a node from a bst
 * @root: a pointer to the root node of the tree where you will remove a node
 * @value: the value to remove in the tree
 * Return: a pointer to the new root node or NULL
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp = NULL;

	if (!root)
		return (NULL);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	if (value > root->n)
		root->right = bst_remove(root->right, value);
	if (!root->left)
	{
		tmp = root->right;
		free(root);
		return (tmp);
	}
	if (!root->right)
	{
		tmp = root->left;
		free(root);
		return (tmp);
	}
	tmp = bst_min(root->right);
	root->n = tmp->n;
	root->right = bst_remove(root->right, tmp->n);
	return (root);
}
