#include "binary_trees.h"
/**
 * enqueue - node to the end of queue
 * @head: Pointer to the head of queue
 * @node: binary tree node to be added to queue
 * Return: new node or NULL
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
 * dequeue - removes first node from queue
 * @head: pointer to the head of queue
 * Return: removed node
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
 * free_queue - frees nodes in queue
 * @head: point to the head of queue
 */
void free_queue(queue_node_t **head)
{
	queue_node_t *temp;

	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

/**
 * binary_tree_is_complete - checks if binary tree is complete
 * @tree: root node of the tree to check
 * Return: 1 if tree is complete, else 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue_node_t *queue = NULL;
	const binary_tree_t *current;
	int flag = 0;

	if (!tree)
		return (0);
	enqueue(&queue, tree);
	while ((current = dequeue(&queue)) != NULL)
	{
		if (current->left)
		{
			if (flag)
			{
				free_queue(&queue);
				return (0);
			}
			enqueue(&queue, current->left);
		}
		else
			flag = 1;

		if (current->right)
		{
			if (flag)
			{
				free_queue(&queue);
				return (0);
			}
			enqueue(&queue, current->right);
		}
		else
			flag = 1;
	}
	free_queue(&queue);
	return (1);
}
