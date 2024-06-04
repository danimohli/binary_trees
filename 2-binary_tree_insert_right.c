#include "binary_trees.h"
/**
 * binary_tree_insert_right - Inserts node as right-child of another node
 * @parent: Parent node to insert the right-child
 * @value: Value to store in the new node
 *
 * Return: Created node / NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	new_node->right = parent->right;
	if (new_node->right != NULL)
		new_node->right->parent = new_node;

	parent->right = new_node;

	return (new_node);
}
