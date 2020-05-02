#include<iostream>
#include<vector>

using namespace std;
int main(){

    //SIZE GIVEN
    // vector<int> v(5);
    // vector<int>::iterator it;

    // for(int i=0;i<5;i++){
    //     v[i]=i+1;
    // }

    // for(it=v.begin();it!=v.end();it++){
    //     cout<<*it<<endl;
    // }

    //SIZE NOT GIVEN
    vector<int> v;
    vector<int>::iterator it;

    for(int i=0;i<5;i++){
        v.push_back(i+1);
    }

    for(it=v.begin();it!=v.end();it++){
        cout<<*it<<endl;
    }
}