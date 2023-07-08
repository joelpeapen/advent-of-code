#include <stdio.h>
#include <stdlib.h>

#define ROCK 1
#define PAPER 2
#define SCISSORS 3

void gethand(char *a, char *b);
char win(const char a, const char b);

int main() {
    FILE* file = NULL;
    int score = 0, total = 0, pos = 0;
    char a = 0, b = 0;

    if (!(file = fopen("input.txt", "r"))) {
        puts("FILE DID NOT OPEN");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%c %c", &a, &b)) {
        if (feof(file)) {
            break;
        }
        printf("\n%c %c\t", a, b);
        gethand(&a, &b);
        total += win(a, b) + b;
        printf("+ %i\tscore: %i", b, total);
        fseek(file, pos += 4, SEEK_SET);
    }

    printf("\n\n\tTotal: %i", total);
}

char win(const char a, const char b) {
    if (a == b && a != '\0' && b != '\0') {
        printf("DRAW +3\t");
        return 3;
    }

    if (a == ROCK) {
        if (b == PAPER) {
            printf("WIN  +6\t");
            return 6;
        } else {
            printf("LOST +0\t");
            return 0;
        }
    }

    if (b == ROCK) {
        if (a == PAPER) {
            printf("LOST +0\t");
            return 0;
        } else {
            printf("WIN  +6\t");
            return 6;
        }
    }

    if (a == SCISSORS && b == PAPER) {
        printf("LOST +0\t");
        return 0;
    }

    if (b == SCISSORS && a == PAPER) {
        printf("WIN  +6\t");
        return 6;
    }

    return 0;
}

void gethand(char *a, char *b) {
    if (*a == 'A') {
        *a = ROCK;
    } else if (*a == 'B') {
        *a = PAPER;
    } else if (*a == 'C') {
        *a = SCISSORS;
    }

    if (*b == 'X') {
        *b = ROCK;
    } else if (*b == 'Y') {
        *b = PAPER;
    } else if (*b == 'Z') {
        *b = SCISSORS;
    }
}
