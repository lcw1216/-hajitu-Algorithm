#include<bits/stdc++.h>
using namespace std;
int to_res(vector<vector<int>> a,vector<vector<int>> b){
    // 0 上位，下位，包含
    if(a[0][1]>b[3][1]||a[3][1]<b[0][1])return 0;
    if(a[0][0]>b[3][0]||a[3][0]<b[0][0])return 0;
    if(a[0][1]>b[0][1]&&a[3][1]<b[3][1]&&a[0][0]>b[0][0]&&a[3][0]<b[3][0])return 0;
    if(b[0][1]>a[0][1]&&b[3][1]<a[3][1]&&b[0][0]>a[0][0]&&b[3][0]<a[3][0])return 0;
    // 1
    if(a[0][0]==b[3][0]&&a[0][1]==b[3][1])return 1;
    if(a[3][0]==b[0][0]&&a[3][1]==b[0][1])return 1;
    if(a[2][0]==b[1][0]&&a[2][1]==b[1][1])return 1;
    if(a[1][0]==b[2][0]&&a[1][1]==b[2][1])return 1;
    // 2 inf
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(a[i][0]==b[j][0]||a[i][1]==b[j][1])return -1;
    return 2;
}
int main(){
    vector<vector<int>> a(2,vector<int>(2)),b(2,vector<int>(2));
    cin>>a[0][0]>>a[0][1]>>a[1][0]>>a[1][1];
    cin>>b[0][0]>>b[0][1]>>b[1][0]>>b[1][1];
    a.push_back({a[0][0],a[1][1]});
    a.push_back({a[1][0],a[0][1]});
    b.push_back({b[0][0],b[1][1]});
    b.push_back({b[1][0],b[0][1]});
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    //左下，左上，右下，右上
    //0 1 2 inf 分类讨论
    int ans = to_res(a,b);
    if(ans==-1)cout<<"inf"<<endl;
    else cout<<ans<<endl;
    return 0;
}