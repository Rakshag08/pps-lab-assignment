#include <stdio.h>

int isLeap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int daysInMonth(int m, int y) {
    int d[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (m == 1 && isLeap(y)) return 29;
    return d[m];
}

/* Day of week of 1 Jan: 0=Sun ... 6=Sat */
int firstDayOfYear(int y) {
    int p = y - 1;
    return (1 + 5*(p % 4) + 4*(p % 100) + 6*(p % 400)) % 7;
}

int main() {
    const char *names[] = {"January","February","March","April","May","June",
                           "July","August","September","October","November","December"};
    int year;
    printf("Enter year: ");
    scanf("%d", &year);

    int start = firstDayOfYear(year);

    printf("\n========== Calendar %d ==========\n", year);
    for (int m = 0; m < 12; m++) {
        printf("\n---------- %s ----------\n", names[m]);
        printf(" Su Mo Tu We Th Fr Sa\n");

        for (int i = 0; i < start; i++)
            printf("   ");

        int days = daysInMonth(m, year);
        for (int d = 1; d <= days; d++) {
            printf("%3d", d);
            start = (start + 1) % 7;
            if (start == 0) printf("\n");
        }
        if (start != 0) printf("\n");
    }
    return 0;
}
