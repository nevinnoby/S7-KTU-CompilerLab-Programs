#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isKeywords(char buffer[]);

int main() {
    char ch, op[] = "+-/*<>=", buffer[20];
    int i, j = 0;
    FILE *fp = fopen("in.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        // Check if the character is an operator
        for (i = 0; i < strlen(op); ++i) {
            if (ch == op[i]) {
                if (j != 0) { // Check if buffer has characters before printing operator
                    buffer[j] = '\0';
                    j = 0;
                    if (isKeywords(buffer) == 1)
                        printf("%s is a keyword\n", buffer);
                    else
                        printf("%s is an identifier\n", buffer);
                }
                printf("%c is an operator\n", ch);
            }
        }

        // If character is alphanumeric, add it to the buffer
        if (isalnum(ch)) {
            buffer[j++] = ch;
        }
        // If character is space or newline, process the identifier in the buffer
        else if ((ch == ' ' || ch == '\n') && (j != 0)) {
            buffer[j] = '\0';
            j = 0;
            if (isKeywords(buffer) == 1)
                printf("%s is a keyword\n", buffer);
            else
                printf("%s is an identifier\n", buffer);
        }
    }

    // Final check in case the file doesn't end with space or newline
    if (j != 0) {
        buffer[j] = '\0';
        if (isKeywords(buffer) == 1)
            printf("%s is a keyword\n", buffer);
        else
            printf("%s is an identifier\n", buffer);
    }

    fclose(fp);
    return 0;
}

int isKeywords(char buffer[]) {
    int flag = 0;
    char keywords[35][10] = {"if", "int", "char", "for", "while"};
    for (int i = 0; i < 35; ++i) {
        if (strcmp(keywords[i], buffer) == 0) {
            flag = 1;
            break;
        }
    }
    return flag;
}
