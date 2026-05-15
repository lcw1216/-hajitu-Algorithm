#include<bits/stdc++.h>
using namespace std;
vector<vector<bool>> bl(10,vector<bool>(10,false));
vector<bool> res(100,false);
vector<vector<int>> checknums;
bool check(int x,int y,int a,int b){
    int h=y-b,l=a-x;
    if(!(bl[x][y]&&bl[a][b]))return false;
    if(a+h>=10||b+l>=10||x+h>=10||y+l>=10)return false;
    if(a+h<0||b+l<0||x+h<0||y+l<0)return false;
    if(!(bl[a+h][b+l]&&bl[x+h][y+l]))return false;
    vector<int> tmp = {x,y,a,b,a+l,b+h,x+l,y+h};
    checknums.push_back(tmp);
    return true;
}
bool cnt(int x,int y){
    int rm  = 10-y,dm = 10-x,ans = 0;
    for(int i=0;i<dm;i++){
        for(int j=0;j<rm;j++){
            if(check(i,j+y,x+i,j))return true;
        }
    }
    return false;
}
int main(){
    for(int i=0;i<10;i++){
        char tmp;
        for(int j=0;j<10;j++){
            cin>>tmp;
            if(tmp=='1')bl[i][j]=true;
        }
    }
    for(int x=0;x<10;x++){
        for(int y=1;y<10;y++){
            if(x*x+y*y>100)break;
            if(cnt(x,y))res[x*x+y*y]=true;
        }
    }
    int ans = 0;
    for(int i=0;i<100;i++)if(res[i])ans++;
    cout<<ans<<endl;
    for(int i=0;i<(int)checknums.size();i++){
        for(int j=0;j<8;j++)cout<<checknums[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}