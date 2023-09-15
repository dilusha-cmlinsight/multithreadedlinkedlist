#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#include "linked_list.h"

#include "serial.h"
#include "global.h"
#include "mutex.h"
#include "rw_lock.h"
int main()
{
    printf("%s\n", "Hello");
    unsigned long serial_runtime, mut_t1_runtime, mut_t2_runtime, mut_t4_runtime, mut_t8_runtime, rw_t1_runtime, rw_t2_runtime, rw_t4_runtime, rw_t8_runtime;
    const int N = 385;
    /*===================
    |       case 1      |
    ====================*/
    int case_num = 1;
    FILE *fp;
    fp = fopen("output/Case_1.csv", "w+");

    fprintf(fp, "Serial, mut_t1, mut_t2, mut_t4, mut_t8, rw_t1, rw_t2, rw_t4, rw_t8\n");
    for (size_t i = 0; i < N; i++)
    {
        serial_runtime = test_serial_run(case_num);
        mut_t1_runtime = test_mutex_run(case_num, 1);
        mut_t2_runtime = test_mutex_run(case_num, 2);
        mut_t4_runtime = test_mutex_run(case_num, 4);
        mut_t8_runtime = test_mutex_run(case_num, 8);
        rw_t1_runtime = test_rw_lock_run(case_num, 1);
        rw_t2_runtime = test_rw_lock_run(case_num, 2);
        rw_t4_runtime = test_rw_lock_run(case_num, 4);
        rw_t8_runtime = test_rw_lock_run(case_num, 8);
        fprintf(fp, "%lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu\n", serial_runtime, mut_t1_runtime, mut_t2_runtime, mut_t4_runtime, mut_t8_runtime, rw_t1_runtime, rw_t2_runtime, rw_t4_runtime, rw_t8_runtime);
    }
    fclose(fp);

    /*===================
    |       case 2      |
    ====================*/
    case_num = 2;
    fp = fopen("output/Case_2.csv", "w+");
    fprintf(fp, "Serial, mut_t1, mut_t2, mut_t4, mut_t8, rw_t1, rw_t2, rw_t4, rw_t8\n");
    for (size_t i = 0; i < N; i++)
    {
        serial_runtime = test_serial_run(case_num);
        mut_t1_runtime = test_mutex_run(case_num, 1);
        mut_t2_runtime = test_mutex_run(case_num, 2);
        mut_t4_runtime = test_mutex_run(case_num, 4);
        mut_t8_runtime = test_mutex_run(case_num, 8);
        rw_t1_runtime = test_rw_lock_run(case_num, 1);
        rw_t2_runtime = test_rw_lock_run(case_num, 2);
        rw_t4_runtime = test_rw_lock_run(case_num, 4);
        rw_t8_runtime = test_rw_lock_run(case_num, 8);
        fprintf(fp, "%lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu\n", serial_runtime, mut_t1_runtime, mut_t2_runtime, mut_t4_runtime, mut_t8_runtime, rw_t1_runtime, rw_t2_runtime, rw_t4_runtime, rw_t8_runtime);
    }
    fclose(fp);

    /*===================
    |       case 3      |
    ====================*/
    case_num = 3;
    fp = fopen("output/Case_3.csv", "w+");
    fprintf(fp, "Serial, mut_t1, mut_t2, mut_t4, mut_t8, rw_t1, rw_t2, rw_t4, rw_t8\n");
    for (size_t i = 0; i < N; i++)
    {
        serial_runtime = test_serial_run(case_num);
        mut_t1_runtime = test_mutex_run(case_num, 1);
        mut_t2_runtime = test_mutex_run(case_num, 2);
        mut_t4_runtime = test_mutex_run(case_num, 4);
        mut_t8_runtime = test_mutex_run(case_num, 8);
        rw_t1_runtime = test_rw_lock_run(case_num, 1);
        rw_t2_runtime = test_rw_lock_run(case_num, 2);
        rw_t4_runtime = test_rw_lock_run(case_num, 4);
        rw_t8_runtime = test_rw_lock_run(case_num, 8);
        fprintf(fp, "%lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu\n", serial_runtime, mut_t1_runtime, mut_t2_runtime, mut_t4_runtime, mut_t8_runtime, rw_t1_runtime, rw_t2_runtime, rw_t4_runtime, rw_t8_runtime);
    }
    fclose(fp);

    /* unsigned long rw_t1_runtime, rw_t2_runtime, rw_t4_runtime, rw_t8_runtime;
    const int N = 385;
    int case_num = 3;

    printf("Case Number %d\n\n", case_num);

    rw_t1_runtime = test_rw_lock_run(case_num, 1);
    rw_t2_runtime = test_rw_lock_run(case_num, 2);
    rw_t4_runtime = test_rw_lock_run(case_num, 4);
    rw_t8_runtime = test_rw_lock_run(case_num, 8);
    printf("thread 1: %lu, Thread 2: %lu, Thread 4: %lu, Thread 8: %lu\n", rw_t1_runtime, rw_t2_runtime, rw_t4_runtime, rw_t8_runtime); */

    return 0;
}