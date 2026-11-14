#include <bits/stdc++.h>
using namespace std;

int fp(int a,int b) {
    int res = 1;
    while (b>0) {
        if (b%2==1) res=res*a;   
        a=a*a;                  
        b/=2;                    
    }
    return res;
}
int main(){
    int a,b;cin>>a>>b;
    int ans = fp(a,b);
    cout<<ans<<endl;
    return 0;
}