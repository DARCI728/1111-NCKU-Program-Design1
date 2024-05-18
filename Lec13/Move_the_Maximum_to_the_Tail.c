#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;
void MoveToTail();

void add_node(struct node *head, int num) {
    struct node *cur = head;
    while (cur->next) cur = cur->next;

    struct node *new_node = malloc(sizeof(struct node));
    new_node->val = num;
    new_node->next = NULL;

    cur->next = new_node;
}

struct node *delete_node(struct node *list, int n) {
    struct node *cur, *prev;
    for (cur = list, prev = NULL;
         cur != NULL && cur->val != n;
         prev = cur, cur = cur->next)
        ;
    if (cur == NULL)
        return list;
    if (prev == NULL)
        list = list->next;
    else
        prev->next = cur->next;
    free(cur);
    return list;
}

void print_node(struct node *head) {
    struct node *cur = head;
    while (cur->next) {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("%d ", cur->val);
    printf("\n");
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        struct node *tmp = malloc(sizeof(struct node));
        scanf("%d", &tmp->val);
        tmp->next = NULL;
        if (i == 1)
            head = tmp;
        else
            tail->next = tmp;
        tail = tmp;
    }
    MoveToTail();
    for (struct node *cur = head; cur != NULL; cur = cur->next) {
        printf("%d ", cur->val);
    }
    return 0;
}

void MoveToTail() {
    int max = 0;
    struct node *cur = head;
    do {
        if (cur->val > max) max = cur->val;
        cur = cur->next;
    } while (cur->next);
    if (cur->val > max) max = cur->val;
    if (tail->val != max) {
        head = delete_node(head, max);
        add_node(tail, max);
    }
}
