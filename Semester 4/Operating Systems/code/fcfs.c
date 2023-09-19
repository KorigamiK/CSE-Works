/**
 * Implementation of FCFS scheduling algorithm
 */
#include <stdio.h>

void find_waiting_time(int processes[], int n, int bt[], int wt[]) {
  wt[0] = 0;
  for (int i = 1; i < n; i++) {
    wt[i] = bt[i - 1] + wt[i - 1];
  }
}

void find_turn_around_time(int processes[], int n, int bt[], int wt[],
                           int tat[]) {
  for (int i = 0; i < n; i++)
    tat[i] = bt[i] + wt[i];
}

void find_avg_time(int processes[], int n, int bt[]) {
  int wt[n], tat[n], total_wt = 0, total_tat = 0;
  find_waiting_time(processes, n, bt, wt);
  find_turn_around_time(processes, n, bt, wt, tat);
  printf("Processes  Burst Time   Waiting Time Turn Around Time\n");
  for (int i = 0; i < n; i++) {
    total_wt = total_wt + wt[i];
    total_tat = total_tat + tat[i];
    printf("%d\t   ", i + 1);
    printf("%d\t\t", bt[i]);
    printf("%d\t\t", wt[i]);
    printf("%d\t\n", tat[i]);
  }
  printf("Average waiting time = %f\n", (float)total_wt / (float)n);
  printf("Average turn around time = %f", (float)total_tat / (float)n);
}

int main() {
  int processes[] = {1, 2, 3};
  int n = sizeof processes / sizeof processes[0];
  int burst_time[] = {10, 5, 8};
  find_avg_time(processes, n, burst_time);
  return 0;
}
