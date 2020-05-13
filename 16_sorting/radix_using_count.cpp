#include <bits/stdc++.h>
using namespace std;

void countsort(int data[], int size, int divi) {
    int max = 10;
    int result[size];
    int cs[max];
    for (int i = 0; i < max; ++i){
        cs[i] = 0;   
    }
    for (int i = 0; i < size; i++){
        cs[(data[i] / divi) % 10]++;   
    }
    for (int i = 1; i < max; i++){
        cs[i] += cs[i - 1];   
    }
    for (int i = size - 1; i >= 0; i--) {
        result[cs[(data[i] / divi) % 10] - 1] = data[i];
        cs[(data[i] / divi) % 10]--;
    }
    for (int i = 0; i < size; i++){
        data[i] = result[i];   
    }
    for (int i = 0; i < size; i++){
        cout << data[i] << " ";
    }cout<<"\n";
}

void radixsort(int data[], int size, int max) {
  for (int divi = 1; max / divi > 0; divi *= 10){
    countsort(data, size, divi);   
  }
}

int main() {
    int n;
    cin>>n;
    int data[n]={0};
    for(int i=0;i<n;i++){
        cin>>data[i];
    }
    int max=0;
    for(int i=0;i<n;i++){
        if(data[i]>max){
            max=data[i];
        }
    }
    radixsort(data, n ,max);
}