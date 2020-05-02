#include<iostream>
#include<utility> //contains pair class
#include<set>
#include<map>
#include<unordered_map>

using namespace std;
int main(){
    
    //PAIR
    // pair<int,char> p;
    // p=make_pair(2,'b');
    // cout<<p.first<<" "<<p.second<<endl;

    // pair<int,char> p2(1,'a');
    // cout<<p2.first<<" "<<p2.second<<endl;

    
    //SET using balanced bst
    // set<int> s;
    // int arr[]={1,2,3,4,4,2,7};
    // for(int i=0;i<7;i++){
    //     s.insert(arr[i]);
    // }
    // set<int>::iterator it;
    // for(it=s.begin();it!=s.end();it++){
    //     cout<<*it<<endl;
    // }
    // if(s.find(6)==s.end()){ //i.e we reached end but not found
    //     cout<<"elementnotfound"<<endl;
    // }else{
    //     cout<<"elementfound"<<endl;
    // }

    
    //MAP using bst
    int arr[]={1,2,3,1,2,5,9};
    // map<int,int> m;
    unordered_map<int,int> m;

    for(int i=0;i<7;i++){
        m[arr[i]]++;
    }

    m.erase(1); //deletes 1's key and values
    // map<int,int>::iterator it;
    unordered_map<int,int>::iterator it;
    for(it=m.begin();it!=m.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }

} 