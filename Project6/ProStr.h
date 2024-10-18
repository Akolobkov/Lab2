#pragma once
#include <string.h>

void processString(char* str, int len) {
    int k;
    str[len++] = '\0';
    for (int i = 0; i < len - 1; i++) {
        k = 1000000;
        if (str[i] >= '0' && str[i] <= '9') {
            if ((str[i] - '0') % 2 == 0 && i < len) {
                for (int j = len - 2; j > i; j--) {
                    str[j + 2] = str[j];
                }
                str[i + 1] = '+';
                str[i + 2] = '+';
                i += 2;
                len += 2;
            }
            else if ((str[i] - '0') % 2 != 0 && i < len - 1) {
                for (int j = i; j < len - 1; j++) {
                    str[j] = str[j + 1];
                    k = j;
                }
                str[k + 1] = '\0';
                str[k + 2] = '\0';
                str[k + 3] = '\0';
                len--;
                i--;
            }
        }
    }
}