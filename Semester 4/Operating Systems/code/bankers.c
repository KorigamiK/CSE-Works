/**
 * @file bankers.c
 * @brief Banker's Algorithm
 * */
#include <stdio.h>

int main() {
  // Number of processes and resources
  int n = 5, m = 3;

  // Allocation and maximum matrices, and available resources vector
  int alloc[5][3] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
  int max[5][3] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
  int avail[3] = {3, 3, 2};

  // Initialization
  int f[n], ans[n], ind = 0;
  for (int k = 0; k < n; k++) f[k] = 0;
  int need[n][m];
  
  for (int i = 0; i < n; i++) 
    for (int j = 0; j < m; j++) 
      need[i][j] = max[i][j] - alloc[i][j];

  // Banker's algorithm
  for (int k = 0; k < 5; k++) {
    for (int i = 0; i < n; i++) {
      // Check if process i can be allocated resources
      if (f[i] == 0 && need[i][0] <= avail[0] && need[i][1] <= avail[1] && need[i][2] <= avail[2]) {
        // Add process i to the safe sequence and update available resources
        ans[ind++] = i;
        for (int y = 0; y < m; y++) avail[y] += alloc[i][y];
        f[i] = 1;
      }
    }
  }

  // Print the safe sequence
  printf("Following is the SAFE Sequence\n");
  for (int i = 0; i < n - 1; i++) printf(" P%d ->", ans[i]);
  printf(" P%d", ans[n - 1]);

  return 0;
}
