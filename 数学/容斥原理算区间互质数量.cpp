#include<bits/stdc++.h>
using namespace std;
// 质因数分解
vector<int> to_ys(int tar){
    vector<int> ans;
    for(int i=2;i*i<=tar;i++){
        if(tar%i==0){
            ans.push_back(i);
            while(tar%i==0)tar/=i;
        }
    }
    if(tar>1)ans.push_back(tar);
    return ans;
}
//计算有多少个1 r中的数与n互质
int to_ct(int r,int n){
    vector<int> ys = to_ys(n);
    int len = r;
    int yss = ys.size();
    for(int i=1;i<(1<<yss);i++){
        int ct = 0,tp = 1;
        bool out = false;
        for(int j=0;j<yss;j++){
            if(i & (1 << j)){
                if(tp>r/ys[j]){out=true;break;}
                tp*=ys[j];
                ct++;}
            }
        if(out)continue;
        if(ct%2==1)len-=(r/tp);else len+=(r/tp);
    }
    return len;
}
//计算有多少个l r中的数与n互质
int to_res(int l,int r,int n){
    int ans = to_ct(r,n);
    if(l>1)ans-=to_ct(l-1,n);
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--){
        int l,r,n;cin>>l>>r>>n;
        int zhi = to_res(l,r,n);
        int len = r-l+1;
        int ans = (len-zhi)*2+zhi;
        cout<<ans<<endl;
    }
    return 0;
}