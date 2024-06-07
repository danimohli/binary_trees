#include "binary_trees.h"
/**
 * max - Returns the max of 2 int
 * @a: first int
 * @b:  second int
 *
 * Return: D max of 2 int
 */
int max(int a, int b)
{
	return (a > b ? a : b);
}

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
int height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + max(height(tree->left), height(tree->right)));
}

/**
 * balance_factor - Calculates the balance factor of a node
 * @node: Pointer to the node
 *
 * Return: Balance factor of the node
 */
int balance_factor(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	return (height(node->left) - height(node->right));
}

/**
 * rotate_left - Performs a left-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree once rotated
 */
avl_t *rotate_left(avl_t *tree)
{
	avl_t *new_root = tree->right;

	tree->right = new_root->left;
	if (new_root->left)
		new_root->left->parent = tree;

	new_root->left = tree;
	new_root->parent = tree->parent;
	tree->parent = new_root;

	return (new_root);
}

/**
 * rotate_right - Performs a right-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree once rotated
 */
avl_t *rotate_right(avl_t *tree)
{
	avl_t *new_root = tree->left;

	tree->left = new_root->right;
	if (new_root->right)
		new_root->right->parent = tree;

	new_root->right = tree;
	new_root->parent = tree->parent;
	tree->parent = new_root;

	return (new_root);
}

/**
 * rebalance - Rebalances an AVL tree
 * @node: Pointer to the node to rebalance from
 *
 * Return: Pointer to the new root node after rebalancing
 */
avl_t *rebalance(avl_t *node)
{
	int balance;

	balance = balance_factor(node);

	if (balance > 1)
	{
		if (balance_factor(node->left) < 0)
			node->left = rotate_left(node->left);
		return (rotate_right(node));
	}
	else if (balance < -1)
	{
		if (balance_factor(node->right) > 0)
			node->right = rotate_right(node->right);
		return (rotate_left(node));
	}
	return (node);
}

/**
 * bst_insert - Inserts a value in a Binary Search Tree (BST)
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: Value to insert in the new node
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *bst_insert(avl_t **tree, int value)
{
	avl_t *node;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	node = *tree;
	if (value < node->n)
	{
		if (node->left == NULL)
		{
			node->left = binary_tree_node(node, value);
			return (node->left);
		}
		else
			return (bst_insert(&(node->left), value));
	}
	else if (value > node->n)
	{
		if (node->right == NULL)
		{
			node->right = binary_tree_node(node, value);
			return (node->right);
		}
		else
			return (bst_insert(&(node->right), value));
	}
	return (NULL);
}

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree to insert the value
 * @value: Value to insert in the new node
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node, *root;

	if (tree == NULL)
		return (NULL);
	node = bst_insert(tree, value);
	if (node == NULL)
		return (NULL);

	root = node;
	while (root->parent != NULL)
	{
		root = root->parent;
		root = rebalance(root);
	}
	*tree = root;
	return (node);
}
