#include "binary_trees.h"
/**
 * enqueue - adds a new node to the end of queue
 * @head: Pointer to the head of queue
 * @node: Pointer to the binary tree node to be added
 * Return: Pointer to the new node or NULL
 */
queue_node_t *enqueue(queue_node_t **head, const binary_tree_t *node)
{
	queue_node_t *new_node = malloc(sizeof(queue_node_t));
	queue_node_t *temp = *head;

	if (!new_node)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;

	if (*head == NULL)
		*head = new_node;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
	return (new_node);
}
/**
 * dequeue - removes the first node from the queue
 * @head: double pointer to the head of the queue
 * Return: pointer to the removed node or NULL
 */
const binary_tree_t *dequeue(queue_node_t **head)
{
	queue_node_t *temp;
	const binary_tree_t *node;

	if (*head == NULL)
		return (NULL);

	temp = *head;
	*head = (*head)->next;
	node = temp->node;
	free(temp);
	return (node);
}

/**
 * binary_tree_levelorder - goes through a binary tree
 * @tree: root node of the tree to traverse
 * @func: funct to call for each node, taking an int
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_node_t *queue = NULL;
	const binary_tree_t *current;

	if (!tree || !func)
		return;

	enqueue(&queue, tree);

	while ((current = dequeue(&queue)) != NULL)
	{
		func(current->n);

		if (current->left)
			enqueue(&queue, current->left);
		if (current->right)
			enqueue(&queue, current->right);
	}
}
