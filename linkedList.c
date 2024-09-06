#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

/*
typedef union {
    int intval;
    char str[50];
    char charval;
    float floatval;
} data;
*/
typedef struct Node{
    struct Node *next;
    int data;
} Node;

Node* LinkedList(int numArgs, ...){
    va_list args;
    va_start(args, numArgs);
    int dataArg = va_arg(args, int);

    Node *head = (Node *)malloc(sizeof(Node));
    head->data = dataArg;
    Node *current = head;

    for (int i = 1; i < numArgs; i++){
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = va_arg(args, int);
        current->next = newNode;
        current = newNode;
    }

    current->next = NULL;
    va_end(args);
    return head;
}

void DisplayList(Node *head){
    Node *current = head;
    while (current!=NULL){
        printf("%d -> ",current->data);
        current = current->next;
    }
    printf("NULL\n");
}
int main(){
    Node *LL1head = LinkedList(5,1,2,3,4,5);
    DisplayList(LL1head);
    return 0;
}
