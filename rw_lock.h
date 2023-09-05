#ifndef RW_LOCK_H
#define RW_LOCK_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <sys/time.h>

#include "linked_list.h"
#include "global.h"

struct rw_lock_data
{
    pthread_rwlock_t rwlock;
    list_node_s *head;

    int thread_count; // Number of threads 
    int m; //Number of operations
    float mmem;
    float mins;
    float mdel;

    // Fractions of each operation
    int Mem,Ins,Del;

    int insOps;
    int memOps;
    int delOps;
    int totOps;

    int rank;
};
typedef struct rw_lock_data rw_lock_data;

unsigned long test_rw_lock_run(int case_num, int thread_count);

#endif