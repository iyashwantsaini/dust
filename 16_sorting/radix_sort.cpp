#include <bits/stdc++.h>
using namespace std;

// 10
// 651 329 45 32 839 20 355 6 9 436

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
    int count=0;
    int temp=max;
    while(temp!=0){
        count++;
        temp/=10;
    }
    
    list<int> v[10];
    list<int>::iterator it;
    int x=0;
    int one=0;
    while(x<count){
        
        int m = pow(10, x+1);
        int p = pow(10, x);
        for(int i=0;i<n;i++){ 
            int temp = data[i]%m;
            int index = temp/p;
            v[index].push_back(data[i]);
        }
        int c = 0;
        for(int i=0;i<10;i++){
            for(it=v[i].begin();it!=v[i].end();it++){
                data[c]=*it;
                c++;
            }
        }

    // if(one ==0){
    //     int num=0;
    //     c=0;
    //     for(int i=0;i<10;i++){
    //         num=0;
    //         for(it=v[i].begin();it!=v[i].end();it++){
    //             num++;
    //             c++;
    //         }
    //         int tot=c;
    //         for(int i=tot-num;i<tot&&tot>0&&i<n;i++,tot--){
    //             int tempo=data[i];
    //             data[i]=data[tot-1];
    //             data[tot-1]=tempo;
    //         }
    //     }
    //     one++;
    // }

        for(int j = 0; j<10; j++) {
            while(!v[j].empty()) {
                v[j].erase(v[j].begin());
            }
        }
        for(int i=n-1;i>=0;i--){
            cout<<data[i]<<" ";
        }    
        cout<<"\n";
        x++;
    }

	return 0;
}
