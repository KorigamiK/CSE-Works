/**
 * CPU Scheduling - Shortest Job First (SJF)
 */

#include <stdio.h>

void swap(int *x, int *y) {
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

int main() {
  int n, i, j, temp, total = 0, pos, avg_wait, avg_turnaround;
  int bt[20], p[20], wt[20], tat[20];

  printf("Enter number of process: ");
  scanf("%d", &n);

  printf("Enter Burst Time:\n");
  for (i = 0; i < n; i++) {
    printf("P[%d]: ", i + 1);
    scanf("%d", &bt[i]);
    p[i] = i + 1; // contains process number
  }

  // sorting burst time in ascending order using selection sort
  for (i = 0; i < n; i++) {
    pos = i;
    for (j = i + 1; j < n; j++) {
      if (bt[j] < bt[pos])
        pos = j;
    }

    swap(&bt[i], &bt[pos]);
    swap(&p[i], &p[pos]);
  }

  wt[0] = 0; // waiting time for first process is zero

  // calculate waiting time
  for (i = 1; i < n; i++) {
    wt[i] = 0;
    for (j = 0; j < i; j++)
      wt[i] += bt[j];

    total += wt[i];
  }

  avg_wait = total / n; // average waiting time

  printf("Process\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
  total = 0;
  for (i = 0; i < n; i++) {
    tat[i] = bt[i] + wt[i]; // calculate turnaround time
    total += tat[i];
    printf("%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
  }

  avg_turnaround = total / n; // average turnaround time
  printf("Average Waiting Time: %d\n", avg_wait);
  printf("Average Turnaround Time: %d", avg_turnaround);

  return 0;
}
