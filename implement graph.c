#include <stdio.h>

#include <stdlib.h>

typedef struct Node {
    int vertex;
    int weight;
    struct Node * next;
}
g_node_t;

typedef g_node_t * g_node_ptr;

typedef struct Graph {
    int num_vertices;
    g_node_ptr * adj_lists;
}
graph_t;

typedef graph_t * graph_ptr;

g_node_ptr create_node(int vertex, int weight) {
    g_node_ptr new_node_ptr;
    new_node_ptr = (g_node_ptr) malloc(sizeof(g_node_t));
    new_node_ptr -> vertex = vertex;
    new_node_ptr -> weight = weight;
    new_node_ptr -> next = NULL;
    return new_node_ptr;
}

graph_ptr create_graph(int num_vertices) {
    graph_ptr new_graph_ptr;
    new_graph_ptr = (graph_ptr) malloc(sizeof(graph_t));
    new_graph_ptr -> num_vertices = num_vertices;
    new_graph_ptr -> adj_lists = (g_node_ptr * ) malloc(sizeof(g_node_ptr) * num_vertices);

    for (int i = 0; i < num_vertices; i++) {
        new_graph_ptr -> adj_lists[i] = NULL;
    }
    //printf("\n%p %p\n", new_graph_ptr -> adj_lists, &(new_graph_ptr -> adj_lists[0]));
    return new_graph_ptr;
}

void free_graph(graph_ptr graph_ptr) {
    for (int i = 0; i < graph_ptr -> num_vertices; i++) {
        g_node_ptr cur = graph_ptr -> adj_lists[i];
        while (cur) {
            g_node_ptr tmp = cur;
            cur = cur -> next;
            free(tmp);
        }
    }
    free(graph_ptr -> adj_lists);
    free(graph_ptr);
}

void add_edge(graph_ptr graph, int src, int dest, int weight) {
    g_node_ptr g_node_ptr = create_node(dest, weight);
    g_node_ptr -> next = (graph -> adj_lists)[src];
    graph -> adj_lists[src] = g_node_ptr;
}

void print_graph(graph_ptr graph) {
    for (int i = 0; i < graph -> num_vertices; i++) {
        g_node_ptr cur = graph -> adj_lists[i];
        if (!cur) continue;
        printf("Adjacency list of vertex %d ", i);
        while (cur) {
            printf(" (%d , %d) -> ", cur -> vertex, cur -> weight);
            cur = cur -> next;
        }
        printf("NULL\n");
    }

}


int main() {

    graph_ptr graph_ptr = create_graph(4);

    add_edge(graph_ptr, 0, 1, 5);
    add_edge(graph_ptr, 0, 2, 3);
    add_edge(graph_ptr, 1, 2, 2);
    add_edge(graph_ptr, 2, 3, 7);
    print_graph(graph_ptr);


    free(graph_ptr);

}
