#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int thread_count;

void *Hello(void *rank);

int main(int argc, char *argv[])
{
  long thread;

  pthread_t *thread_handles;

  thread_count = strtol("10", NULL, 10);
  thread_handles = malloc(thread_count * sizeof(pthread_t));

  for (thread = 0; thread < thread_count; thread++)
  {
    pthread_create(&thread_handles[thread], NULL, Hello, (void *)thread);
  }

  printf("Hello from the main thread \n");
  for (thread = 0; thread < thread_count; thread++)
  {
    pthread_join(thread_handles[thread], NULL);
  }

  free(thread_handles);


  printf("This is exceced after all the threads joined with the main thread");
  return 0;
}

void *Hello(void *rank)
{
  long my_rank = (long) rank;
  printf("Hello is calling %ld of %d  \n",my_rank,thread_count);
  return NULL;
}
