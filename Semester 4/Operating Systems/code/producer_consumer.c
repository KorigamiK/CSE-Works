/**
 * Producer-Consumer Problem
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 3

int buffer[BUFFER_SIZE];
int mutex = 1;
int full = 0;

int empty = BUFFER_SIZE;

int in = 0;
int out = 0;

void *producer(void *pno) {
  int item;
  for (int i = 0; i < 3; i++) {
    item = rand(); // Produce an random item
    while (mutex <= 0)
      ; // Do nothing
    mutex--;
    full++;
    empty--;
    buffer[in] = item;
    printf("Producer %d: Insert Item %d at %d\n", *((int *)pno), buffer[in], in);
    in = (in + 1) % BUFFER_SIZE;
    mutex++;
  }
  return NULL;
}

void *consumer(void *cno) {
  for (int i = 0; i < 3; i++) {
    while (mutex <= 0)
      ; // Do nothing
    mutex--;
    full--;
    empty++;
    int item = buffer[out];
    printf("Consumer %d: Remove Item %d from %d\n", *((int *)cno), item, out);
    out = (out + 1) % BUFFER_SIZE;
    mutex++;
  }
  return NULL;
}

int main() {
  pthread_t pro[3], con[3];
  pthread_attr_t attr;
  pthread_attr_init(&attr);

  // Just used for numbering the producer and consumer
  int a[3] = {1, 2, 3}; // A vector of item

  // Create the producer threads
  for (int i = 0; i < 3; i++)
    pthread_create(&pro[i], &attr, producer, &a[i]);
  
  // Create the consumer threads
  for (int i = 0; i < 3; i++) 
    pthread_create(&con[i], &attr, consumer, &a[i]);
  

  for (int i = 0; i < 3; i++) 
    // Wait for the producer thread to exit
    pthread_join(pro[i], NULL);
  
  for (int i = 0; i < 3; i++) 
    // Wait for the consumer thread to exit
    pthread_join(con[i], NULL);

  return 0;
}
