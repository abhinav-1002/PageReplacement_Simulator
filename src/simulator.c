#include <stdio.h>
#include "simulator.h"

void displayComparison(
    Statistics fifoStats,
    Statistics lruStats,
    Statistics optimalStats,
    int totalPages
)
{
    double fifoHitRate = ((double)fifoStats.hits / totalPages) * 100.0;
    double fifoFaultRate = ((double)fifoStats.faults / totalPages) * 100.0;
    double lruHitRate = ((double)lruStats.hits / totalPages) * 100.0;

    double lruFaultRate = ((double)lruStats.faults / totalPages) * 100.0;
    double optimalHitRate = ((double)optimalStats.hits / totalPages) * 100.0;
    double optimalFaultRate = ((double)optimalStats.faults / totalPages) * 100.0;

    printf("\n================ ALGORITHM COMPARISON ================\n");

    printf("%-12s %-10s %-10s %-12s %-12s\n",
           "Algorithm",
           "Hits",
           "Faults",
           "Hit Rate",
           "Fault Rate");

    printf("-----------------------------------------------------------------\n");

    printf("%-12s %-10d %-10d %.2f%%       %.2f%%\n",
           "FIFO",
           fifoStats.hits,
           fifoStats.faults,
           fifoHitRate,
           fifoFaultRate);

    printf("%-12s %-10d %-10d %.2f%%       %.2f%%\n",
           "LRU",
           lruStats.hits,
           lruStats.faults,
           lruHitRate,
           lruFaultRate);

    printf("%-12s %-10d %-10d %.2f%%       %.2f%%\n",
           "Optimal",
           optimalStats.hits,
           optimalStats.faults,
           optimalHitRate,
           optimalFaultRate);

    printf("-----------------------------------------------------------------\n");

    printf("Total References: %d\n", totalPages);

    // Determine the best algorithm based on minimum number of page faults

    int minimumFaults = fifoStats.faults;

    if (lruStats.faults < minimumFaults) {
       minimumFaults = lruStats.faults;
    }
    if (optimalStats.faults < minimumFaults) {
       minimumFaults = optimalStats.faults;
    }

    printf("\nBest Algorithm: ");

    if (fifoStats.faults == minimumFaults && lruStats.faults == minimumFaults && optimalStats.faults == minimumFaults) {
       printf("All algorithms performed equally");
    }
    else if (fifoStats.faults == minimumFaults && lruStats.faults == minimumFaults) {
       printf("FIFO and LRU");
    }
    else if (fifoStats.faults == minimumFaults && optimalStats.faults == minimumFaults) {
       printf("FIFO and Optimal");
    }
    else if (lruStats.faults == minimumFaults && optimalStats.faults == minimumFaults) {
       printf("LRU and Optimal");
    }
    else if (fifoStats.faults == minimumFaults) {
       printf("FIFO");
    }
    else if (lruStats.faults == minimumFaults) {
       printf("LRU");
    }
    else {
       printf("Optimal");
    }

    printf("\nReason: Minimum number of page faults (%d)\n", minimumFaults);
}