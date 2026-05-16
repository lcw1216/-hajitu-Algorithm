#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
//判断两根线段之间的交点是否有交点且为整点
int n;
int check(vector<int> a,vector<int>b){
    //b2 = (b[1]-(b[3]-b[1])/(b[2]-b[0])*b[0])
    //b1 = (a[1]-(a[3]-a[1])/(a[2]-a[0])*a[0])
    //k2 = ((b[3]-b[1])/(b[2]-b[0]))
    //k1 = ((a[3]-a[1])/(a[2]-a[0]))
    // double xx = (b2-b1)/(k1-k2),yy = k1*(b2-b1)/(k1-k2)+b1;
    double xx = ((b[1]-(b[3]-b[1])/(b[2]-b[0])*b[0])-(a[1]-(a[3]-a[1])/(a[2]-a[0])*a[0]))/(((a[3]-a[1])/(a[2]-a[0]))-((b[3]-b[1])/(b[2]-b[0])));
    double yy = ((a[3]-a[1])/(a[2]-a[0]))*((b[1]-(b[3]-b[1])/(b[2]-b[0])*b[0])-(a[1]-(a[3]-a[1])/(a[2]-a[0])*a[0]))/(((a[3]-a[1])/(a[2]-a[0]))-((b[3]-b[1])/(b[2]-b[0])))+(a[1]-(a[3]-a[1])/(a[2]-a[0])*a[0]);
    int x = ((b[1]-(b[3]-b[1])/(b[2]-b[0])*b[0])-(a[1]-(a[3]-a[1])/(a[2]-a[0])*a[0]))/(((a[3]-a[1])/(a[2]-a[0]))-((b[3]-b[1])/(b[2]-b[0])));
    int y = ((a[3]-a[1])/(a[2]-a[0]))*((b[1]-(b[3]-b[1])/(b[2]-b[0])*b[0])-(a[1]-(a[3]-a[1])/(a[2]-a[0])*a[0]))/(((a[3]-a[1])/(a[2]-a[0]))-((b[3]-b[1])/(b[2]-b[0])))+(a[1]-(a[3]-a[1])/(a[2]-a[0])*a[0]);
    if(!(x==xx&&y==yy))return -1;
    if(x<min(a[0],a[2])||x<min(b[0],b[2])||x>max(a[0],a[2])||x>max(b[0],b[2]))return -1;
    if(y<min(a[1],a[3])||y<min(b[1],b[3])||y>max(a[1],a[3])||y>max(b[1],b[3]))return -1;
    return (x*(n+10)+y);
}
int main(){
    cin>>n;
    vector<vector<int>>pos(n,vector<int>(4));
    int up = n+10;
    for(int i=0;i<n;i++)cin>>pos[i][0]>>pos[i][1]>>pos[i][2]>>pos[i][3];
    unordered_map<int,int> mp;
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int ck = check(pos[i],pos[j]);
            if(ck>=0)mp[ck]++;
        }
    }
    int ans = 0;
    for(const auto&pair:mp) ans++;
    cout<<ans<<endl;
    return 0;
}