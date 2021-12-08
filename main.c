#include <stdio.h>
#include <stdlib.h>

int len;
int size;

void swap(int *x, char *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int charToInt(char c) {
    int num = 0;

    //Substract '0' from entered char to get
    //corresponding digit
    num = c - '0';

    return num;
}

char intToChar(int i) {
    return i + '0';
}

int ddd = 1;

void print(const int *v) {
    int i;
    if (v != 0) {
        printf("%d: ", ddd);
        ddd++;
        for (i = 0; i < size; i++) {
            printf("%c", intToChar(v[i]));
        }
        printf("\n");
    }
}

void heapalg(int v[], int n) {
    int i;
    if (n == 1) {
        print(v);
    } else {
        for (i = 0; i < n; i++) {
            heapalg(v, n - 1);
            if (n % 2 == 1) {
                swap(&v[0], &v[n - 1]);
            } else {
                swap(&v[i], &v[n - 1]);
            }
        }
    }
}

int main(int argc, char **argv) {
    if (argc > 2) {
        printf("Too many arguments!<%d>", argc);
        return 0;
    }
    if (argc == 0) {
        printf("No arguments!", argc);
        return 0;
    }
    int len = atoi(argv[1]);
    size = len;

    if (len <= 0 || len > 26) {
        printf("n<%d> too big!", len);
    }
    int num[26];
    for (int i = 0; i < len; i++) {
        num[i] = 17 + i;
    }
    heapalg(num, len);
    printf("%d permutations.", ddd - 1);
    return 0;
}