#include <stdio.h>
#include "optimal.h"

void optimal(int pages[], int pageCount, int frameCount) {
    int frames[frameCount];
    int pageHits = 0;
    int pageFaults = 0;

    for (int i = 0; i < frameCount; i++) {
        frames[i] = -1;
    }

    printf("\n=============== OPTIMAL PAGE REPLACEMENT ===============\n");
    printf("Page\t");

    for (int i = 0; i < frameCount; i++) {
        printf("F%d\t", i + 1);
    }

    printf("Result\n");
    printf("---------------------------------------------------------\n");

    for (int i = 0; i < pageCount; i++) {
        int page = pages[i];
        int pageFound = 0;
        int replacementIndex = -1;

        // Check whether the page is already present.

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


            // First use an empty frame if available.

            for (int j = 0; j < frameCount; j++) {
                if (frames[j] == -1) {
                    replacementIndex = j;
                    break;
                }
            }

            // If all frames are full find the page that will be used farthest

            if (replacementIndex == -1) {
                int farthestUse = -1;

                for (int j = 0; j < frameCount; j++) {
                    int nextUse = pageCount;

                    for (int k = i + 1; k < pageCount; k++) {
                        if (pages[k] == frames[j]) {
                            nextUse = k;
                            break;
                        }
                    }

                    if (nextUse > farthestUse) {
                        farthestUse = nextUse;
                        replacementIndex = j;
                    }
                }
            }

            frames[replacementIndex] = page;
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

    printf("---------------------------------------------------------\n");
    printf("Page Hits   : %d\n", pageHits);
    printf("Page Faults : %d\n", pageFaults);
}