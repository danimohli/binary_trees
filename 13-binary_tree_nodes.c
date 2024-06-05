#include "binary_trees.h"
/**
 * binary_tree_nodes - The nodes with at least 1 child in binary tree
 * @tree: Root node of the tree to count number of nodes
 *
 * Return: Number of nodes with at least 1, or 0 if NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}
