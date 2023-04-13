#include <stdio.h>
#include <stdlib.h>

int *page_table;
int *page_table_last_use;
int page_table_size;
int page_table_capacity;

void initialize_page_table() {
  page_table = (int *)malloc(page_table_capacity * sizeof(int));
  page_table_last_use = (int *)malloc(page_table_capacity * sizeof(int));
  for (int i = 0; i < page_table_capacity; i++) {
    page_table[i] = -1;          // -1 means the page is empty
    page_table_last_use[i] = -1; // -1 means the page has not been used yet
  }
}

int is_page_in_table(int page) {
  for (int i = 0; i < page_table_capacity; i++)
    if (page_table[i] == page)
      return 1;
  return 0;
}

int find_lru_page() {
  int lru_page = -1, lru_time = -1;
  for (int i = 0; i < page_table_capacity; i++) {
    if (page_table_last_use[i] < lru_time || lru_time == -1) {
      lru_page = i;
      lru_time = page_table_last_use[i];
    }
  }
  return lru_page;
}

void add_page_to_table(int page, int time) {
  int lru_page = find_lru_page();
  page_table[lru_page] = page;
  page_table_last_use[lru_page] = time;
}

// Simulate the LRU page replacement algorithm
int simulate_lru(int *pages, int num_pages) {
  int page_faults = 0, time = 0;
  for (int i = 0; i < num_pages; i++) {
    int page = pages[i];
    if (!is_page_in_table(page)) {
      add_page_to_table(page, time);
      page_faults++;
    } else
      for (int j = 0; j < page_table_capacity; j++)
        if (page_table[j] == page) {
          page_table_last_use[j] = time;
          break;
        }

    time++;
  }
  return page_faults;
}
