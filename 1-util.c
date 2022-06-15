#include "monty.h"
/**
 * push - add elemnt to top of stack
 * @head: stack top
 * @data: value
 * @linum: line number
 */
void push(stack_t **head, int data, unsigned int __attribute__((unused))linum)
{
	stack_t *newNode;

	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		if (line)
			free(line);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	newNode->next = (*head);
	newNode->prev = NULL;
	newNode->n = data;
	if (*head)
		(*head)->prev = newNode;
	(*head) = newNode;
}
/**
 * add_end - add data to bottom of stack
 * @head: stack top
 * @data: value
 * @linum: line number
 */
void add_end(stack_t **head, int data, unsigned int linum)
{
	stack_t *newNode, *cur;

	cur = *head;
	if (!cur)
	{
		push(head, data, linum);
	}
	else
	{
		newNode = malloc(sizeof(stack_t));
		if (!newNode)
		{
			fprintf(stderr, "Error: malloc failed\n");
			if (line)
				free(line);
			free_stack(head);
			exit(EXIT_FAILURE);
		}
		
		newNode->next = NULL;
		newNode->n = data;
		while (cur->next)
			cur = cur->next;
		cur->next = newNode;
		newNode->prev = cur;
	}
}
/**
 * pop - remove data from top of stack
 * @head: stack top
 * @linum: line number
 */
void pop(stack_t **head, unsigned int linum)
{
	stack_t *del;

	if ((!head) || !(*head))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", linum);
		if (line)
			free(line);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	del = *head;
	*head = (*head)->next;
	if (*head)
		(*head)->prev = NULL;
	free(del);
}
/**
 * swap - swap most top 2 data
 * @head: stack top
 * @linum: line number
 */
void swap(stack_t **head, unsigned int linum)
{
	int tmp;

	if (!(*head) || !((*head)->next))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", linum);
		if (line)
			free(line);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->n;
	(*head)->n = ((*head)->next)->n;
	((*head)->next)->n = tmp;
}
/**
 * add - add top 2 data
 * @head: stack top
 * @linum: line number
 */
void add(stack_t **head, unsigned int linum)
{
	if (!(*head) || !((*head)->next))
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", linum);
		if (line)
			free(line);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	((*head)->next)->n += (*head)->n;
	pop(head, linum);
}
