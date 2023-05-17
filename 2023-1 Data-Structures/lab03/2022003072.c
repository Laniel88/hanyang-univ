#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ISFULL 1
#define ISEMPTY 2
#define DIVIDEZERO 3

FILE *fin;
FILE *fout;

typedef struct Stack{
	int *key;
	int top;
	int max_stack_size;
} Stack;

Stack* CreateStack(int max);
void Push(Stack* S, int X);
int Pop(Stack* S);
int Top(Stack* S);

void DeleteStack(Stack* S);
int IsEmpty(Stack* S);
int IsFull(Stack* S);

int main(int argc, char *argv[]){
	fin=fopen(argv[1], "r");
	fout=fopen(argv[2], "w");

	Stack* stack;
	char input_str[101];
	int max=20, i=0,a,b,result, error_flag=0;

	fgets(input_str,101,fin);
	stack = CreateStack(max);
	
	fprintf(fout, "top numbers : ");
	while(input_str[i]!='#'){
        if (input_str[i] >= '0' && input_str[i] <= '9') {
            if (IsFull(stack)) {
                error_flag = ISFULL;
                break;
            }
            Push(stack, input_str[i] - '0');
        }  else {
            // pop the top two elements from the stack
            b = Pop(stack);
            a = Pop(stack);

            if(a == -1 || b == -1) {
                // check if Pop function is normally closed without exception(IsEmpty)
                error_flag = ISEMPTY;
                break;
            }

            // perform the operation based on the operator
            switch(input_str[i]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/':
                    if (b == 0) {
                        // check if dividing by zero
                        error_flag = DIVIDEZERO;
                        break;
                    }
                    result = a / b;
                    break;
                case '%':
                    if (b == 0) {
                        // check if dividing by zero
                        error_flag = DIVIDEZERO;
                        break;
                    }
                    result = a % b;
                    break;
            }

            // push the result onto the stack
            Push(stack, result);
        }

		if(error_flag) break;

		int t = Top(stack);
		fprintf(fout, "%d ",t);
		result=t;

		i++;
	}

	if(error_flag == ISFULL){
		fprintf(fout, "\nerror : invalid postfix expression, stack is full!\n");
	}
	else if(error_flag == ISEMPTY){
		fprintf(fout, "\nerror : invalid postfix expression, stack is empty!\n");
	}
	else if(error_flag == DIVIDEZERO){
		fprintf(fout, "\nerror : invalid postfix expression, divide by zero!\n");
	}

	else{
		if(stack->top+1 > 1){
			fprintf(fout, "\nerror : invalid postfix expression, %d elements are left!\n", stack->top+1);
		}
		else{
			fprintf(fout, "\nevaluation result : %d\n",result);
		}
	}
	fclose(fin);
	fclose(fout);
	DeleteStack(stack);
}

Stack* CreateStack(int max){
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->key = (int*)malloc(sizeof(int) * max);
    stack->top = -1;
    stack->max_stack_size = max;
    return stack;
}

void DeleteStack(Stack* S){
    free(S->key);
    free(S);
}

void Push(Stack* S, int X){
    if(IsFull(S)) return;
    S->key[++S->top] = X;
}

int Pop(Stack* S){
    if(IsEmpty(S)) return -1;
    return S->key[S->top--];
}

int Top(Stack* S){
    if(IsEmpty(S)) return -1;
    return S->key[S->top];
}

int IsFull(Stack* S){
    return S->top == S->max_stack_size - 1;
}

int IsEmpty(Stack* S){
    return S->top == -1;
}