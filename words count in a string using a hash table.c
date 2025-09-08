#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define SIZE 1000

typedef unsigned long int ul;
typedef struct node {
    char * key;
    int value;
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
    return (hashTable) malloc(sizeof(h_node * ) * SIZE);
}

void add(hashTable tbl, char * key) {
    int hash = djb2(key) % SIZE;
    h_node * new_node = (h_node * ) malloc(sizeof(h_node));
    new_node -> key = key;
    new_node -> value = 1;
    new_node -> next = NULL;


    if (tbl[hash] == NULL) {
        tbl[hash] = new_node;
    }

    else {
        h_node * cur = tbl[hash];
        while (cur -> next != NULL || (strcmp(cur -> key, key)) == 0) {
            if ((strcmp(cur -> key, key)) == 0) {
                cur -> value += 1;
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
                printed++ ? printf(", '%s' : '%d'", cur -> key, cur -> value): printf("'%s' : '%d'", cur -> key, cur -> value);
                cur = cur -> next;
            }
        }
    }

    printf("}");
}

int get_item(hashTable tbl, char * key) {
    int hash = djb2(key) % SIZE;
    if (tbl[hash] == NULL) return 0;
    h_node * cur = tbl[hash];
    while (cur != NULL) {
        if ((strcmp(cur -> key, key)) == 0) return cur -> value;
        cur = cur -> next;
    }
    return 0;
}

void word_count(hashTable table, char * str) {

    int str_len = strlen(str), wrd_len = 0;
    char * ptr;


    for (int i = 0; i < str_len + 1; i++) {

        if (str[i] == '\0') break;

        else if (str[i] == ' ') {
            wrd_len = 0;
        }

        else {
            wrd_len++;
            if (str[i + 1] == ' ' || str[i + 1] == '\0') {
                ptr = (char * ) malloc(sizeof(char) * (wrd_len + 1));
                for (int j = 0; j < wrd_len; j++) {
                    *(ptr + j) = str[(i + j + 1) - wrd_len];
                }
                *(ptr + wrd_len) = '\0';

                add(table, ptr);
            }
        }

    }
}

int main() {

    hashTable table = craete();

    char * poem = "It was many and many a year ago,\
                        In a kingdom by the sea,\
                        That a maiden there lived whom you may know\
                        By the name of Annabel Lee;\
                        And this maiden she lived with no other thought\
                        Than to love and be loved by me.\
                        I was a child and she was a child,\
                        In this kingdom by the sea,\
                        But we loved with a love that was more than love—\
                        I and my Annabel Lee—\
                        With a love that the wingèd seraphs of Heaven\
                        Coveted her and me.";

    word_count(table, poem);

    print_table(table);


}
