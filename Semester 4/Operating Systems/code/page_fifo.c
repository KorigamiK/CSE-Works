#include <stdio.h>
#include <stdlib.h>

// Define the page table as a circular buffer using an array
int *page_table;
int page_table_size;
int page_table_capacity;
int head;

void initialize_page_table() {
  page_table = (int *)malloc(page_table_capacity * sizeof(int));
  for (int i = 0; i < page_table_capacity; i++)
    page_table[i] = -1; // -1 means the page is empty
  head = 0;
}

int is_page_in_table(int page) {
  for (int i = 0; i < page_table_capacity; i++)
    if (page_table[i] == page)
      return 1;
  return 0;
}

void add_page_to_table(int page) {
  page_table[head] = page;
  head = (head + 1) % page_table_capacity;
}

// Function to simulate the FIFO page replacement algorithm
int simulate_fifo(int *pages, int num_pages) {
  int page_faults = 0;
  for (int i = 0; i < num_pages; i++) {
    int page = pages[i];
    if (!is_page_in_table(page)) {
      add_page_to_table(page);
      page_faults++;
    }
  }
  return page_faults;
}

int main() {
  int num_pages, page_capacity;
  printf("Enter the number of pages: ");
  scanf("%d", &num_pages);
  printf("Enter the capacity of the page table: ");
  scanf("%d", &page_capacity);
  page_table_size = 0;
  page_table_capacity = page_capacity;
  initialize_page_table();
  int *pages = (int *)malloc(num_pages * sizeof(int));
  printf("Enter the page references:\n");
  for (int i = 0; i < num_pages; i++)
    scanf("%d", &pages[i]);
  int page_faults = simulate_fifo(pages, num_pages);
  printf("Number of page faults: %d\n", page_faults);
  free(page_table);
  free(pages);
  return 0;
}
