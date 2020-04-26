#ifndef chaining_h
#define chaining_h

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
// void Display(struct Node *p)
// {
//     while (p != NULL)
//     {
//         printf("%d ", p->data);
//         p = p->next;
//     }
// }

// int count(struct Node *p)
// {
//     int l = 0;
//     while (p)
//     {
//         l++;
//         p = p->next;
//     }
//     return l;
// }
void SortedInsert(struct Node **H, int x)
{
    struct Node *t, *q = NULL, *p = *H;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (*H == NULL)
        *H = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == *H)
        {
            t->next = *H;
            *H = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
    cout<<"Inserted : "<<x<<endl;
}
struct Node *Search(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// int Delete(struct Node *p, int index)
// {
//     struct Node *q = NULL;
//     int x = -1, i;

//     if (index < 1 || index > count(p))
//         return -1;
//     if (index == 1)
//     {
//         q = first;
//         x = first->data;
//         first = first->next;
//         free(q);
//         return x;
//     }
//     else
//     {
//         for (i = 0; i < index - 1; i++)
//         {
//             q = p;
//             p = p->next;
//         }
//         q->next = p->next;
//         x = p->data;
//         free(p);
//         return x;
//     }
// }
#endif