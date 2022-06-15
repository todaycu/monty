#define EXTERN
#include "monty.h"
/**
 * __push -execute push command
 * @argv: args
 * @linum: line number
 * @head: stack top
 */
void __push(char **argv, unsigned int linum, stack_t **head)
{
	if (!argv[1] || !_is_digit(argv[1]))
	{
		fprintf(stderr, "L%u: usage: push integer\n", linum);
		if (line)
			free(line);
		free_argv(argv);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	push(head, atoi(argv[1]), linum);
	free_argv(argv);
}
/**
 * free_argv - free args
 * @argv: args vector
 */
void free_argv(char **argv)
{
	int i =  -1;

	while (argv && argv[++i])
		free(argv[i]);
	free(argv);
}
/**
 * exec_line - execute one line
 * @head: stack top
 * @line_num: line number
 * Return: 1 if succcess else EXIT FAILURE
 */
int exec_line(stack_t **head, unsigned int line_num)
{

	char **argv = NULL;
	int index = 0;

	line[_strlen(line) - 2] = '\0';
	while (line[index] && line[index] != '#')
		index++;
	line[index] = '\0';
	argv = (char **)_strtok(line, argv, " ");
	if (strcmp(argv[0], "nop") == 0)
	{
		free_argv(argv);
		return (1);
	}
	if (_strcmp(argv[0], "push") == 0)
	{
		__push(argv, line_num, head);
		return (1);
	}
	else if (!f(argv[0]))
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_num, argv[0]);
		if (line)
			free(line);
		free_argv(argv);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	f(argv[0])(head, line_num);
	free_argv(argv);
	return (1);
}
/**
 * free_stack - free stack memory on exit
 * @head: stack top
 */
void free_stack(stack_t **head)
{
	stack_t *cur;

	cur = *head;
	while (*head)
	{
		*head = (*head)->next;
		free(cur);
		cur = *head;
	}
}

/**
 * main - entry point
 * @argc: args count
 * @argv: args vector
 * Return: 0 if success else EXIT_FAILUE
 */
int main(int argc, char **argv)
{
	stack_t *head = NULL;
	int line_num = 1;
	FILE *fp;
	size_t len = 0;
	ssize_t read;

	line = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, fp)) != -1)
	{
		if (line[0] == '#' || line[0] == '\n')
			continue;
		exec_line(&head, line_num);
		line_num++;
	}
	fclose(fp);
	if (line)
		free(line);
	free_stack(&head);
	exit(EXIT_SUCCESS);
}
