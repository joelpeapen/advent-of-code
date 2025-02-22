#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int getScore(const char n);
char search(const char arr[]);

int main() {
    FILE* file = NULL;
    char line[50];
    int total = 0;

    if (!(file = fopen("input.txt", "r"))) {
        puts("FILE DID NOT OPEN");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        const char found = search(line);
        const int len = strlen(line);
        printf("\nline: ");
        for (size_t i = 0; i < len; i++) {
            if (line[i] == found) {
                printf("(%c)", line[i]);
            } else {
                printf("%c", line[i]);
            }
        }
        printf("found char: %c\n", found);
        const int s = getScore(found);
        printf("score: %i\n", s);
        total += s;
    }

    printf("\nTotal: %i", total);
}

char search(const char arr[]) {
    size_t len = strlen(arr) - 1;
    size_t mid = len / 2;

    // split
    char *a = malloc((mid + 1) * sizeof(char));
    char *b = malloc((len - mid + 1) * sizeof(char));

    strncpy(a, arr, mid);
    strncpy(b, arr + mid, len - mid + 1);

    // search
    for (size_t i = 0; i < mid + 1; i++) {
        char c = a[i];
        for (size_t j = 0; j < len - mid + 1; j++) {
            if (a[i] == b[j]) {
                free(a);
                free(b);
                return c;
            }
        }
    }

    free(a);
    free(b);
    return 0;
}

int getScore(char found) {
    if (islower(found)) {
        return found - 96;
    }
    return found - 38;
}
