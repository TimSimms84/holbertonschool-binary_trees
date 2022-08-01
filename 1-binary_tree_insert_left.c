#include "binary_trees.h"


/**
 * binary_tree_insert_left -  inserts left node
 * @parent: pointer to the parent node
 * @value: value for the new node
 * Return: new_node or null if failure
 */


binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	if (!parent)
		return (NULL);

	if (!parent->left)
		parent->left = binary_tree_node(parent, value);

	if (parent->left)
	{
		parent->left->left =  binary_tree_node(parent->left, parent->left->n);
		parent->left->n = value;
	}

	return (parent->left);
}
