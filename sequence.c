// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>

// struct list_node_s
// {
//     int data;
//     struct list_node_s *next;
// };

// pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
// struct OperationArgs
// {
//     int value;
//     struct list_node_s **head_pp;
// };
// int Member(int value, struct list_node_s **head_pp)
// {
//     struct list_node_s *current_p = *head_pp;
//     printf("\n %d <-> \n", current_p->data);
//     while (current_p != NULL && current_p->data < value)
//         current_p = current_p->next;
//     if (current_p == NULL || current_p->data > value)
//         return 0;
//     else
//         return 1;
// }

// int Insert(int value, struct list_node_s **head_pp)
// {
//     struct list_node_s *curr_p = *head_pp;
//     struct list_node_s *pred_p = NULL;
//     struct list_node_s *temp_p;

//     while (curr_p != NULL && curr_p->data <= value)
//     {
//         pred_p = curr_p;
//         curr_p = curr_p->next;
//     }

//     if (curr_p == NULL || curr_p->data > value)
//     {

//         temp_p = malloc(sizeof(struct list_node_s));
//         temp_p->data = value;
//         temp_p->next = curr_p;
//         if (pred_p == NULL)
//         {
//             *head_pp = temp_p;
//         }
//         else
//         {
//             pred_p->next = temp_p;
//         }

//         // printf("%d\n", (*head__pp)->data);
//         return 1;
//     }
//     else
//     {
//         printf("%s", "\nThere is a number");
//         return 0;
//     }
// }

// int Delete(int value, struct list_node_s **head_pp)
// {
//     struct list_node_s *curr_p = *head_pp;
//     struct list_node_s *pred_p = NULL;

//     while (curr_p != NULL && curr_p->data < value)
//     {
//         pred_p = curr_p;
//         curr_p = curr_p->next;
//     }

//     if (curr_p != NULL && curr_p->data == value)
//     {

//         if (pred_p == NULL)
//         {
//             *head_pp = curr_p->next;
//             free(curr_p);
//         }
//         else
//         {
//             pred_p->next = curr_p->next;
//             free(curr_p);
//         }
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// void *InsertThread(void *args)
// {
//     struct OperationArgs *argsData = (struct OperationArgs *)args;
//     pthread_mutex_lock(&mutex);
//     Insert(argsData->value, argsData->head_pp);
//     pthread_mutex_unlock(&mutex);
//     return NULL;
// }

// void *DeleteThread(void *args)
// {
//     struct OperationArgs *argsData = (struct OperationArgs *)args;
//     pthread_mutex_lock(&mutex);
//     Delete(argsData->value, argsData->head_pp);
//     pthread_mutex_unlock(&mutex);
//     return NULL;
// }
// void *MemberThread(void *args)
// {
//     struct OperationArgs *argsData = (struct OperationArgs *)args;
//     pthread_mutex_lock(&mutex);
//     Member(argsData->value, argsData->head_pp);
//     pthread_mutex_unlock(&mutex);
//     return NULL;
// }
// int main()
// {
//     struct list_node_s *head = NULL;
//     pthread_mutex_init(&mutex, NULL);
//     long thread;

//     pthread_t *thread_handles;

//     int thread_count = 4;
//     thread_handles = malloc(thread_count * sizeof(pthread_t));

//     for (thread = 0; thread < thread_count; thread++)
//     {
//         struct OperationArgs insertData;
//         insertData.value = thread;
//         insertData.head_pp = &head;
//         pthread_create(&thread_handles[thread], NULL, (void *)InsertThread, (void *)&insertData);
//     }

//     for (thread = 0; thread < thread_count; thread++)
//     {
//         pthread_join(thread_handles[thread], NULL);
//     }

//     free(thread_handles);

//     struct list_node_s *current = head;
//     while (current != NULL)
//     {
//         printf("%d -> ", current->data);
//         current = current->next;
//     }
// }