#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> sol, vector<int> arr, int n)
{
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        sol[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
            {
                int possibleans = sol[j] + 1;
                if (possibleans > sol[i])
                {
                    sol[i] = possibleans;
                }
            }
        }
    }
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (sol[i] > max)
        {
            max = sol[i];
        }
    }
    return max;
}

int findlonsubseq(vector<int> arr, int n)
{
    vector<int> solution(n);
    solution[0] = 1;
    int ans = helper(solution, arr, n);
    return ans;
}

int main()
{
    vector<int> arr = {4, 3, 9, 7, 6, 8, 20};
    int n = 7;
    cout << findlonsubseq(arr, n);
}