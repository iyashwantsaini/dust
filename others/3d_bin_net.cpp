#include <stdio.h>
#include <stdlib.h>
int main()
{

    int a[3][2][2] = {
        {{2, 11},{12, 19}},
        {{21, 22},{28, 37}},
        {{39,69},{75,92}}
        };

    // we'll find the start, end and pivot value using base pointer
    // Starting address of the 1D array
    int *start = **a;
    // End address of the array
    int *end = **a + sizeof(a) / sizeof(int) - 1;
    // Pivot would be set in middle of start and end
    int *pivot = **a + (sizeof(a) / sizeof(int)) / 2;
    // step would (start+end)/2, as pointer is used, +/- would have to be used
    // Cant divide address by 2, not allowed
    int step = (sizeof(a) / sizeof(int)) / 2;
    // Value to be searched in the array
    int val = 75;
    // Counter to tell the number of iterations
    int i = 1;

    //printf("%d",*(**a+7));
    //for(i=0;i<10;i++)
    while (1)
    {
        step /= 2;
        if (step == 0)
            step = 1;

        printf("Start- %d End-%d Pivot-%d Step-%d\n", *start, *end, *pivot, step);
        if (val < *pivot)
        {
            end = pivot;
            pivot -= step;
        }
        else if (val > *pivot)
        {
            start = pivot;
            pivot += step;
        }
        else
        {
            printf("Value found in %d loop runs", i+step);
            exit(0);
        }
        i++;
    }
    printf("Value not found");

    return 0;
}