#include<bits/stdc++.h>
using namespace std;
//归并排序求逆序对数量
int a[500005],c[500005];
long long ans = 0;
void to_cnt(int l,int r){
    if(l==r)return;
    int mid = (l+r)/2,i = l,j = mid+1,k = l;
    to_cnt(l,mid);to_cnt(mid+1,r);
    while(i<=mid&&j<=r){
        if(a[i]<=a[j])c[k++] = a[i++];
        else {c[k++] = a[j++];ans += mid-i+1;}
    }
    while(i<=mid) c[k++] = a[i++];
    while(j<=r) c[k++] = a[j++];
    for(int m = l;m <= r;m++)a[m] = c[m];
}
int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    to_cnt(1,n);
    cout<<ans<<endl;
    return 0;
}