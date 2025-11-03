#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

int isCircular(struct Node *head) {
    if (head == NULL)
        return 0;

    struct Node *temp = head->next;

    while (temp != NULL && temp != head) {
        temp = temp->next;
    }

    return (temp == head);
}
