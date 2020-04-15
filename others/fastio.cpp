#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        string alpha="abcdefghijklmnopqrstuvwxyz";
        string ans;
        for(int i=0;i<n/b+1;i++) ans+=alpha.substr(0,b);
        ans.resize(n);
        cout<<ans<<endl;
    }
}