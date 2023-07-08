// elf calories
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main() {
    FILE* file = NULL;
    char elfCurrent[SIZE];
    int maxCal = 0, theElf = 0, elfCount = 1;

    if (!(file = fopen("input.txt", "r"))) {
        puts("FILE DID NOT OPEN");
        exit(EXIT_FAILURE);
    }

    while (fgets(elfCurrent, SIZE, file)) {
        int totalElf = 0;
        printf("\n Elf %i\n -------\n", elfCount);
        for (int i = 1; elfCurrent[0] != '\n' && !feof(file); i++) {
            printf("%2i: %s", i, elfCurrent);
            totalElf += atoi(elfCurrent);
            fgets(elfCurrent, SIZE, file);
        }
        printf("TOTAL: %i", totalElf);
        if (totalElf > maxCal) {
            maxCal = totalElf;
            theElf = elfCount;
        }
        elfCount++;
        puts("");
    }

    fclose(file);

    printf("\nelf %i has %i calories", theElf, maxCal);
}
