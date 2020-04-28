#include<iostream>
using namespace std;

int *apply_all(int *p, int size1 ,int *q, int size2){

    int *new_arr{nullptr};
    new_arr = new int[size1 * size2];
    
    for(size_t i{0};i<size1;i++)
    {
        for(size_t j{0};j<size2;j++)
        {
            cout<<*q<<endl;
             *(new_arr)=(*p)*(*q);
                q++;
                new_arr++;
            // cout<<*new_arr<<endl;
        }
        p++;
        cout<<*p<<endl;
    }
    return new_arr;
}

void print(int *r, int size)
{
    for(int i{0};i<size; i++)
    {
        cout<< *r << " ";
        r++;
    }
}

int main()
{
    int arr1[]{1,2,3,4,5};
    int arr2[]{10,20,30};
    
    cout<< "Array 1 :";
    print(arr1,5);
    cout << endl;
    
    cout<< "Array 2 :";
    print(arr2,3);
    cout << endl;
    
    int *results = apply_all(arr1 ,5 ,arr2 ,3);
    cout<< "result :";
    print(results,15);
    
}