#include <stdio.h>
#include <stdlib.h>
#define node struct NODE

node {
    int data;
    node *next;
};

void insert(node **graph, int a, int b);
node *newnode(int n);
void create(node **graph, int a, int b);

int main() {
    int n = 7, i;
    node **graph = (node **)malloc(n * sizeof(node *));

    for (i = 0; i < n; i++) {
        graph[i] = NULL;
    }

    insert(graph, 1, 2);
    insert(graph, 1, 3);
    insert(graph, 2, 4);
    insert(graph, 3, 4);
    insert(graph, 3, 5);
    insert(graph, 5, 6);
    insert(graph, 4, 5);

    for (i = 0; i < 8; i++) {
        printf("%d -> ", i);
        node *p = graph[i];
        while (p != NULL) {
            printf("%d -> ", p->data);
            p = p->next;
        }
        printf("N\n");
    }
}

node *newnode(int n) {
    node *temp = (node *)malloc(sizeof(node));
    temp->data = n;
    temp->next = NULL;
    return temp;
}

void insert(node **graph, int a, int b) {
    create(graph, a, b);
    create(graph, b, a); // Create an edge in both directions
}

void create(node **graph, int a, int b) {
    node *temp = newnode(b);
    node *p = graph[a];

    if (p == NULL)
        graph[a] = temp;
    else {
        while (p->next != NULL)
            p = p->next;
        p->next = temp;
    }
}
