#include "binary_trees.h"
/**
 * bst_search - searches a value in a Binary Search Tree
 * @tree: Root node of the BST to search
 * @value: value to search
 * Return: node containing the value, or NUl
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (tree->n == value)
		return ((bst_t *)tree);

	if (value < tree->n)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));
}
