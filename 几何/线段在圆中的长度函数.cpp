#include<bits/stdc++.h>
using namespace std;
typedef double db;
const db eps = 1e-12;
vector<db> to_mid(db x0,db y0,db rr,db ax,db ay,db bx,db by){
    db dx = bx - ax,dy = by - ay;
    db a = dx*dx+dy*dy;
    db b = dx*(ax-x0)+dy*(ay-y0);
    db c = (ax-x0)*(ax-x0)+(ay-y0)*(ay-y0)-rr*rr;
    db dt = b*b-a*c;
    if(dt<0)return {0.0,-1.0};
    db sum = sqrt(dt);
    db t1 = (-b-sum)/a,t2 = (-b+sum)/a;
    if(t1>t2)swap(t1,t2);
    db l = max(t1,0.0),r = min(t2,1.0);
    if(l>r){
        if(l-r<eps){
            db t = (l+r)/2.0;
            return {t,t};
        }
        return {0.0,-1.0};
    }
    return {l,r};
}
int main(){
    db x1,y1,r1,x2,y2,r2;
    db a,b,c,d;
    cin>>x1>>y1>>r1;
    cin>>x2>>y2>>r2;
    cin>>a>>b>>c>>d;
    db dx = c-a,dy = d-b;
    db xd_len = hypot(dx,dy);
    if(xd_len<eps){cout<<0.0<<endl;return 0;}
    vector<db> mid1 = to_mid(x1,y1,r1,a,b,c,d);
    vector<db> mid2 = to_mid(x2,y2,r2,a,b,c,d);
    vector<vector<db>> mids;
    if(mid1[0]<=mid1[1])mids.push_back(mid1);
    if(mid2[0]<=mid2[1])mids.push_back(mid2);
    if(mids.empty()){cout<<0.0<<endl;return 0;}
    sort(mids.begin(),mids.end());
    db t = 0.0;
    db l = mids[0][0],r = mids[0][1];
    if(mids.size()==2){
        if(mids[1][0]<=r+eps)r = max(r,mids[1][1]);
        else {
            t += r-l;
            l = mids[1][0];
            r = mids[1][1];
        }
    }
    t+=r-l;
    db ans = t*xd_len;
    printf("%.10f",ans);
    return 0;
}