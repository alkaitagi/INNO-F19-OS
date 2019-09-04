#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

void print_list(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\r\n");
}

// return head pointer
Node *insert_node(Node *head, int index, int value) // index after which to insert
{
    Node *r_head = head;

    Node *new = (Node *)malloc(sizeof(struct Node));
    new->value = value;
    new->next = NULL;

    if (head == NULL)
        r_head = new;
    if (head != NULL) // if list is not empty, insert after indexed element
    {
        for (int i = 0; i < index && head->next != NULL; i++) // stop if index is larger than list size
            head = head->next;

        new->next = head->next;
        head->next = new;
    }

    // return head element;
    return r_head;
}

// return head pointer
Node *delete_node(Node *head, int index) // index which to delete
{
    Node *r_head = head;
    if (index == 0)
    {
        r_head = head->next;
        free(head);
    }
    else
    {
        for (int i = 1; i < index && head->next != NULL; i++) // stop if index is larger than list size
            head = head->next;

        Node *target = head->next;
        Node *next = target->next;
        head->next = next;
        free(target);
    }
    return r_head;
}

int main()
{
    Node *head = insert_node(NULL, 0, 6);
    head = insert_node(head, 0, 9);
    head = insert_node(head, 0, 7);
    // [0]6 -> [1]7 -> [2]9
    head = insert_node(head, 2, 10);
    head = insert_node(head, 1, 8);
    // [0]6 -> [1]7 -> [2]8 -> [3]9 -> [4]10
    head = delete_node(head, 3);
    head = delete_node(head, 1);
    // [0]6 -> [1]8 -> [2]10
    head = delete_node(head, 0);
    // [0]8 -> [1]10
    print_list(head);
    return 0;
}
