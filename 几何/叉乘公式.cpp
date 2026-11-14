#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//差乘判断是否相交
//+1代表线段是否从左到右，-1代表是否从右到左
double a,b,c,d;
double u1,v1,u2,v2;
double cross(double x1,double y1,double x2,double y2,double x3,double y3){
    return (y3-y1)*(x2-x1)-(x3-x1)*(y2-y1);
}
void solve(){
    double n,ans = 0;cin>>n;
    cin>>u1>>v1>>u2>>v2;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c>>d;
        double s1 = cross(u1,v1,u2,v2,a,b);
        double s2 = cross(u1,v1,u2,v2,c,d);
        double t1 = cross(a,b,c,d,u1,v1);
        double t2 = cross(a,b,c,d,u2,v2);
        if(s1*s2<0&&t1*t2<0){
            if(s1>0)ans++;else ans--;
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--){
        solve();
    }
    return 0;
}