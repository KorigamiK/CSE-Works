/**
 * @file disk_fcfs.c
 * @brief Disk scheduling algorithm FCFS
 */

#include <stdio.h>
#include <stdlib.h>

void FCFS(int arr[], int head, int size) {
  int seek_count = 0;
  int cur_track, distance;

  for (int i = 0; i < size; i++) {
    cur_track = arr[i];
    distance = abs(head - cur_track); // calculate absolute distance
    seek_count += distance;           // increase the total count
    head = cur_track;                 // accessed track is now new head
  }
  printf("Total number of seek operations: %d\n", seek_count);
  printf("Seek Sequence is ");       // Seek sequence would be the same as request array sequence
  for (int i = 0; i < size; i++)
    printf("-> %d ", arr[i]);
}

int main() {
  int size;
  printf("Enter the size of the queue: ");
  scanf("%d", &size);
  int arr[size];
  printf("Enter the queue: ");
  for (int i = 0; i < size; i++)
    scanf("%d", &arr[i]);
  int head;
  printf("Enter the head: ");
  scanf("%d", &head);
  FCFS(arr, head, size);
  return 0;
}

