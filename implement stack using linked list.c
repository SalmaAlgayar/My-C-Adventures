#include <stdio.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *link;
} s_node;
typedef s_node* s_top;

void push(s_top *top, int data){
    s_node *new_node;
    new_node = (s_node*)malloc(sizeof(s_node));
    new_node->data = data;
    new_node->link = *top;
    *top = new_node;
}

void pop(s_top *top){
    s_node *tmp = *top;
    if (tmp) {
        *top = (*top)->link;
        printf("%d\n", tmp->data);
        free(tmp);
    } else printf("Empty Stack\n");
}

void display(s_top top){
    int first_print = 0;
    printf("{");
    while (top){
        !first_print++ ? printf("%d", top->data) : printf(", %d", top->data);
        top = top->link;
    }
    printf("}\n");
}

void peek(s_top top){
    top? printf("%d\n", top->data) : printf("Empty Stack\n");
}


int main() {
	s_top top = NULL;
	peek(top);
	pop(&top);
	display(top);
	push(&top,5);
	push(&top,7);
	push(&top,2);
	push(&top,11);
	
	display(top);
	peek(top);
	
	pop(&top);
	pop(&top);
	
	display(top);
	peek(top);
	
	printf("%d\n", (*top).data);
	
}

