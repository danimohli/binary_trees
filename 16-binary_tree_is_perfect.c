#include "binary_trees.h"
/**
 * binary_tree_size_rec - counts the number recursively
 * @tree: Root node of the tree
 * @count: variable to store the count
 */
void binary_tree_size_rec(const binary_tree_t *tree, size_t *count)
{
	if (tree == NULL)
		return;

	(*count)++;

	binary_tree_size_rec(tree->left, count);
	binary_tree_size_rec(tree->right, count);
}

/**
 * binary_tree_height - Height of a binary tree
 * @tree: Node of the tree to measure the height
 * Return: Height of the tree, else 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (left_height > right_height ? left_height + 1 : right_height + 1);
}

/**
 * binary_tree_is_perfect - if binary tree is perfect
 * @tree: Root node of the tree to check
 *
 * Return: 1 if tree is perfect, else 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, max_nodes, node_count;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);

	max_nodes = 1 << height;

	max_nodes--;

	/* Count the number of nodes in the tree */
	node_count = 0;
	binary_tree_size_rec(tree, &node_count);

	/* Check if the number of nodes is equal to the maximum possible */
	return (node_count == max_nodes);
}
