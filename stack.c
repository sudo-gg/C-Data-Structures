#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

typedef union element{
    int intval;
    float floatval;
    char charval;
    char stringval[100];
} element;

/*
The stacks bottom is index 0 so peek from last index
Also had to give up on union element above since it was not being taken as a parameter directly and it would be a pain to make multiple pointers for each argument
So now just an int stack
might try later to get the data type of the stack to be a parameter to the function
*/
typedef struct{
    // element data; future datatype addition?
    int max;
    int top;  // integer index of the top of the stack used to ensure doesnt go out of bounds
    int *head;
} Stack;


Stack CreateStack(int size,int numArgs,...){
    if (numArgs > size){
        printf("Stack Overflow");
        return NULL;
    }
    //Called tmpstack since will be returned and given a name on return
    Stack tmpstack;
    tmpstack.max = size;
    va_list args;
    va_start(args,numArgs);
    int *head = calloc(size,sizeof(int)); // *head = calloc(size,sizeof(int)); || head[size]; ?

    for (int i = 0; i < numArgs; i++){
        head[i] = va_arg(args,int);
    }
    va_end(args);
    tmpstack.head = (int *)(head+numArgs-1);
    return tmpstack;
}

int Peek(Stack tmpstack){
    return *(tmpstack.head);
}

int Pop(int *head){
}

int main(){
    Stack stack1 = CreateStack(5,4,2,3,4,5);
    printf("Peek: %d\n",Peek(stack1));
    return 0;
}