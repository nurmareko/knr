#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum Boolean {FALSE, TRUE};

#define	MAXOP	 100
#define	NUMBER	 '0'
#define MATH	 '1'
#define UNKNOWN	 '2'
#define VARIABLE '3'
#define ASSIGN   '4'
#define GREET	 "---- Reverse Polish Notation Calculator ---- \n"

int	getop(char[]);
void	push(double);
double	pop(void);
void	top(void);
void	duplicate(void);
void	swap(void);
void	clear(void);
void	apply(char[]);
void	assignvar(void);
double	varvalue(void);

double	variables[26];
int	varstate[26];
char	variable = 0;
int	assignment = FALSE;

/* reverse Polish calculator	*/
main() {
	printf("%s", GREET);

	int	type, i;
	double	op2;
	char	s[MAXOP];	/* collect op, rewrited on loops	*/

	for(i = 0; i < 26; i++)
		varstate[i] = FALSE;

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case VARIABLE:
			if (assignment == FALSE) {
				push(varvalue());
			} else
				assignment = FALSE;
			break;
		case MATH:
			apply(s);
			break;
		case '=':
			assignvar();
			break;
		case '+':
			push( pop() + pop());
			break;
		case '*':
			push( pop() * pop());
			break;
		case '-':
			op2 = pop();
			push( pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0) {
				push( pop() / op2);
			} else
				printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop();
			if (op2 != 0.0) {
				push((long)pop() % (long)op2);
			} else
				printf("%: zero divisor\n");
			break;
		case 'P':
			top();
			break;
		case 'D':
			duplicate();
			break;
		case 'S':
			swap();
			break;
		case 'C':
			clear();
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}
/*********************************************************************/
#define	MAXVAL	100

int 	sp = 0; /* next free stack positon	*/
double	val[MAXVAL];

/* push:  push f onto value stack	*/
void push(double f) {
	if (sp < MAXVAL) {
		val[sp++] = f;
	} else
		printf("error: stack full, can't push %g\n", f);
}

/* pop:  pop and return top value from stack	*/
double pop(void) {
	if (sp > 0) {
		return val[--sp];
	} else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* top: print the top element of the stack	*/
void top(void) {
	if (sp > 0) {
		printf("P: %.8g\n", val[sp-1]);
	} else
		printf("P: stack empty\n");
}

/* duplicate: duplicate the top element of the stack	*/
void duplicate(void) {
	if (sp < MAXVAL) {
		if (sp > 0) {
			val[sp++] = val[sp - 1];
		} else
			printf("D: stack empty\n");
	} else
		printf("D: stack full, can't duplicate\n");
}

/* swap: swap the sequence of the top two element of the stack	*/
void swap(void) {
	long op2, op1;	

	if (sp < 2) {
		printf("S: stack has less than two element\n");
	} else {
		op2 = pop();
		op1 = pop();
		push(op2);
		push(op1);
	}
}

/* clear: empty the stack	*/
void clear(void) {
	sp = 0;
}

/* apply: perform the application of the given operator */
void apply(char op[]) {
	double op2;
	
	if (strcmp(op, "acos") == 0) {
		push(acos(pop()));
	} else if (strcmp(op, "asin")  == 0) {
		push(asin(pop()));
	} else if (strcmp(op, "atan")  == 0) {
		push(atan(pop()));
	} else if (strcmp(op, "atan2") == 0) {
		op2 = pop();
		push(atan2(pop(), op2));
	} else if (strcmp(op, "cos")   == 0) {
		push(cos(pop()));
	} else if (strcmp(op, "cosh")  == 0) {
		push(cosh(pop()));
	} else if (strcmp(op, "sin")   == 0) {
		push(sin(pop()));
	} else if (strcmp(op, "sinh")  == 0) {
		push(sinh(pop()));
	} else if (strcmp(op, "tanh")  == 0) {
		push(tanh(pop()));
	} else if (strcmp(op, "exp")   == 0) {
		push(exp(pop()));
	} else if (strcmp(op, "log")   == 0) {
		push(log(pop()));
	} else if (strcmp(op, "log10") == 0) {
		push(log10(pop()));
	} else if (strcmp(op, "pow")   == 0) {
		op2 = pop();
		push(pow(pop(), op2));
	} else if (strcmp(op, "sqrt")  == 0) {
		push(sqrt(pop()));
	} else if (strcmp(op, "ceil")  == 0) {
		push(ceil(pop()));
	} else if (strcmp(op, "fabs")  == 0) {
		push(fabs(pop()));
	} else if (strcmp(op, "floor") == 0) {
		push(floor(pop()));
	} else if (strcmp(op, "fmod")  == 0) {
		op2 = pop();
		push(fmod(pop(), op2));
	}
}

/* assignvar: assign constant to variable	*/
void assignvar(void) {
	double 	value = pop();
	int	index;

	if (isalpha(variable)) {
		index = variable - 'a';
		varstate[index] = TRUE;
		push(variables[index] = value);
		variable = 0;
	} else
		printf("=: invalid assignment\n");
}

/* varvalue: get the given variable actual value	*/
double	varvalue(void) {
	int index = variable - 'a';

	if (varstate[index] == TRUE) {
		return variables[index];
		variable = 0;
	} else
		;
}
/*********************************************************************/
#include <ctype.h>
#include <string.h>

int	getch(void);
void	ungetch(int);
int	ismath(char[]);
void	ungets(char[]);

/* getop:  get next operator or numberic operand	*/
int getop(char s[]) {
	int	i, c, next;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	i = 0;
	if (!isdigit(c) && c != '.') {
		if (c == '-') {
			ungetch(next = getch());
			if (!isdigit(next) && next != '.')
				return '-';
		} else if (islower(c)) {
			while(isalnum(s[++i] = c = getch()))
				;
			s[i] = '\0';
			if (c != EOF)
				ungetch(c);
			if (ismath(s)) {
				return MATH;
			} else if (i == 1) {
				variable = s[0];
				if ((c=getch()) == '=')
					assignment = TRUE;
				ungetch(c);
				return VARIABLE;
			} else
				return UNKNOWN;
		}else
			return c;
	}
	if (isdigit(c) || c == '-')
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}
/*********************************************************************/
#include <string.h> 

char	buff;
int	havebuff = FALSE;

/* get a (possibly pushed back) character	*/
int getch(void) {
	if (havebuff) {
		havebuff = FALSE;
		return buff;
	} else
		return getchar();
}

/* push character back on input	*/
void ungetch(int c) {
	if (havebuff) {
		printf("ungetch:  already have char in buffer:%c\n", buff);
	} else
		buff = c;
}

/* ismath: is the given string a math library operator?	*/
int ismath(char s[]) {
	if (strcmp(s, "acos") == 0) {
		return TRUE;
	} else if (strcmp(s, "asin")  == 0) {
		return TRUE;
	} else if (strcmp(s, "atan")  == 0) {
		return TRUE;
	} else if (strcmp(s, "atan2") == 0) {
		return TRUE;
	} else if (strcmp(s, "cos")   == 0) {
		return TRUE;
	} else if (strcmp(s, "cosh")  == 0) {
		return TRUE;
	} else if (strcmp(s, "sin")   == 0) {
		return TRUE;
	} else if (strcmp(s, "sinh")  == 0) {
		return TRUE;
	} else if (strcmp(s, "tanh")  == 0) {
		return TRUE;
	} else if (strcmp(s, "exp")   == 0) {
		return TRUE;
	} else if (strcmp(s, "log")   == 0) {
		return TRUE;
	} else if (strcmp(s, "log10") == 0) {
		return TRUE;
	} else if (strcmp(s, "pow")   == 0) {
		return TRUE;
	} else if (strcmp(s, "sqrt")  == 0) {
		return TRUE;
	} else if (strcmp(s, "ceil")  == 0) {
		return TRUE;
	} else if (strcmp(s, "fabs")  == 0) {
		return TRUE;
	} else if (strcmp(s, "floor") == 0) {
		return TRUE;
	} else if (strcmp(s, "fmod")  == 0) {
		return TRUE;
	} else
		return FALSE;
}

/* ungets: push back entire string onto the input	*/
void ungets(char s[]) {
	int i;
	for (i = strlen(s) - 1; i >= 0; i--)
		ungetch(s[i]);
}












