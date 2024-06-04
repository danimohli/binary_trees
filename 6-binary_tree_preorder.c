#include "binary_trees.h"
/**
 * binary_tree_preorder - Goes thru a binary tree usin pre-order traversal
 * @tree: D rut node of tree to traverse
 * @func: Func to cal 4 each node
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
