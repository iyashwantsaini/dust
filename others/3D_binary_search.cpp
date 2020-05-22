#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y, z, n;
    cin >> x >> y >> z >> n;
    int a[x][y][z];
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            for (int k = 0; k < z; k++){
                cin >> a[i][j][k];
            }
        }
    }

    int rangemin1d = 2147483647, rangemin2d = 2147483647;
    int rangemax1d = -1, rangemax2d = -1;
    int elx = 0, ely = 0, elz = 0, i=0, j=0, k=0;
    int flip = 0, countbin=0;

    for (i=0; i < x; i++){
        j=0;
        k=0;
        if(a[i][j][k]<n){
            rangemin1d=a[i][j][k];
            rangemax1d=a[i][j+y-1][k+z-1];
        }
        for (j=0; j < y; j++){
            k = 0;
            if(a[i][j][k]<=n){
                if(a[i][j][k+z-1]<n){
                    continue;
                }
                rangemin2d=a[i][j][k];
                rangemax2d=a[i][j][k+z-1];
            }
            if (a[i][j][k] == n){
                elx = i;
                ely = j;
                elz = k;
                flip = 1;
            }
            k++;
        }
    }
    
    if(rangemin1d!=2147483647){
        cout<<rangemin1d<<" "<<rangemax1d<<endl;
    }
    if(rangemin2d!=2147483647){
        cout << rangemin2d << " " << rangemax2d << endl;
    }

    if(flip==1){
        cout << elx << " " << ely << " " << elz << endl;
    }else{
        cout<<"0"<<endl;
        return 0;
    }
    
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
    int val = n;
    // Counter to tell the number of iterations
    i = 1;

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
            printf("Value found in %d loop runs", i);
            // cout<<i<<endl;
            exit(0);
        }
        i++;
    }
    // printf("Value not found");
    
    return 0;
}