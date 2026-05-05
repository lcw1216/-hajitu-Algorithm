#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> sum = {{0,1},{1,0}};
vector<vector<int>> nums(6,vector<int>(6));
vector<vector<int>> zo;
bool check(int x,int y){if(x>=6||y>=6)return false;return true;}
void hf_in(int x,int y){
    for(int i=0;i<2;i++){
        if(check(x+sum[i][0],y+sum[i][1])&&nums[x][y]+nums[x+sum[i][0]][y+sum[i][1]]==1)
            zo.push_back({x,y,x+sum[i][0],y+sum[i][1]});
    }
}
bool check_res(int x,int y,int z){
    vector<vector<int>> ck;
    for(int i=0;i<3;i+=2){
        ck.push_back({zo[x][i],zo[x][i+1]});
        ck.push_back({zo[y][i],zo[y][i+1]});
        ck.push_back({zo[z][i],zo[z][i+1]});
    }
    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            if(ck[i][0]==ck[j][0]&&ck[i][1]==ck[j][1])return false;
        }
    }
    return true;
}
int main(){
    for(int i=0;i<6;i++)for(int j=0;j<6;j++)cin>>nums[i][j];
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            hf_in(i,j);
        }
    }
    int ans = 0;
    int len = zo.size();
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            for(int k=j+1;k<len;k++){
                if(check_res(i,j,k))ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}