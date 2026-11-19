#include <stdio.h>
#include <string.h>
#include <ctype.h>

void readString(char s[], int size) {
    fgets(s, size, stdin);
    s[strcspn(s, "\n")] = '\0';
}

int main() {
    char s1[100], s2[100], temp[200];
    int choice, i, n;

    do {
        printf("\n===== STRING OPERATIONS MENU =====\n");
        printf("1. Length of string\n");
        printf("2. Copy string\n");
        printf("3. Concatenate two strings\n");
        printf("4. Compare two strings\n");
        printf("5. Reverse string\n");
        printf("6. Convert to uppercase\n");
        printf("7. Convert to lowercase\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();   /* consume leftover newline */

        switch (choice) {
            case 1:
                printf("Enter a string: ");
                readString(s1, sizeof(s1));
                printf("Length = %lu\n", strlen(s1));
                break;
            case 2:
                printf("Enter a string: ");
                readString(s1, sizeof(s1));
                strcpy(s2, s1);
                printf("Copied string = %s\n", s2);
                break;
            case 3:
                printf("Enter first string: ");
                readString(s1, sizeof(s1));
                printf("Enter second string: ");
                readString(s2, sizeof(s2));
                strcpy(temp, s1);
                strcat(temp, s2);
                printf("Concatenated string = %s\n", temp);
                break;
            case 4:
                printf("Enter first string: ");
                readString(s1, sizeof(s1));
                printf("Enter second string: ");
                readString(s2, sizeof(s2));
                if (strcmp(s1, s2) == 0)
                    printf("Strings are equal\n");
                else
                    printf("Strings are not equal\n");
                break;
            case 5:
                printf("Enter a string: ");
                readString(s1, sizeof(s1));
                n = strlen(s1);
                for (i = 0; i < n; i++)
                    temp[i] = s1[n - 1 - i];
                temp[n] = '\0';
                printf("Reversed string = %s\n", temp);
                break;
            case 6:
                printf("Enter a string: ");
                readString(s1, sizeof(s1));
                for (i = 0; s1[i]; i++)
                    s1[i] = toupper(s1[i]);
                printf("Uppercase = %s\n", s1);
                break;
            case 7:
                printf("Enter a string: ");
                readString(s1, sizeof(s1));
                for (i = 0; s1[i]; i++)
                    s1[i] = tolower(s1[i]);
                printf("Lowercase = %s\n", s1);
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 8);

    return 0;
}
