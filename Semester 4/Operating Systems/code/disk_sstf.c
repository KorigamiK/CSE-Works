/**
* @file disk_sstf.c
* @brief Implementation of the SSTF disk scheduling algorithm.
*/

#include <stdio.h>
#include <stdlib.h>

int disk_sstf(disk_request_t *requests, size_t num_requests, size_t initial_head_pos, size_t *head_movement)
{
    if (requests == NULL || num_requests == 0 || head_movement == NULL)
        return -1;

    // Copy the requests array so that we can modify it
    disk_request_t *requests_copy = (disk_request_t *)malloc(sizeof(disk_request_t) * num_requests);
    for (size_t i = 0; i < num_requests; i++)
        requests_copy[i] = requests[i];
    size_t head_pos = initial_head_pos; // The head starts at the initial position
    *head_movement = 0;

    // Loop through all the requests
    for (size_t i = 0; i < num_requests; i++)
    {
        size_t closest_request = 0; // Find the closest request
        size_t min_distance = abs(requests_copy[0].track - head_pos);
        for (size_t j = 1; j < num_requests; j++)
        {
            size_t distance = abs(requests_copy[j].track - head_pos);
            if (distance < min_distance)
            {
                closest_request = j;
                min_distance = distance;
            }
        }

        // Process the closest request
        *head_movement += min_distance;
        head_pos = requests_copy[closest_request].track;

        // Remove the request from the array
        for (size_t j = closest_request; j < num_requests - 1; j++)
            requests_copy[j] = requests_copy[j + 1];
    }

    free(requests_copy);
    return 0;
}
