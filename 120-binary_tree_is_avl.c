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
 * is_avl_rec - Recursively checks if a binary tree is a valid
 * @tree: Root node of the tree to check
 * @height: Ptr to store the height of tree
 * Return: 1 or 0
 */
int is_avl_rec(const binary_tree_t *tree, int *height)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
	{
		*height = 0;
		return (1);
	}

	if (!is_avl_rec(tree->left, &left_height) ||
			!is_avl_rec(tree->right, &right_height))
		return (0);

	*height = 1 + max(left_height, right_height);

	if (abs(left_height - right_height) > 1)
		return (0);

	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Root node of the tree to check
 * Return: 1 if tree is a valid, or 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;

	if (tree == NULL)
		return (0);

	if (!is_bst(tree, NULL, NULL))
		return (0);

	return (is_avl_rec(tree, &height));
}
