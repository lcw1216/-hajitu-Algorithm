#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int P = 131;
const int N = 1000010;
//字符串哈希+二分
ULL h1[N],h2[N],p[N];
char s[N];
ULL get_hash(ULL h[],int l,int r){
    return h[r] - h[l-1]*p[r-l+1];
}
int main(){
    string si;cin>>si;
    int n = si.length();
    for(int i=1;i<=n;i++)s[i] = si[i-1];
    p[0] = 1;
    for(int i=1;i<=n;i++){
        p[i] = p[i-1]*P;
        h1[i] = h1[i-1]*P+s[i];
        h2[i] = h2[i-1]*P+s[n-i+1];
    }
    int maxlen = 0;
    for(int i=1;i<=n;i++){
        int l = 0,r = min(i-1,n-i);
        while(l<r){
            int mid = (l+r+1)>>1;
            if(get_hash(h1,i-mid,i-1)==get_hash(h2,n-(i+mid)+1,n-(i+1)+1)){
                l = mid;
            }
            else r = mid-1;
        }
        maxlen = max(maxlen,1+2*l);
        l = 0,r = min(i,n-i);
        while(l<r){
            int mid = (l+r+1)>>1;
            if(get_hash(h1,i-mid+1,i)==get_hash(h2,n-(i+mid)+1,n-(i+1)+1)){
                l = mid;
            }else r = mid-1;
        }
        maxlen = max(maxlen,2*l);
    }
    cout<<maxlen<<endl;
    return 0;
}