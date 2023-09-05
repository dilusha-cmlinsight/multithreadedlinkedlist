#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <sys/time.h>

#include "global.h"
#include "linked_list.h"
#include "serial.h"

unsigned long test_serial_run(int case_num)
{
    list_node_s *head = NULL;
    float mmem;
    float mins;
    float mdel;

    int m = 10000; // number of operations

    switch (case_num)
    {
    case 1:
    {
        mmem = 0.99;
        mins = 0.005;
        mdel = 0.005;
        break;
    }
    case 2:
    {
        mmem = 0.9;
        mins = 0.05;
        mdel = 0.05;
        break;
    }
    case 3:
    {
        mmem = 0.5;
        mins = 0.25;
        mdel = 0.25;
        break;
    }
    default:
    {
        mmem = 0.99;
        mins = 0.005;
        mdel = 0.005;
        break;
    }
    }

    // Fractions of each operations
    int Mem = (int)(m * mmem);
    int Ins = (int)(m * mins);
    int Del = (int)(m * mdel);

    int insOps = 0;
    int memOps = 0;
    int delOps = 0;
    int totOps = 0;

    int n = 1000; // Number of initial elements of the linked list
    int count = 0;

    // Generate a linked list with n random numbers
    srand(time(0));
    while (count < n)
    {
        Insert(rand() % MAX, &head);
        count++;
    }
    struct timeval stop;
    struct timeval start;
    gettimeofday(&start, NULL);

    while (totOps < m)
    {

        int rand_value = rand() % MAX;

        int op = rand() % 3;

        if (op == 0 && insOps < Ins)
        {
            short res = Insert(rand_value, &head);
            insOps++;
            totOps++;
            // printf("Operation %d , Insert %d %d\n", totOps, rand_value, res);
        }
        else if (op == 1 && delOps < Del)
        {
            short res = Delete(rand_value, &head);
            delOps++;
            totOps++;
            // printf("Operation %d , Delete %d %d\n", totOps, rand_value, res);
        }
        else if (memOps < Mem)
        {
            short res = Member(rand_value, &head);
            memOps++;
            totOps++;
            // printf("Operation %d , Search %d %d\n", totOps, rand_value, res);
        }
    }
    gettimeofday(&stop, NULL);
    unsigned long time;
    time = (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec;
    // printf("took %lu us\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);
    // Print(&head);
    destructor(&head);
    printf("Serial ran!\n");
    return time;
}