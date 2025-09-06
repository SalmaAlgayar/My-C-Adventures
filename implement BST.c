#include <stdio.h>

#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node * left;
    struct Node * right;
}
t_node;

typedef t_node * root_ptr;

t_node * get_new_node(int data) {
    t_node * new_node;
    new_node = (t_node * ) malloc(sizeof(t_node));
    new_node -> data = data;
    new_node -> left = new_node -> right = NULL;
    return new_node;
}

void insert(root_ptr * root_ptr, int data) {

    if (! * root_ptr) {
        * root_ptr = get_new_node(data);
        return;
    }

    else if (( * root_ptr) -> data > data) {
        insert( & (( * root_ptr) -> left), data);
    }
    else {
        insert( & (( * root_ptr) -> right), data);
    }

}

root_ptr insert2(root_ptr root_ptr, int data) {

    if (!root_ptr) {
        root_ptr = get_new_node(data);
        return root_ptr;
    }
    else if (root_ptr -> data > data) {
        root_ptr -> left = insert2(root_ptr -> left, data);
    }
    else {
        root_ptr -> right = insert2(root_ptr -> right, data);
    }
    return root_ptr;



}

bool search(root_ptr root_ptr, int data) {

    while (root_ptr) {
        if ((root_ptr -> data) == data) return true;
        else if ((root_ptr -> data) == data) root_ptr = root_ptr -> left;
        else root_ptr = root_ptr -> right;
    }

    return false;
}

bool search2(root_ptr root_ptr, int data) {
    if (!root_ptr) return false;
    if ((root_ptr -> data) == data) return true;
    else if ((root_ptr -> data) == data) return search2(root_ptr -> left, data);
    else return search2(root_ptr -> right, data);

}

int main() {
    root_ptr root_ptr = NULL;

    insert( & root_ptr, 15);
    insert( & root_ptr, 10);
    insert( & root_ptr, 20);
    insert( & root_ptr, 25);
    printf("%d\n", root_ptr -> data);
    printf("%d\n", root_ptr -> left -> data);
    printf("%d\n", root_ptr -> right -> data);
    printf("%d\n", root_ptr -> right -> right -> data);

    printf("%d\n", search(root_ptr, 200));
    printf("%d\n", search2(root_ptr, 20));


    root_ptr = insert2(root_ptr, 90);
    printf("%d\n", root_ptr -> data);

    root_ptr = insert2(root_ptr, 98);
    printf("%d\n", root_ptr -> data);

    printf("%d\n", root_ptr -> right -> data);

}
