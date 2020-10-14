#ifndef STACK_H
#define STACK_H

#include <stdio.h> 
#include <stdlib.h> 

struct StackNode {
    int data;
    struct StackNode* next;
};

struct StackNode* init(const int data)
{
    struct StackNode* new_node =
        (struct StackNode*)malloc(sizeof(struct StackNode));

    if (new_node == NULL)
    {
        exit(1);
    }
    new_node->next = NULL;
    return new_node;
}

void destroy(struct StackNode* node)
{
    while (node->next != NULL)
    {
        struct StackNode* old_node = node;
        node = node->next;
        free(old_node);
        old_node = NULL;
    }
}

void push(struct StackNode** head, const int data)
{
    struct StackNode* new_node = init(data);
    struct StackNode* last = *head;

    if (*head == NULL)
    {
        *head = new_node;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
}


int pop(struct StackNode** head)
{
    if (*head == NULL)
    {
        printf("%s", "No Head Supplied");
        return 0;
    }

    int data = (*(*head)).data;

    struct StackNode* tmp = *head;

    *head = (*(*head)).next;
    free(tmp);
    return data;
}

#endif