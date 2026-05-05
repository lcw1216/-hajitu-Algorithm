#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;cin>>T;
    while(T--){
        int n,m;cin>>n>>m;
        string a,s;cin>>a>>s;
        int pos = 0;
        for(int i=0;i<m;i++){
            if(s[i]=='L')if(pos>0)pos--;
            if(s[i]=='R')if(pos<n-1)pos++;
            if(s[i]=='U'){if(a[pos]=='9')a[pos]='0';else a[pos]++;}
            if(s[i]=='D'){if(a[pos]=='0')a[pos]='9';else a[pos]--;}
        }
        cout<<a<<endl;
    }
    return 0;
}