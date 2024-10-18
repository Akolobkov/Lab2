#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ProStr.h"
int z3() {
    FILE* file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.");
        return 1;
    }

    char ch;
    int length = 0;
    char* str = (char*)malloc(sizeof(char));
    if (str == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF && ch != 'q') {
        str[length++] = ch;

        char* temp = (char*)malloc((length + 1) * sizeof(char));
        if (temp == NULL) {
            printf("Memory allocation failed.");
            free(str);
            return 1;
        }

        for (int i = 0; i < length; i++) {
            temp[i] = str[i];
        }
        temp[length] = '\0';

        free(str);
        str = temp;
    }

    fclose(file);

    processString(str, length);

    file = fopen("data.txt", "w"); 
    if (file == NULL) {
        printf("Error opening the file.");
        free(str);
        return 1;
    }

    fprintf(file, "%s", str); 

    fclose(file);

    return 0;
}
int z2() {
    char* str = (char*)calloc(5, sizeof(char));
    if (str == NULL) {
        printf("Memory allocation failed.");
        return 0;
    }

    int length = 0;
    int allocatedSize = 5;
    char ch;

    printf("Enter characters (press Enter after each character, press 'q' to finish):\n");
    while ((ch = getchar()) != 'q') {
        if (length >= allocatedSize) {
            allocatedSize += 5;
            char* temp = (char*)realloc(str, allocatedSize * sizeof(char));

            if (temp != NULL) {
                str = temp;
            }
            else {
                printf("Memory reallocation failed.");
                free(str);
                return 0;
            }
        }

        str[length++] = ch;
    }
    processString(str, length);
    printf("%s", str);

    return 0;
}
int z1() {
    char* str = (char*)malloc(sizeof(char));
    if (str == NULL) {
        printf("Memory allocation failed.");
        return 0;
    }

    int length = 0;
    char ch;

    printf("Enter characters (press Enter after each character, press 'q' to finish):\n");
    while ((ch = getchar()) != 'q') {
        str[length++] = ch;

        char* temp = (char*)malloc((length + 1) * sizeof(char));
        if (temp == NULL) {
            printf("Memory allocation failed.");
            free(str);
            return 0;
        }

        for (int i = 0; i < length; i++) {
            temp[i] = str[i];
        }
        temp[length] = '\0';

        free(str);
        str = temp;
    }
    processString(str, length);
    printf("%s", str);

    return 0;
}
void main(void) {
    z3();
}