#include "monty.h"
/**
 * sub - subtract top of stack from second top
 * @head: stack top
 * @linum: line number
 */
void sub(stack_t **head, unsigned int linum)
{
	if (!(*head) || !((*head)->next))
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", linum);
		if (line)
			free(line);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	((*head)->next)->n -= (*head)->n;
	pop(head, linum);
}
/**
 * mul - multiply top 2 stack value
 * @head: stack top
 * @linum: line number
 */
void mul(stack_t **head, unsigned int linum)
{
	if (!(*head) || !((*head)->next))
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", linum);
		if (line)
			free(line);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	((*head)->next)->n *= (*head)->n;
	pop(head, linum);
}
/**
 * mod - divide and get reminder stack top from stack second top
 * @head: stack top
 * @linum: line number
 */
void mod(stack_t **head, unsigned int linum)
{
	if (!(*head) || !((*head)->next))
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", linum);
		if (line)
			free(line);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	if (((*head)->n) == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", linum);
		if (line)
			free(line);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	((*head)->next)->n %= (*head)->n;
	pop(head, linum);
}
/**
 * _div - divide stack second top by stack top
 * @head: stack top
 * @linum: line number
 */
void _div(stack_t **head, unsigned int linum)
{
	if (!(*head) || !((*head)->next))
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", linum);
		if (line)
			free(line);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	if (((*head)->n) == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", linum);
		if (line)
			free(line);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	((*head)->next)->n /= (*head)->n;
	pop(head, linum);
}
/**
 * pint - get top of stack value
 * @head: stack top
 * @linum: line number
 */
void pint(stack_t **head, unsigned int linum)
{
	if (!(*head))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", linum);
		if (line)
			free(line);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
