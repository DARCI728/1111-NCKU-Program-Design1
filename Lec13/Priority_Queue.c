#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
    int weight;
    int value;
    struct node_s *next;
} node_t;

typedef struct prio_queue_s {
    node_t *head;
} prio_queue_t;

void enqueue(prio_queue_t *const queue, int value, int weight);
node_t *dequeue(prio_queue_t *const queue);
void print_nodes(const prio_queue_t *const queue);
void delete_node(prio_queue_t *head, int value);

int main() {
    int N;
    scanf("%d", &N);
    prio_queue_t queue = {
        .head = NULL,
    };
    for (int i = 0; i < N; i++) {
        char op[8];
        scanf("%s", op);
        if (!strcmp(op, "ENQUEUE")) {
            int v, w;
            scanf("%d%d", &v, &w);
            enqueue(&queue, v, w);
        } else if (!strcmp(op, "DEQUEUE")) {
            free(dequeue(&queue));
        }
        print_nodes(&queue);
    }

    return 0;
}

void enqueue(prio_queue_t *const queue, int value, int weight) {
    node_t *cur = queue->head;
    node_t *temp = malloc(sizeof(node_t *));
    node_t *new_node = malloc(sizeof(node_t *));
    new_node->value = value;
    new_node->weight = weight;
    new_node->next = NULL;

    if (queue->head == NULL) {
        queue->head = new_node;
    } else if (weight < cur->weight) {
        new_node->next = cur;
        queue->head = new_node;
    } else {
        while (1) {
            if (cur->next == NULL) {
                cur->next = new_node;
                break;
            } else if (cur->next->weight > weight) {
                temp = cur->next;
                cur->next = new_node;
                new_node->next = temp;
                break;
            }
            cur = cur->next;
        }
    }
}

node_t *dequeue(prio_queue_t *const queue) {
    node_t *delete_node = malloc(sizeof(node_t *));
    if (queue->head == NULL) return 0;
    delete_node = queue->head;
    if (delete_node->next == NULL)
        queue->head = NULL;
    else
        queue->head = delete_node->next;
    return delete_node;
}

void print_nodes(const prio_queue_t *const queue) {
    if (!queue->head) {
        printf("EMPTY\n");
        return;
    }
    for (node_t *node = queue->head; node; node = node->next) {
        printf(" -> %d", node->value);
    }
    printf("\n");
    return;
}