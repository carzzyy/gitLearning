#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

int count_chars(FILE *fp) {
    int count = 0;
    char c;
    while ((c = fgetc(fp)) != EOF) {
        count++;
    }
    return count;
}

int count_words(FILE *fp) {
    int count = 0;
    char str[MAX_LEN];
    while (fscanf(fp, "%s", str) != EOF) {
        count++;
    }
    return count;
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        printf("Usage: %s -c/-w [filename]\n", argv[0]);
        exit(1);
    }

    char *option = argv[1];
    char *filename = argv[2];
    if (argc == 2) {
        filename = "input.txt";
    }

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    int count = 0;
    if (strcmp(option, "-c") == 0) {
        count = count_chars(fp);
        printf("×Ö·ûÊý£º%d\n", count);
    } else if (strcmp(option, "-w") == 0) {
        count = count_words(fp);
        printf("µ¥´ÊÊý£º%d\n", count);
    } else {
        printf("Unknown option %s\n", option);
        exit(1);
    }

    fclose(fp);
    return 0;
}
