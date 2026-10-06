#include <stdio.h>
#include "fifo.h"
#include "lru.h"
#include "optimal.h"
#include "simulator.h"

#define MAX_PAGES 100
#define MAX_FRAMES 20

int readFrames(void) {
    int frames;

    while (1) {
        printf("Enter number of frames (1-%d): ", MAX_FRAMES);

        if (scanf("%d", &frames) == 1 && frames >= 1 && frames <= MAX_FRAMES) {
            return frames;
        }

        printf("Invalid input. Please enter a number between 1 and %d.\n",MAX_FRAMES);

        while (getchar() != '\n');
    }
}

int readPageCount(void) {
    int pageCount;

    while (1) {
        printf("Enter number of pages (1-%d): ", MAX_PAGES);

        if (scanf("%d", &pageCount) == 1 && pageCount >= 1 && pageCount <= MAX_PAGES) {
            return pageCount;
        }

        printf("Invalid input. Please enter a number between 1 and %d.\n",MAX_PAGES);

        while (getchar() != '\n');
    }
}

void readReferenceString(int pages[], int pageCount) {
    printf("Enter reference string:\n");

    for (int i = 0; i < pageCount; i++) {
        while (scanf("%d", &pages[i]) != 1 || pages[i] < 0) {
            printf("Invalid page value. Please enter a non-negative integer: ");

            while (getchar() != '\n');
        }
    }
}

int main(void) {
    int frames;
    int pageCount;
    int pages[MAX_PAGES];

    printf("========================================\n");
    printf("     PAGE REPLACEMENT SIMULATOR\n");
    printf("========================================\n\n");

    frames = readFrames();
    pageCount = readPageCount();
    readReferenceString(pages, pageCount);

    printf("\nInput accepted successfully.\n");
    printf("Number of frames: %d\n", frames);
    printf("Number of pages: %d\n", pageCount);

    Statistics fifoStats;
    Statistics lruStats;
    Statistics optimalStats;

    fifoStats = fifo(pages, pageCount, frames);

    printf("\nRunning LRU...\n");
    lruStats = lru(pages, pageCount, frames);

    printf("\nRunning Optimal...\n");
    optimalStats = optimal(pages, pageCount, frames);

    displayComparison(fifoStats, lruStats, optimalStats, pageCount);

    return 0;
}