#include <bits/stdc++.h>
using namespace std;
#include "chaining.h" //conatins ll

int hashfn(int key)
{
    return key % 10;
}
void Insert(struct Node *H[], int key)
{
    int index = hashfn(key);
    SortedInsert(&H[index], key);
}
int main()
{
    struct Node *HT[10];
    struct Node *temp;
    int i;

    for (i = 0; i < 10; i++)
        HT[i] = NULL;

    Insert(HT, 12);
    Insert(HT, 22);
    Insert(HT, 42);

    temp = Search(HT[hashfn(12)], 12);
    printf("%d ", temp->data);

    temp = Search(HT[hashfn(22)], 22);
    printf("%d ", temp->data);

    temp = Search(HT[hashfn(42)], 42);
    printf("%d ", temp->data);

    return 0;
}