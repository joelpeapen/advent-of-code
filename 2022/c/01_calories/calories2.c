// elf calories
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main() {
    FILE* file = NULL;
    int calories[3] = { 0 }, elves[3] = { 0 }, elfCount = 1;
    char elfCurrent[SIZE]; // char for fgets

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
        if (totalElf > calories[0]) {
            calories[2] = calories[1];
            calories[1] = calories[0];
            calories[0] = totalElf;
            elves[2] = elves[1];
            elves[1] = elves[0];
            elves[0] = elfCount; // biggest elf
        }
        elfCount++;
        puts("");
    }

    fclose(file);

    int totalElf = 0;
    for (size_t i = 0; i < 3; i++) {
        printf("\nElf %3i: %i", elves[i], calories[i]);
        totalElf += calories[i];
    }
    printf("\n\nElf %i has the most calories", elves[0]);
    printf("\nSum of 3 largest elves: %i", totalElf);
}
