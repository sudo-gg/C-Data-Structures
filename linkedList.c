#include <stdlib.h>
#include <stdio.h>

typedef union {
    int intval;
    char str[100];
    char charval;
    float floatval;
} elementtype;

typedef struct Node{
    struct Node *next;
    elementtype element;
} Node;

int main(){
    Node Node1;
    Node Node2;
    Node Node3;
    Node1.element.intval = 69;
    Node1.next = &Node3;
    Node3.next = &Node2;
    printf("%d %p ",Node1.element.intval,*Node1.next);
    return 0;
}
