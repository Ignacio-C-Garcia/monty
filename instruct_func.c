#include "monty.h"

/**
 *fstruct - Function that stands for struct list array
 *@i: int variable
 *Return: Array of i
 */

lista fstruct(int i)
{
lista array[] = {
	{'s', fun_str},
	{'c', fun_char},
	{'d', fun_int},
	{'i', fun_int},
	{'u', fun_unint},
	{'r', fun_rev},
	{'\0', NULL}
};
	return (array[i]);
}