#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_STACK_SIZE 20

typedef int element;
typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
}StackType;

char tmp[MAX_STACK_SIZE] = "";

// stack initiate
void init(StackType *s) {
		s->top = -1;
}

// check whether stack is empty
int is_empty(StackType *s) {
		return (s->top == -1);
}

// check whether stack is full
int is_full(StackType *s) {
		return (s->top == (MAX_STACK_SIZE-1));
}

// insert to the stack
void push(StackType *s, element item) {
		if ( is_full(s) ) {
			fprintf(stderr," \n");
			return;
		}else s->stack[++(s->top)] = item;

}

// delete from the stack
element pop(StackType *s) {
	if ( is_empty(s) ) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
		} else return s->stack[(s->top)--];
}

// peek function
element peek(StackType *s) {
	if ( is_empty(s) ) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
		} else return s->stack[s->top];
}

// return priority
int prec(char op) {
	switch(op){
		case '(': case ')': return 0;
		case '+': case '-': return 1;
		case '*': case '/': return 2;
		}
		return -1;
}

//infix to postfix
void infix_to_postfix(char infix[],char postfix[])
{
    StackType s;
    char x,token;
    int i,j;    //i-index of infix, j-index of postfix
    init(&s);
    j=0;

    for(i=0;infix[i]!='\0';i++)
    {
        token=infix[i];
        if(isalnum(token))
            postfix[j++]=token;
        else
            if(token=='(')
               push(&s,'(');
        else
            if(token==')')
                while((x=pop(&s))!='(')
                      postfix[j++]=x;
                else
                {
                    while(!is_empty(&s) && (prec(token) <= prec(peek(&s))))
                    {
                        x=pop(&s);
                        postfix[j++]=x;
                    }
                    push(&s,token);
                }
    }

    while(!is_empty(&s))
    {
        x=pop(&s);
        postfix[j++]=x;
    }

    postfix[j]='\0';
		printf("postfix_to_infix expression: %s", postfix);
		printf("\n");
}

// postfix to infix
char* postfix_to_infix(char expression[])
{
	printf("\ninfix_to_postfix expression:");
	/* fill in the blank */
	int count, length;
	char element, operator;
	StackType s;

	length = strlen(expression);

	for(count = 0; count < MAX_STACK_SIZE; count++){
		s.stack[count] = 0;
	}

	printf("(%c", expression[0]);

	for(count = 1; count < length; count++){
		if(expression[count] == '+' || expression[count] == '-' || expression[count] == '*' || expression[count] == '/'){
			element = pop(&s);
			operator = expression[count];
			printf("%c%c)", operator, element);
		}
		else
			push(&s, expression[count]);
	}
	printf("\n");

	return expression;
}

//evaluate postfix expression
int postfixEval(char exp[])
{
  /* fill in the blank */
	StackType s;
	init(&s);
	int tmp;

	for(int i = 0; exp[i] != '\0'; i++){
		if(isdigit(exp[i])){
			push(&s, exp[i] - '0');
		}
		else{
			switch (exp[i]) {
				case '+':
					tmp = s.stack[s.top - 1] + s.stack[s.top];
					pop(&s);
					pop(&s);
					push(&s, tmp);
					break;
				case '-':
					tmp = s.stack[s.top - 1] - s.stack[s.top];
					pop(&s);
					pop(&s);
					push(&s, tmp);
					break;
				case '*':
					tmp = s.stack[s.top - 1] * s.stack[s.top];
					pop(&s);
					pop(&s);
					push(&s, tmp);
					break;
				case '/':
					tmp = s.stack[s.top - 1] + s.stack[s.top];
					pop(&s);
					pop(&s);
					push(&s, tmp);
					break;
				default:
					break;
			}
		}
	}
	return peek(&s);
}

int main() {

	FILE *f;
	char postfix[30];
	char* tmp = (char*)malloc(sizeof(char)*20);

	f=fopen("input1.txt","r");
	fscanf(f,"%s", tmp);
	infix_to_postfix(tmp, postfix);
	printf("\neval: %d \n", postfixEval(postfix));

	f=fopen("input2.txt","r");
	fscanf(f,"%s", tmp);
	postfix_to_infix(tmp);
	printf("\neval: %d \n", postfixEval(tmp));

	return 0;
}
