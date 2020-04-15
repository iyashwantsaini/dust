#include <bits/stdc++.h>
using namespace std;

//bug

class Node
{
public:
    int col;
    int data;
    Node *next;
};

class sparse
{
private:
    Node *a[4];
    Node *p;

public:
    sparse()
    {
        for (int i = 0; i < 4; i++)
        {
            a[i] = NULL;
        }
        p = NULL;
    }
    sparse(int arr[4][4])
    {
        for (int i = 0; i < 4; i++)
        {   
            p = a[i];
            for (int j = 0; j < 4; j++)
            {
                if (arr[i][j] != 0)
                {
                    p = new Node();
                    p->col = j;
                    p->data = arr[i][j];
                    p = p->next;
                }
            }
        }
    }
    ~sparse()
    {
        Node *q;
        for (int i = 0; i < 4; i++)
        {
            a[i] = p;
            for (int j = 0; j < 4; j++)
            {
                q = p;
                p = p->next;
                delete q;
            }
        }
    }
    void SDisplay()
    {
        for (int i = 0; i < 4; i++)
        {
            p=a[i];
            int j=0;
            while(p){
                cout<<p->data<<" ";
                p=p->next;
            }
        }
    }
};

int main()
{

    int a[4][4] = {
        {0, 2, 0, 0},
        {5, 0, 0, 8},
        {0, 4, 0, 0},
        {7, 2, 1, 0}};

    // --display--
    // for(int i=0;i<4;i++){
    //     for(int j=0;j<4;j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    sparse s(a);
    s.SDisplay();
}