#include<iostream>
#include<set>
#include<vector>

using namespace std;

int main(){
    set<int> s;
    vector<int> result;

    vector<int> input={1,2,2,3,1,4};
    for(int i=0;i<input.size();i++){
        if(s.find(input[i])==s.end()){
            s.insert(input[i]);
            result.push_back(input[i]);
        }
    }
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}