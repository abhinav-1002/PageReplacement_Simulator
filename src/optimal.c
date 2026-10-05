#include <stdio.h>
#include "optimal.h"

void optimal(int pages[], int pageCount, int frameCount) {
    int frames[frameCount];

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
            int replacementIndex = -1;

            // First look for an empty frame.
            
            for (int j = 0; j < frameCount; j++) {
                if (frames[j] == -1) {
                    replacementIndex = j;
                    break;
                }
            }

            // If all frames are occupied find the page whose next use is farthest

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
    }
}