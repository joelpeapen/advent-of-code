#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int getScore(const char n);
char search(const char a[], const char b[], const char c[]);

int main() {
    FILE* file = NULL;
    char a[50], b[50], c[50];
    int total = 0;

    if (!(file = fopen("input.txt", "r"))) {
        puts("FILE DID NOT OPEN");
        return 1;
    }

    while (fgets(a, sizeof(a), file)) {
        fgets(b, sizeof(b), file);
        fgets(c, sizeof(c), file);
        printf("\na: %sb: %sc: %s", a, b, c);
        const char found = search(a, b, c);
        printf("found char: %c\n", found);
        const int s = getScore(found);
        printf("score: %i\n", s);
        total += s;
    }

    printf("\nTotal: %i", total);
}

char search(const char a[], const char b[], const char c[]) {
    for (size_t i = 0, len1 = strlen(a); i < len1; i++) {
        char first = a[i];
        for (size_t j = 0, len2 = strlen(b); j < len2; j++) {
            char second = b[j];
            for (size_t k = 0, len3 = strlen(c); k < len3; k++) {
                char third = c[k];
                if (first == second && second == third) {
                    return first;
                }
            }
        }
    }
    return '\0';
}

int getScore(char found) {
    if (islower(found)) {
        return found - 96;
    }
    return found - 38;
}
