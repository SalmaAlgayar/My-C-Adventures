#include <stdio.h>

typedef struct Node {
        int value;
        struct Node *next;
    } node_t;

void display_ll(node_t *start_node){
    while (start_node) {
        printf("%d  ", start_node->value);
        start_node = start_node->next;
    }
    printf("\n");
}

node_t* create_new_node(int value){
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;
}

void insert_at_head(node_t** head, node_t* node_to_insert){
    node_to_insert->next = *head;
    *head = node_to_insert;
    //return node_to_insert;
}

node_t* find_node(node_t* head, int value){
    node_t *tmp = head;
    while(tmp){
        if (tmp->value == value) return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

void insert_after_node(node_t* before, node_t* me){
    me->next = before->next;
    before->next = me;
}

int main() {
    node_t *head = NULL, *tmp;
    
    for (int i = 1; i<=22; i++){
        tmp = create_new_node(i);
        tmp->next = head;
        head = tmp;
} 
    display_ll(head);
    head = NULL;
    
    for (int i = 1; i<=22; i++){
        if (!head) {
            tmp = create_new_node(i);
            head = tmp;
        }
        else if (!head->next){
            tmp = create_new_node(i);
            head->next = tmp;
        }
        else {
            (*tmp).next = create_new_node(i);
            tmp = tmp->next;
        }
        
        }
        
        
    int arr[4] = {3,8,5,11};
    head = NULL;
    for(int i = 0; i< sizeof(arr)/sizeof(int); i++){
        if (!head) {
            tmp = create_new_node(arr[i]);
            head = tmp;
        }
        else if (!head->next){
            tmp = create_new_node(arr[i]);
            head->next = tmp;
        }
        else {
            (*tmp).next = create_new_node(arr[i]);
            tmp = tmp->next;
        }
    }
    
    node_t* a2l(int arr[], int size){
        node_t *head = NULL, *tmp;
        for(int i = 0; i< size; i++){

        if (!head) {
            tmp = create_new_node(arr[i]);
            head = tmp;
        }
        else if (!head->next){
            tmp = create_new_node(arr[i]);
            head->next = tmp;
        }
        else {
            (*tmp).next = create_new_node(arr[i]);
            tmp = tmp->next;
        }
    }
    return head;
    }
    
    head = NULL;
    for (int i = 1; i<=10; i++){
        tmp = create_new_node(i);
        insert_at_head(&head, tmp);
} 
    
    display_ll(a2l(&arr, sizeof(arr)/sizeof(int)));
    display_ll(head);
    node_t *f = find_node(head, 8);
    if (f) printf("\n%d\n", f->value);
    
    insert_after_node(head, create_new_node(999));
    
    display_ll(head);
    
    insert_after_node(find_node(head, 7), create_new_node(54545));
    
    display_ll(head);
    
}
