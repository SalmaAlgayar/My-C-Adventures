#include <stdio.h>

typedef struct Node {
    int data;
    struct Node * link;
}
q_node;
typedef q_node * q_front;
typedef q_node * q_rear;

void enqueue(q_front * front, q_rear * rear, int data) {
    q_node * new_node;
    new_node = (q_node * ) malloc(sizeof(q_node));
    new_node -> data = data;
    new_node -> link = NULL;

    if (! * front) {
        * front = * rear = new_node;
        return;
    };

    ( * rear) -> link = new_node;
    * rear = new_node;
}


void dequeue(q_front * front) {
    q_node * tmp = * front;
    if (tmp) {
        * front = ( * front) -> link;
        printf("%d\n", tmp -> data);
        free(tmp);
    } else printf("Empty Queue\n");
}

void display(q_front front) {
    int first_print = 0;
    printf("{");
    while (front) {
        !first_print++ ? printf("%d", front -> data): printf(", %d", front -> data);
        front = front -> link;
    }
    printf("}\n");
}

void peek(q_front front) {
    front ? printf("%d\n", front -> data) : printf("Empty Queue\n");
}

int main() {
    q_front front = NULL;
    q_rear rear = NULL;
    display(front);
    peek(front);
    dequeue( & front);

    enqueue( & front, & rear, 22);


    printf("%d\n", front -> data);
    printf("%d\n", rear -> data);

    enqueue( & front, & rear, 33);

    printf("%d\n", front -> data);
    printf("%d\n", rear -> data);

    enqueue( & front, & rear, 54);
    enqueue( & front, & rear, 12);
    enqueue( & front, & rear, 87);
    enqueue( & front, & rear, 43);
    enqueue( & front, & rear, 97);

    printf("%d\n", front -> link -> link -> data);
    printf("%d\n", rear -> data);

    display(front);



    dequeue( & front);
    dequeue( & front);

    printf("%d\n", front -> data);
    printf("%d\n", rear -> data);

    display(front);
    peek(front);


}
