#include "binary_trees.h"
/**
 * min_value_node - Node with the minimum value
 * @node: Root node of the subtree to search
 * Return: Node with the minimum value
 */
bst_t *min_value_node(bst_t *node)
{
	bst_t *current = node;

	while (current && current->left != NULL)
		current = current->left;

	return (current);
}
/**
 * bst_remove - Node from a Binary Search Tree
 * @root: Root node of the tree where you will remove
 * @value: value to remove in the tree
 * Return: Root node of the tree after removing the desired
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			if (root->parent && root->parent->left == root)
				root->parent->left = temp;
			else if (root->parent)
				root->parent->right = temp;
			if (temp)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			if (root->parent && root->parent->left == root)
				root->parent->left = temp;
			else if (root->parent)
				root->parent->right = temp;
			if (temp)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		temp = min_value_node(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}
