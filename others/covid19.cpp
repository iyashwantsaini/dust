#include <iostream>
using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T;
    cin>>T;
    int i=0;
    while(i<T){
        int n;
    cin>>n;
    int d,val,c=0;
    int inf=1;
    int min=20,max=1;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(i!=0){
            d=a-val;
            if(d<=2)
            {
                inf++;
            }
            else
            {
                if(min>inf)
                  min=inf;
                if(max<inf)
                    max=inf;
              inf=1;
            }
        }
         val=a;
    }
    if(min>inf){
        min=inf;
    }
    if(max<inf){
        max=inf;
    }
    i++;
    cout<<min<<" "<<max<<endl;
    }
	return 0;
}
