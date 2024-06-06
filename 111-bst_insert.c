#include "binary_trees.h"
/**
 * bst_insert - inserts a value in a Binary Tree
 * @tree: root node of the BST to insert the value
 * @value: value to store
 * Return: created node, or NUL
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current, *new_node;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	current = *tree;
	while (current != NULL)
	{
		if (value == current->n)
			return (NULL);
		if (value < current->n)
		{
			if (current->left == NULL)
			{
				new_node = binary_tree_node(current, value);
				if (new_node == NULL)
					return (NULL);
				current->left = new_node;
				return (new_node);
			}
			current = current->left;
		}
		else
		{
			if (current->right == NULL)
			{
				new_node = binary_tree_node(current, value);
				if (new_node == NULL)
					return (NULL);
				current->right = new_node;
				return (new_node);
			}
			current = current->right;
		}
	}
	return (NULL);
}
