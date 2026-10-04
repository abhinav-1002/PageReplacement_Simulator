#include <stdio.h>
#include "lru.h"

void lru(int pages[], int pageCount, int frameCount) {
    int frames[frameCount];
    int lastUsed[frameCount];
    int time = 0;

    for (int i = 0; i < frameCount; i++) {
        frames[i] = -1;
        lastUsed[i] = -1;
    }

    for (int i = 0; i < pageCount; i++) {
        int page = pages[i];
        int pageFound = 0;

        time++;

        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == page) {
                pageFound = 1;
                lastUsed[j] = time;
                break;
            }
        }

        if (!pageFound) {
            int replacementIndex = -1;

            for (int j = 0; j < frameCount; j++) {
                if (frames[j] == -1) {
                    replacementIndex = j;
                    break;
                }
            }

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
    }
}