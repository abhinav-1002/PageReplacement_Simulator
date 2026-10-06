#ifndef SIMULATOR_H
#define SIMULATOR_H

typedef struct
{
    int hits;
    int faults;
} Statistics;

void displayComparison(
    Statistics fifoStats,
    Statistics lruStats,
    Statistics optimalStats,
    int totalPages
);

#endif