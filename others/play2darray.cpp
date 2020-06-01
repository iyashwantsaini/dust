#include <bits/stdc++.h>
using namespace std;

void view(int *arr, int dim)
{
    for (int iteri = 0; iteri < pow(dim, 2); iteri++)
    {
        cout << arr[iteri] << " ";
    }
    cout << "\n\n";
}

int main()
{
    int dim,iteri = 0, iterj = 0,iterk=0, minimum, tempo, swp = 0, ind;
    cin >> dim;
    int arr[dim][dim];

    while (iteri < dim)
    {
        iterj = 0;
        while (iterj < dim)
        {
            cin >> arr[iteri][iterj];
            iterj++;
        }
        iteri++;
    }

    iteri = 0;
    while (iteri < dim - 1)
    {
        iterj = 0;
        while (iterj < dim)
        {
            minimum = arr[iteri][iterj];
            iterk = iteri;
            while (iterk < dim)
            {
                if (minimum > arr[iterk][iterj])
                {
                    minimum = arr[iterk][iterj];
                    ind = iterk;
                }
                iterk++;
            }
            if (minimum != arr[iteri][iterj])
            {
                swp++;
                tempo = arr[ind][iterj];
                arr[ind][iterj] = arr[iteri][iterj];
                arr[iteri][iterj] = tempo;
            }
            iterj++;
        }

        iterj = 0;
        while (iterj < dim)
        {
            minimum = arr[iterj][iteri];
            int iterk = iteri;
            while (iterk < dim)
            {
                if (minimum > arr[iterj][iterk])
                {
                    minimum = arr[iterj][iterk];
                    ind = iterk;
                }
                iterk++;
            }
            if (minimum != arr[iterj][iteri])
            {
                swp++;
                tempo = arr[iterj][ind];
                arr[iterj][ind] = arr[iterj][iteri];
                arr[iterj][iteri] = tempo;
            }
            iterj++;
        }
        iteri++;
    }
    cout << swp << "\n";
    view(*arr, dim);
}