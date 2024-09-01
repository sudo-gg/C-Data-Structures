#include <stdlib.h>
#include <stdio.h>

typedef union elementType{
    int intval;
    float floatval;
    char charval;
    char stringval[100];
} elementType;

typedef struct Stack{
    int head = 0;
    elementType values[100];
} Stack;

int main(){
    Stack stack1;
    stack1.values[0].floatval = 5.7;
    printf("%d %f",stack1.head,stack1.values->floatval)
    return 0;
}