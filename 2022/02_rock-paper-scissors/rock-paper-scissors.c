#include <stdio.h>
#include <stdlib.h>

enum Hands { ROCK = 1, PAPER, SCISSORS };

void gethand(char *a, char *me);
char win(const char a, const char me);

int main() {
    FILE* file = NULL;
    int score = 0, total = 0, pos = -4;
    char a = 0, me = 0;

    if (!(file = fopen("02_input.txt", "r"))) {
        puts("FILE DID NOT OPEN");
        exit(EXIT_FAILURE);
    }

    while (!feof(file)) {
        fseek(file, pos += 4, SEEK_SET);
        fscanf(file, "%c %c", &a, &me);
        printf("\n%c %c\t", a, me);
        gethand(&a, &me);
        total += win(a, me) + me;
        printf("+ %i\tscore: %i", me, total);
    }

    printf("\n\n\tTotal: %i", total - 6);
}

void gethand(char *a, char *me) {
    if (*a == 'A') {
        *a = ROCK;
    } else if (*a == 'B') {
        *a = PAPER;
    } else if (*a == 'C') {
        *a = SCISSORS;
    }

    if (*me == 'X') {
        *me = ROCK;
    } else if (*me == 'Y') {
        *me = PAPER;
    } else if (*me == 'Z') {
        *me = SCISSORS;
    }
}

char win(const char a, const char me) {
    if (a == me && a != '\0' && me != '\0') {
        printf("DRAW +3\t");
        return 3;
    }

    if (a == ROCK) {
        if (me == PAPER) {
            printf("WIN  +6\t");
            return 6;
        } else {
            printf("LOST +0\t");
            return 0;
        }
    }

    if (me == ROCK) {
        if (a == PAPER) {
            printf("LOST +0\t");
            return 0;
        } else {
            printf("WIN  +6\t");
            return 6;
        }
    }

    if (a == SCISSORS && me == PAPER) {
        printf("LOST +0\t");
        return 0;
    }

    if (me == SCISSORS && a == PAPER) {
        printf("WIN  +6\t");
        return 6;
    }

    return 0;
}
