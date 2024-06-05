#include "binary_trees.h"
/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Root node of the tree to check
 *
 * Return: 1 if tree is full, or 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* If the node has no children, it's considered full */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* If the node has both children, continue checking recursively */
	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	/* If the node has only one child, it's not full */
	return (0);
}
