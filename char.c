#include <stdio.h>
#include <string.h>

int main() {
    char input[30];        
    char stuffed[50] = " ";
    char start_delim, end_delim;
    char start_str[3], end_str[3];
    int i, length;

    printf("Enter characters to be stuffed: ");
    scanf("%s", input);

    printf("Enter a character as starting delimiter: ");
    scanf(" %c", &start_delim);

    printf("Enter a character as ending delimiter: ");
    scanf(" %c", &end_delim);

    start_str[0] = start_delim;
    start_str[1] = '\0';

    end_str[0] = end_delim;
    end_str[1] = '\0';

    strcat(stuffed, start_str);

    for (i = 0; i < strlen(input); i++) {
        char temp[2];  
        temp[0] = input[i];
        temp[1] = '\0';  

        if (input[i] == start_delim) {
            strcat(stuffed, start_str);
        } else if (input[i] == end_delim) {
            strcat(stuffed, end_str);
        } else {
            strcat(stuffed, temp);
        }
    }

    strcat(stuffed, end_str);
    printf("\nAfter stuffing: %s", stuffed);
    length = strlen(stuffed);

    for (i = 2; i < length - 1; i++) {
        stuffed[i - 1] = stuffed[i];
    }
    stuffed[length - 1] = '\0';
    printf("\nAfter de-stuffing: %s", stuffed);

    return 0;
}
