#include <stdio.h>

#include <string.h>


#define SIZE 1000
int simple_hash(char * str) {
    int hash = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash += (int) str[i];
    }
    return hash;
}


typedef unsigned long int ul;
typedef struct node {
    char * key;
    char * value;
    struct node * next;
}
h_node;
typedef h_node ** hashTable;

ul djb2(char * str) {
    ul hash = 5381;
    int c;
    while (c = * str++) {
        hash = (hash << 5) + hash + c;
    }
    return hash;
}

hashTable craete() {
    return (hashTable) malloc(sizeof(h_node) * SIZE);
}


void add(hashTable tbl, char * key, char * value) {
    int hash = djb2(key) % SIZE;
    h_node * new_node = (h_node * ) malloc(sizeof(h_node));
    new_node -> key = key;
    new_node -> value = value;
    new_node -> next = NULL;


    if (tbl[hash] == NULL) {
        tbl[hash] = new_node;
    }

    else {
        h_node * cur = tbl[hash];
        while (cur -> next != NULL || (strcmp(cur -> key, key)) == 0) {
            if ((strcmp(cur -> key, key)) == 0) {
                cur -> value = value;
                return;
            }
            cur = cur -> next;
        }
        cur -> next = new_node;

    }


}



void free_hashTable(hashTable tbl) {
    for (int i = 0; i < SIZE; i++) {
        h_node * cur = tbl[i];
        while (cur != NULL) {
            h_node * tmp = cur -> next;
            free(cur);
            cur = tmp;
        }
    }
    free(tbl);
}

void print_table(hashTable tbl) {
    int printed = 0;
    printf("{");
    h_node * cur;

    for (int i = 0; i < SIZE; i++) {
        if (tbl[i] != NULL) {
            cur = tbl[i];
            while (cur != NULL) {
                printed++ ? printf(", '%s' : '%s'", cur -> key, cur -> value): printf("'%s' : '%s'", cur -> key, cur -> value);
                cur = cur -> next;
            }
        }
    }

    printf("}");
}

char * get_item(hashTable tbl, char * key) {
    int hash = djb2(key) % SIZE;
    if (tbl[hash] == NULL) return NULL;
    h_node * cur = tbl[hash];
    while (cur != NULL) {
        if ((strcmp(cur -> key, key)) == 0) return cur -> value;
        cur = cur -> next;
    }
    return "Found hash but not the key";
}



int main() {

    hashTable table = craete();

    add(table, "husband", "Karim");
    add(table, "wife", "Salomy");
    add(table, "husband", "Khalid");
    
    print_table(table);
    
    printf("\n%s\n", get_item(table, "daughter"));

}
