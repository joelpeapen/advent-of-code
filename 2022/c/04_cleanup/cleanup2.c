#include <stdio.h>

int main() {
    FILE* file = NULL;
    int a[2], b[2], total = 0;

    if (!(file = fopen("input.txt", "r"))) {
        puts("FILE DID NOT OPEN");
        return 1;
    }

    while (fscanf(file, "%i-%i,%i-%i", &a[0], &a[1], &b[0], &b[1]) && !feof(file)) {
        printf("\n\n%i-%i", a[0], a[1]);
        if (!(a[1] < b[0] || a[0] > b[1])) {
            total++;
            printf("  yes");
        }
        printf("\n%i-%i", b[0], b[1]);
    }

    printf("\ntotal: %i", total);
}
