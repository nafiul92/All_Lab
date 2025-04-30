#include <stdio.h>

#define MAX_PAGES 100
#define MAX_FRAMES 10

int main() {
    int n_pages, n_frames;
    int pages[MAX_PAGES], frames[MAX_FRAMES];
    int i, j, pointer = 0, page_faults = 0;
    int hit;

    printf("Enter number of pages: ");
    scanf("%d", &n_pages);

    printf("Enter page reference sequence:\n");
    for (i = 0; i < n_pages; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &n_frames);

    for (i = 0; i < n_frames; i++) {
        frames[i] = -1;  /* initialize empty frames */
    }

    printf("\nFIFO Page Replacement:\n");
    printf("Reference | Frames\n");
    printf("----------+---------------------\n");

    for (i = 0; i < n_pages; i++) {
        hit = 0;
        for (j = 0; j < n_frames; j++) {
            if (frames[j] == pages[i]) {
                hit = 1;
                break;
            }
        }

        if (!hit) {
            frames[pointer] = pages[i];
            pointer = (pointer + 1) % n_frames;
            page_faults++;
        }

        printf("   %3d    |", pages[i]);
        for (j = 0; j < n_frames; j++) {
            if (frames[j] == -1)
                printf("   -");
            else
                printf(" %3d", frames[j]);
        }
        if (hit)
            printf("  (HIT)\n");
        else
            printf("  (FAULT)\n");
    }

    printf("----------------------------------\n");
    printf("Total Page Faults: %d\n", page_faults);

    return 0;
}
