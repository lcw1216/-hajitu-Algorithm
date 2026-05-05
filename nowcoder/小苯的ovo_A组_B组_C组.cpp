#include<bits/stdc++.h>
using namespace std;
const int TOP = 2*1e5+10;
vector<vector<bool>> bl(TOP,vector<bool>(TOP,false));
vector<vector<int>> md;
vector<vector<int>> sum = {{-1,2},{-2,1},{-2,-1},{-1,-2},{1,2},{2,1},{2,-1},{1,-2}};
bool check(int x,int y){
    if(x<0||x>TOP||y<0||y>TOP)return false;
    return true;
}
void sum_m(int x,int y){
    for(int i=0;i<8;i++){
        if(check(x+sum[i][0],y+sum[i][1])&&!bl[x+sum[i][0]][y+sum[i][1]])md.push_back({x+sum[i][0],y+sum[i][1]});
    }
    return ;
}
int to_sum(int x,int y){
    int val = 0;
    for(int i=0;i<8;i++){
        if(bl[x+sum[i][0]][y+sum[i][1]])val++;
    }
    return val;
}
int main(){
    int n;cin>>n;
    int max_x=0,max_y=0;
    vector<vector<int>> sd(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>sd[i][0]>>sd[i][1];
        bl[sd[i][0]][sd[i][1]]=true;
    }
    for(int i=0;i<n;i++){
        sum_m(sd[i][0],sd[i][1]);
    }
    int max_val=-1;
    vector<int> max_pos;
    int len = md.size();
    for(int i=0;i<len;i++){
        int tmp = to_sum(md[i][0],md[i][1]);
        if(tmp>max_val){max_val=tmp;max_pos=md[i];}
    }
    cout<<max_pos[0]<<' '<<max_pos[1]<<endl;
    return 0;
}