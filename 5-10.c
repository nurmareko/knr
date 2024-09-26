#include <math.h>
#include <stdio.h>
#include <string.h>

int 	is_num(char*);
int 	is_op(char*);
int 	get_type(char*);
double	pop(void);
void	push(double);

extern int _CRT_glob = 0;

/* expr: evalautes reverse Polish expr from the command line	*/
main(int argc, char *argv[]){
	char *current;
	long op2;

	while (--argc > 0) {
		current = *++argv;
		switch (get_type(current)) {
			case '#':
				push(atof(current));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push( pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0) {
					push(pop() / op2);
				} else
					printf("error: zero divisor\n");
				break;
			default:
				printf("error: unknown command %s\n", current);
		}
	}
	printf("\t%.8g\n", pop());
	return 0;
}
/****************************************************************/
#define	MAXVAL	100	/* maximum depth of val stack		*/

int	sp = 0;		/* next free stack position		*/
double	val[MAXVAL];	/* value stack				*/

/* push:  push f onto value stack				*/
void push(double f) {
	if (sp < MAXVAL) {
		val[sp++] = f;
	} else
		printf("error: stack full, can't push %g\n", f);
}

/* pop:  pop and return top value from stack			*/
double pop(void) {
	if (sp > 0) {
		return val[--sp];
	} else {
		printf("error: stack empty\n");
		return 0.0;
	}
}
/****************************************************************/
/* get_type: is s a representation of number or operator?	*/
int get_type(char *s) {
	if (is_op(s)) {
		return *s;
	} else if (is_num(s)) {
		return '#';
	} else
		return '?';	/* unknown command		*/
}

/* is_op: is the string s a representation of operator?			*/
int is_op(char *s) {
	int is_length_one = (strlen(s) == 1);
	int is_op_sign = (*s == '+' || *s == '*' || *s == '-' || *s == '/');

	return (is_length_one && is_op_sign);
}

/* is_num: is the string s a representation of number?			*/
int is_num(char *s) {
	for (; *s != '\0'; ++s)
		if (!isdigit(*s) && *s != '.')
			return 0;
	return 1;
}