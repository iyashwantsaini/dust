#include <iostream>
#include<string>
#include<map>

using namespace std;

void rect(int t){
        if(t==0){
            return;
        }
        
        string s;
	    int x,a,b;
	    cin>>a;cin>>b;
	    cin>>s;
	    
        map<char,int> m;
	        for(int i=0;i<s.length();i++){
                m[s[i]]++;
            }
        
        for(int i=0;i<b;i++){
            
	        int c;
	        cin>>c;
	       
	        int sum=0;
	        map<char,int>::iterator it;
	        for(it=m.begin();it!=m.end();it++){
	            if(it->second>c){
	                sum+=it->second-c;
	            }
            }
            cout<<sum<<endl;
        }
    rect(t-1);
}

int main() {
	int t;
	cin>>t;
	
	rect(t);
	return 0;
}
