#include <stdio.h>

main()
{
    float fahr, celcius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    celcius = lower;
    printf("  C      F\n");
    while (celcius <= upper) {
        fahr = celcius * (9.0 / 5.0) + 32.0;
        printf("%3.0f %6.0f\n", celcius, fahr);
        celcius = celcius + step;
    }
}