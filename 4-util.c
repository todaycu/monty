#include "monty.h"
/**
 * _is_digit -check if string contain only digits
 * @s: string to be checked
 * Return: 1 if digit only else 0
 */
int _is_digit(char *s)
{
	int i  = 0;

	while (s[i] && s[i] != '#')
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

/**
 * nop - no operation
 */
void nop(void)
{}
/**
 * f - select opcode  instruction
 * @opcode: opcode
 * Return: instruction function pointer
 */
void (*f(char *opcode))(stack_t **stack, unsigned int line_num)
{

	if (_strcmp(opcode, "pop") == 0)
		return (pop);
	if (_strcmp(opcode, "add") == 0)
		return (add);
	if (_strcmp(opcode, "sub") == 0)
		return (sub);
	if (_strcmp(opcode, "mul") == 0)
		return (mul);
	if (_strcmp(opcode, "div") == 0)
		return (_div);
	if (_strcmp(opcode, "mod") == 0)
		return (mod);
	if (_strcmp(opcode, "rotl") == 0)
		return (rotl);
	if (_strcmp(opcode, "rotr") == 0)
		return (rotr);
	if (_strcmp(opcode, "pall") == 0)
		return (pall);
	if (_strcmp(opcode, "swap") == 0)
		return (swap);
	if (_strcmp(opcode, "pstr") == 0)
		return (pstr);
	if (_strcmp(opcode, "pchar") == 0)
		return (pchar);
	if (_strcmp(opcode, "pint") == 0)
		return (pint);
	return (NULL);

}
