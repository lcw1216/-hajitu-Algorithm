#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    while(b){
        int t = b;
        b = a%b;
        a = t;
    }
    return a;
}
int main(){
    int a,b;cin>>a>>b;
    cout<<gcd(a,b)<<endl;
    return 0;
}