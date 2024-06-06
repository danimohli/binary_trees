#include "binary_trees.h"
/**
 * max - Finds D max of #2 ints
 * @a: First int
 * @b: Second int
 * Return: The max
 */
int max(int a, int b)
{
	return (a > b ? a : b);
}

/**
 * height - Measures height of binary tree
 * @tree: Root node of the tree to measure
 * Return: Height of the tree, or 0
 */
int height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + max(height(tree->left), height(tree->right)));
}

/**
 * is_bst - Checks if a binary tree is a valid BST
 * @tree: Root node of the tree to check
 * @min: node with D min val allowed
 * @max: node with D max val allowed
 * Return: 1 if the tree is a valid, or 0
 */
int is_bst(const binary_tree_t *tree, const binary_tree_t *min,
		const binary_tree_t *max)
{
	if (tree == NULL)
		return (1);

	if ((min && tree->n <= min->n) || (max && tree->n >= max->n))
		return (0);

	return (is_bst(tree->left, min, tree) && is_bst(tree->right, tree, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Root node of the tree to check
 * Return: 1 if tree is a valid, or 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	if (!is_bst(tree, NULL, NULL))
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);

	if (abs(left_height - right_height) > 1)
		return (0);

	return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}
