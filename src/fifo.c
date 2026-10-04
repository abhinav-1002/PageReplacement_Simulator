#include <stdio.h>
#include "fifo.h"

void fifo(int pages[], int pageCount, int frameCount) {
    int frames[frameCount];
    int nextReplacement = 0;

    for (int i = 0; i < frameCount; i++) {
        frames[i] = -1;
    }

    for (int i = 0; i < pageCount; i++) {
        int page = pages[i];
        int pageFound = 0;

        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == page) {
                pageFound = 1;
                break;
            }
        }

        if (!pageFound) {
            frames[nextReplacement] = page;
            nextReplacement = (nextReplacement + 1) % frameCount;
        }
    }
}