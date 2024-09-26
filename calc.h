#define	MAXOP	 100
#define	NUMBER	 '0'
#define MATH	 '1'
#define UNKNOWN	 '2'
#define VARIABLE '3'
#define ASSIGN   '4'
#define GREET	 "---- Reverse Polish Notation Calculator ---- \n"
#define	MAXVAL	 100
#define BUFSIZE  100

enum Boolean {FALSE, TRUE};

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
int	getch(void);
void	ungetch(int);
int	ismath(char[]);

double	variables[26];
int	varstate[26];
char	variable = 0;
int	assignment = FALSE;
int 	sp = 0;
double	val[MAXVAL];
char	buf[BUFSIZE];
int	bufp = 0;