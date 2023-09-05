#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "linked_list.h"

int Member(int value, struct list_node_s **head_pp)
{
    struct list_node_s *current_p = *head_pp;
    while (current_p != NULL && current_p->data < value)
        current_p = current_p->next;
    if (current_p == NULL || current_p->data > value)
        return 0;
    else
        return 1;
}

int Insert(int value, struct list_node_s **head_pp)
{
    struct list_node_s *curr_p = *head_pp;
    struct list_node_s *pred_p = NULL;
    struct list_node_s *temp_p;

    while (curr_p != NULL && curr_p->data <= value)
    {
        pred_p = curr_p;
        curr_p = curr_p->next;
    }

    if (curr_p == NULL || curr_p->data > value)
    {

        temp_p = malloc(sizeof(struct list_node_s));
        temp_p->data = value;
        temp_p->next = curr_p;
        if (pred_p == NULL)
        {
            *head_pp = temp_p;
        }
        else
        {
            pred_p->next = temp_p;
        }

        // printf("%d\n", (*head__pp)->data);
        return 1;
    }
    else
    {
        printf("%s", "\nThere is a number");
        return 0;
    }
}

int Delete(int value, struct list_node_s **head_pp)
{
    struct list_node_s *curr_p = *head_pp;
    struct list_node_s *pred_p = NULL;

    while (curr_p != NULL && curr_p->data < value)
    {
        pred_p = curr_p;
        curr_p = curr_p->next;
    }

    if (curr_p != NULL && curr_p->data == value)
    {

        if (pred_p == NULL)
        {
            *head_pp = curr_p->next;
            free(curr_p);
        }
        else
        {
            pred_p->next = curr_p->next;
            free(curr_p);
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

void Print(list_node_s **head_pp)
{
    list_node_s *curr_p = *head_pp;

    while (NULL != curr_p)
    {
        printf("node: %d \n", curr_p->data);
        curr_p = curr_p->next;
    }
}

void destructor(list_node_s **head_p)
{
    list_node_s *curr_p = *head_p;
    list_node_s *temp_p = NULL;

    while (NULL != curr_p)
    {
        temp_p = curr_p;
        curr_p = curr_p->next;
        free(temp_p);
    }
    // printf("Entire linked list destructed!!\n");
}