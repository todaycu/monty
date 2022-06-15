#ifndef MONTY_H
#define MONTY_H
#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/*
* stack functions
*/
#ifndef EXTERN
#define EXTERN extern
#endif

EXTERN char *line;
void free_stack(stack_t **head);
void free_argv(char **argv);
int _is_digit(char *s);
void push(stack_t **head, int data, unsigned int linum);
void add_end(stack_t **head, int data, unsigned int linum);
void pop(stack_t **head, unsigned int linum);
void swap(stack_t **head, unsigned int linum);
void add(stack_t **head, unsigned int linum);
void sub(stack_t **head, unsigned int linum);
void mul(stack_t **head, unsigned int linum);
void mod(stack_t **head, unsigned int linum);
void _div(stack_t **head, unsigned int linum);
void pint(stack_t **head, unsigned int linum);
void pchar(stack_t **head, unsigned int linum);
void pstr(stack_t **head, unsigned int __attribute__((unused))linum);
void rotl(stack_t **head, unsigned int __attribute__((unused))linum);
void rotr(stack_t **head, unsigned int __attribute__((unused))linum);
void pall(stack_t **head, unsigned int __attribute__((unused))linum);
void nop(void);
void (*f(char *opcode))(stack_t **stack, unsigned int line_num);
void __push(char **argv, unsigned int linum, stack_t **head);

/*
* string functions
*/
size_t _strlen(const char *s);
char *_strtok(char *s, char **p, char *sep);
int _strcmp(char *src, char *dest);
int _strcpy(char *src, char *dest);
size_t len_words(char **s);
int _memset(char *mem, size_t size);
size_t len_from_to(char *p, int start, char stop);
int _strcmp_index(char *src, char *dest);
void _strcpy_index(char *src, char *dest, size_t start_index);
#endif
