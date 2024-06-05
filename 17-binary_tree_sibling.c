#include "binary_trees.h"
/**
 * binary_tree_sibling - look 4 sibling nodes
 * @node: node to look 4 the sibling
 *
 * Return: sibling node, or NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left == NULL || node->parent->right == NULL)
		return (NULL);

	if (node == node->parent->left)
		return (node->parent->right);
	else
		return (node->parent->left);
}
