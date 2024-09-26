#include <stdio.h>
#include <math.h>	/* for atof()				*/

#define	MAXOP	 100	/* max size of operand or operator	*/
#define	NUMBER	 '0'	/* signal that a number was found	*/
#define GREET	 "---- Reverse Polish Notation Calculator ---- \n"

int	getop(char[]);
void	push(double);
double	pop(void);

/* reverse Polish calculator	*/
main() {
	printf("%s", GREET);

	int	type;
	double	op2;
	char	s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push( pop() + pop());
			break;
		case '*':
			push( pop() * pop());
			break;
		case '-':
			printf("-: not here!!\n");
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
		case '%':
			op2 = pop();
			if (op2 != 0.0) {
				push(fmod(pop(), op2));
			} else
				printf("error: zero divisor\n");
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
#define	MAXVAL	100	/* maximum depth of val stack		*/

int	sp = 0;		/* next free stack position		*/
double	val[MAXVAL];	/* value stack	*/

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
/*********************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define	NUMBER	'0' /* signal that a number was found		*/

int	getch(void);
void	ungetch(int);

/* getop:  get next operator or numberic operand		*/
int getop(char s[]) {
	int	c, i;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	i = 0;
	if (!isdigit(c) && c != '.' && c != '-')
		return c;	/* not a number			*/
	if (c == '-')
		if (isdigit(c = getch()) || c == '.') {
			s[++i] = c;	/* negative number	*/
		} else {
			if (c != EOF)
				ungetch(c);
			return '-';	/* minus sign		*/
		}	
	if (isdigit(c))		/* collect integer part		*/
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
#define BUFSIZE 100

char 	buf[BUFSIZE];	/* buffer for ungetch			*/
int	bufp = 0;	/* next free position in buf		*/

/* getch: get a (possibly pushed back) character		*/
int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push character back on input			*/
void ungetch(int c) {
	if (bufp >= BUFSIZE) {
		printf("ungetch: too many characters\n");
	} else
		buf[bufp++] = c;
}

