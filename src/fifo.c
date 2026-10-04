#include <stdio.h>
#include "fifo.h"

void fifo(int pages[], int pageCount, int frameCount) {
    int frames[frameCount];
    int nextReplacement = 0;
    int pageHits = 0;
    int pageFaults = 0;

    for (int i = 0; i < frameCount; i++) {
        frames[i] = -1;
    }

    printf("\n================ FIFO PAGE REPLACEMENT ================\n");
    printf("Page\t");

    for (int i = 0; i < frameCount; i++) {
        printf("F%d\t", i + 1);
    }

    printf("Result\n");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < pageCount; i++) {
        int page = pages[i];
        int pageFound = 0;

        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == page) {
                pageFound = 1;
                break;
            }
        }

        if (pageFound) {
            pageHits++;
        }
        else {
            pageFaults++;
            frames[nextReplacement] = page;
            nextReplacement = (nextReplacement + 1) % frameCount;
        }

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

    printf("--------------------------------------------------------\n");
    printf("Page Hits   : %d\n", pageHits);
    printf("Page Faults : %d\n", pageFaults);
}