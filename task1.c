#include <stdio.h>

int main(void) {
    int score;

    while (1) {
        printf("Enter the NFL score (Enter 1 to stop): ");
        if (scanf("%d", &score) != 1) {
            fprintf(stderr, "Invalid input\n");
            return 1;
        }

        if (score == 1) {
            break; // sentinel value to stop (1 is never a real NFL score anyway)
        }

        if (score < 0) {
            printf("Score must be non-negative.\n\n");
            continue;
        }

        printf("Possible combinations of scoring plays if a team's score is %d:\n", score);

        int found = 0;

        for (int a = 0; a * 8 <= score; a++) {                     // TD + 2pt = 8
            for (int b = 0; a * 8 + b * 7 <= score; b++) {          // TD + FG(XP) = 7
                for (int c = 0; a * 8 + b * 7 + c * 6 <= score; c++) { // TD = 6
                    for (int d = 0; a * 8 + b * 7 + c * 6 + d * 3 <= score; d++) { // 3pt FG
                        int rem = score - (a * 8 + b * 7 + c * 6 + d * 3);
                        if (rem >= 0 && rem % 2 == 0) {
                            int e = rem / 2; // Safety = 2
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                   a, b, c, d, e);
                            found++;
                        }
                    }
                }
            }
        }

        if (!found) {
            printf("No valid combination of scoring plays sums to %d.\n", score);
        }

        printf("\n");
    }

    printf("Program terminated.\n");
    return 0;
}