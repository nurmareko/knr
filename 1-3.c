#include <stdio.h>

/* this is a comment */

main()
{
    float fahr, celcius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("  F      C\n"); /* header */
    while (fahr <= upper) {
        celcius = (5.0 / 9) * (fahr - 32);
        printf("%3.0f %6.1f\n", fahr, celcius);
        fahr = fahr + step;
    }
}