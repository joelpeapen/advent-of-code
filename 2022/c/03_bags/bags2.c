#include <stdio.h>
#include <string.h>
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

int getScore(const char n) {
    switch(n) {
        case 65: return 27; break;
        case 66: return 28; break;
        case 67: return 29; break;
        case 68: return 30; break;
        case 69: return 31; break;
        case 70: return 32; break;
        case 71: return 33; break;
        case 72: return 34; break;
        case 73: return 35; break;
        case 74: return 36; break;
        case 75: return 37; break;
        case 76: return 38; break;
        case 77: return 39; break;
        case 78: return 40; break;
        case 79: return 41; break;
        case 80: return 42; break;
        case 81: return 43; break;
        case 82: return 44; break;
        case 83: return 45; break;
        case 84: return 46; break;
        case 85: return 47; break;
        case 86: return 48; break;
        case 87: return 49; break;
        case 88: return 50; break;
        case 89: return 51; break;
        case 90: return 52; break;
        case 97: return 1; break;
        case 98: return 2; break;
        case 99: return 3; break;
        case 100: return 4; break;
        case 101: return 5; break;
        case 102: return 6; break;
        case 103: return 7; break;
        case 104: return 8; break;
        case 105: return 9; break;
        case 106: return 10; break;
        case 107: return 11; break;
        case 108: return 12; break;
        case 109: return 13; break;
        case 110: return 14; break;
        case 111: return 15; break;
        case 112: return 16; break;
        case 113: return 17; break;
        case 114: return 18; break;
        case 115: return 19; break;
        case 116: return 20; break;
        case 117: return 21; break;
        case 118: return 22; break;
        case 119: return 23; break;
        case 120: return 24; break;
        case 121: return 25; break;
        case 122: return 26; break;
    }
    return 0;
}
