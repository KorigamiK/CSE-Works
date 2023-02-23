/**
 * CPU priority scheduler.
 */

#include <stdio.h>

typedef struct Process {
  int pid;
  int priority;
  int burst;
} Process;

int compare(Process a, Process b) { return a.priority < b.priority; }

void sort(Process *p, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (compare(p[j], p[i])) {
        Process temp = p[i];
        p[i] = p[j];
        p[j] = temp;
      }
    }
  }
}

void findWaitingTime(Process proc[], int n, int wt[]) {
  wt[0] = 0;
  for (int i = 1; i < n; i++)
    wt[i] = proc[i - 1].burst + wt[i - 1];
}

void findTurnAroundTime(Process proc[], int n, int wt[], int tat[]) {
  for (int i = 0; i < n; i++)
    tat[i] = proc[i].burst + wt[i];
}

void findavgTime(Process proc[], int n) {
  int wt[n], tat[n], total_wt = 0, total_tat = 0;

  findWaitingTime(proc, n, wt);
  findTurnAroundTime(proc, n, wt, tat);

  printf("Processes Burst time Waiting time Turn around time\n");
  for (int i = 0; i < n; i++) {
    total_wt = total_wt + wt[i];
    total_tat = total_tat + tat[i];
    printf("%d\t\t", proc[i].pid);
    printf("%d\t\t", proc[i].burst);
    printf("%d\t\t", wt[i]);
    printf("%d", tat[i]);
    printf("\n");
  }

  printf("Average waiting time = %f", (float)total_wt / (float)n);
  printf("Average turn around time = %f", (float)total_tat / (float)n);
}

void priorityScheduling(Process proc[], int n) {
  sort(proc, n);
  printf("Order in which processes gets executed\n");
  for (int i = 0; i < n; i++)
    printf("%d ", proc[i].pid);
  printf("\n");
  findavgTime(proc, n);
}

int main() {
  Process proc[] = {{1, 2, 100}, {2, 1, 19}, {3, 1, 27}, {4, 1, 25}};
  int n = sizeof proc / sizeof proc[0];
  priorityScheduling(proc, n);
  return 0;
}
