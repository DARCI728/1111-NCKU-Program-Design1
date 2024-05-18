#include <stdio.h>
#include <stdlib.h>

struct list {
    int number;
    struct list *next;
};

void add_node(struct list *head, int num) {
    struct list *cur = head;
    while (cur->next) cur = cur->next;

    struct list *new_card = malloc(sizeof(struct list));
    new_card->number = num;
    new_card->next = NULL;

    cur->next = new_card;
}

struct list *delete_node(struct list *list, int n) {
    struct list *cur, *prev;
    for (cur = list, prev = NULL;
         cur != NULL && cur->number != n;
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

void print_node(struct list *head) {
    struct list *cur = head;
    while (cur->next) {
        printf("%d ", cur->number);
        cur = cur->next;
    }
    printf("%d ", cur->number);
    printf("\n");
}

void draw_card(struct list *head, int m);

int main() {
    int n, m, a;
    struct list head;
    head.next = NULL;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        add_node(&head, i + 1);
    }
    draw_card(&head, m);
    return 0;
}

void draw_card(struct list *head, int m) {
    int drawed_card, moved_card;
    head = head->next;
    for (int i = 0; i < m; i++) {
        printf("%d ", head->number);
        if (head->next == NULL) break;
        head = delete_node(head, head->number);
        if (head->next != NULL) {
            moved_card = head->number;
            head = delete_node(head, moved_card);
            add_node(head, moved_card);
        }
    }
}
