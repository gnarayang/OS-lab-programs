#include <stdio.h>
#include <stdlib.h>

int numberOfPagesinPT = 0;
int pageTableSize;
int numberOfPages;

//opr specific starts
int *firstUsed;

void prePageProcessing() {
    firstUsed = (int*) malloc(pageTableSize * sizeof(int));
}

void postHit(int positionInPT) {
}

void postPageAppendedToPT() {
}

//assuming page table is full
int replacePageinPT(int *pageTable, int page, int *pageSequence , int positionInPS ) {
    int i, max = 1e9;
    //initialisation
    for(i = 0; i < pageTableSize; i++) {
        firstUsed[i] = max;
    }
    //update firstUsed
    if(pageSequence != NULL)
    for(i = positionInPS + 1; i < numberOfPages; i++) {
        int page = pageSequence[i];
        int j;
        for(j = 0; j < pageTableSize; j++) {
            if(pageTable[j] == page && firstUsed[j] == max) {
                firstUsed[j] = i;
            }
        }
    }
    //find the last used page
    int lastFirstUsed = 0;
    for(i = 0; i < pageTableSize; i++) {
        if(firstUsed[i] > firstUsed[lastFirstUsed])
            lastFirstUsed = i;
     }
    pageTable[lastFirstUsed] = page; //page replaced
}

void postPageRequest() {
}

//opr specific ends

//debugging functions starts

void displayPT(int *pageTable, int page) {
    int i;
    printf("%d : ", page);
    for(i = 0; i < numberOfPagesinPT; i++) {
        printf("%d ", pageTable[i]);
    }
    printf("\n");
}

void printHit() {
    printf("H : ");
}

void printFault() {
    printf("F : ");
}

//debugging functions ends

int isPageHit(int *pageTable, int page) {
    int i;
    for(i = 0; i < numberOfPagesinPT; i++) {
        if(pageTable[i] == page) {
            postHit(i);
            return 1;
        }
    }
    return 0;
}

int main() {

    int i;
    printf("Enter the number of pages in page sequence: ");
    scanf("%d", &numberOfPages);

    int *pageSequence;
    pageSequence = (int*) malloc(numberOfPages * sizeof(int));
    printf("Enter the page sequence: ");
    for(i = 0; i < numberOfPages; i++) {
        scanf("%d", pageSequence + i);
    }

    printf("Enter the page table size: ");
    scanf("%d", &pageTableSize);

    int *pageTable = (int*) malloc(pageTableSize * sizeof(int));
    prePageProcessing();

    int hits = 0, faults = 0;
    for(i = 0; i < numberOfPages; i++) {
        int page = pageSequence[i];
        if(isPageHit(pageTable, page)) {
            hits++;
            printHit();
        }
        else {
            faults++;
            printFault();
            if(numberOfPagesinPT < pageTableSize) {
                pageTable[numberOfPagesinPT++] = page;
                postPageAppendedToPT();
            }
            else {
                replacePageinPT(pageTable, page, pageSequence, i);
            }
        }
        displayPT(pageTable, page); //debugging
        postPageRequest();
    }

    printf("Hits   : %d\n", hits);
    printf("Faults : %d\n", faults);

    return 0;
}