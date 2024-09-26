#include <stdio.h>
#include <stdlib.h>

#define	MAXOP	100
#define	OPERAND	'0'

int	getop(char[]);
void	push(double);
double	pop(void);

/* reverse Polish calculator	*/
main() {
	int	type;
	double	op2;
	char	s[MAXOP];

	while ((type = getop(s)) != EOF)
		switch (type) {
		case OPERAND:
			push(getval(s));
			break;
		case OPERATOR:
			push(operate());
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}






while (next operator or operand is not end-of-file indicator)
	if (operand)
		push it

	else if (operator)
		pop operands
		do operation
		push result

	else if (newline)
		pop and print to of stack

	else
		error