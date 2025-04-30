#include <stdio.h>

#define MAX_PAGES 100
#define MAX_FRAMES 10

int findLRU(int time[], int n) {
    int i, minimum = time[0], pos = 0;
    for (i = 1; i < n; i++) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int pages[MAX_PAGES], frames[MAX_FRAMES], time[MAX_FRAMES];
    int n_pages, n_frames, counter = 0, page_faults = 0;
    int i, j, pos, hit;

    printf("Enter number of pages: ");
    scanf("%d", &n_pages);

    printf("Enter the page reference sequence:\n");
    for (i = 0; i < n_pages; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &n_frames);

    for (i = 0; i < n_frames; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    printf("\nLRU Page Replacement:\n");
    printf("Reference | Frames\n");
    printf("----------+---------------------\n");

    for (i = 0; i < n_pages; i++) {
        hit = 0;

        for (j = 0; j < n_frames; j++) {
            if (frames[j] == pages[i]) {
                counter++;
                time[j] = counter;
                hit = 1;
                break;
            }
        }

        if (!hit) {
            pos = findLRU(time, n_frames);
            counter++;
            frames[pos] = pages[i];
            time[pos] = counter;
            page_faults++;
        }

        printf("   %3d    |", pages[i]);
        for (j = 0; j < n_frames; j++) {
            if (frames[j] == -1)
                printf("   -");
            else
                printf(" %3d", frames[j]);
        }
        printf("%s\n", hit ? "  (HIT)" : "  (FAULT)");
    }

    printf("----------------------------------\n");
    printf("Total Page Faults: %d\n", page_faults);

    return 0;
}
