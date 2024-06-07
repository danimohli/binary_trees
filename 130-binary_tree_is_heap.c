#include "binary_trees.h"
/**
 * count_nodes - number of nodes in a binary tree
 * @tree: root node of the tree to count
 * Return: Number of nodes
 */
int count_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * is_complete - binary tree is complete
 * @tree: root node of the tree to check
 * @index: current node in the complete tree
 * @node_count: number of nodes in the tree
 * Return: 1 or 0
 */
int is_complete(const binary_tree_t *tree, int index, int node_count)
{
	if (!tree)
		return (1);

	if (index >= node_count)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, node_count) &&
			is_complete(tree->right, 2 * index + 2, node_count));
}

/**
 * is_max_heap - binary tree satisfies the max heap property
 * @tree: the root node of the tree to check
 * Return: 1 or 0
 */
int is_max_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (tree->left && tree->n < tree->left->n)
		return (0);
	if (tree->right && tree->n < tree->right->n)
		return (0);
	return (is_max_heap(tree->left) && is_max_heap(tree->right));
}

/**
 * binary_tree_is_heap - valid Max Binary Heap
 * @tree: root node of the tree to check
 * Return: 1 or 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int node_count;

	if (!tree)
		return (0);

	node_count = count_nodes(tree);
	if (is_complete(tree, 0, node_count) && is_max_heap(tree))
		return (1);
	return (0);
}
