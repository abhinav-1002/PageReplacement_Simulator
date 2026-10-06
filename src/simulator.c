#include <stdio.h>
#include "simulator.h"

void displayComparison(Statistics fifoStats, Statistics lruStats, Statistics optimalStats, int totalPages) {
    printf("\n================ ALGORITHM COMPARISON ================\n");

    printf("%-12s %-10s %-10s\n",
           "Algorithm", "Hits", "Faults");

    printf("-------------------------------------------------------\n");

    printf("%-12s %-10d %-10d\n",
           "FIFO",
           fifoStats.hits,
           fifoStats.faults);

    printf("%-12s %-10d %-10d\n",
           "LRU",
           lruStats.hits,
           lruStats.faults);

    printf("%-12s %-10d %-10d\n",
           "Optimal",
           optimalStats.hits,
           optimalStats.faults);

    printf("-------------------------------------------------------\n");

    printf("Total References: %d\n", totalPages);
}