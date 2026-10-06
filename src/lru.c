#include <stdio.h>
#include "lru.h"

Statistics lru(int pages[], int pageCount, int frameCount) {
    Statistics stats;
    stats.hits = 0;
    stats.faults = 0;

    int frames[frameCount];
    int lastUsed[frameCount];
    int time = 0;

    for (int i = 0; i < frameCount; i++) {
        frames[i] = -1;
        lastUsed[i] = -1;
    }

    printf("\n================ LRU PAGE REPLACEMENT ================\n");
    printf("Page\t");

    for (int i = 0; i < frameCount; i++) {
        printf("F%d\t", i + 1);
    }

    printf("Result\n");
    printf("-------------------------------------------------------\n");

    for (int i = 0; i < pageCount; i++) {
        int page = pages[i];
        int pageFound = 0;
        int replacementIndex = -1;

        time++;

        // Check whether the page is already present.
        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == page) {
                pageFound = 1;
                lastUsed[j] = time;
                break;
            }
        }

        
        //  Page fault: find an empty frame first.

        if (!pageFound) {
            stats.faults++;

            for (int j = 0; j < frameCount; j++) {
                if (frames[j] == -1) {
                    replacementIndex = j;
                    break;
                }
            }
        // If no empty frame exists, find the least recently used page.

            if (replacementIndex == -1) {
                replacementIndex = 0;

                for (int j = 1; j < frameCount; j++) {
                    if (lastUsed[j] < lastUsed[replacementIndex]) {
                        replacementIndex = j;
                    }
                }
            }

            frames[replacementIndex] = page;
            lastUsed[replacementIndex] = time;
        }
        else {
            stats.hits++;
        }

        
        // Display current frame state.
        printf("%d\t", page);

        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == -1) {
                printf("-\t");
            }
            else {
                printf("%d\t", frames[j]);
            }
        }

        if (pageFound) {
            printf("Hit\n");
        }
        else {
            printf("Fault\n");
        }
    }

    printf("-------------------------------------------------------\n");
    printf("Page Hits   : %d\n", stats.hits);
    printf("Page Faults : %d\n", stats.faults);

    return stats;
}