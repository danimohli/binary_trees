#include "binary_trees.h"
/**
 * binary_tree_depth - Measures the depth of a parent node in binary tree
 * @tree: node to measure the depth
 *
 * Return: Depth of node, or 0 if NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);

	while (tree->parent != NULL)
	{
		depth++;
		tree = tree->parent;
	}
	return (depth);
}
