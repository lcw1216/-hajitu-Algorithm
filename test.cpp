#include<bits/stdc++.h>
using namespace std;

//要求矩阵为排列，且每一列的最大公约数也为全排列
int main(){
    int n;cin>>n;
    vector<vector<int>> ans(n);
    for(int i=1;i<=n;i++)ans[i].push_back(i);
    for(int i=n+1;i<=n*n;i++){
        bool ip = false;
        for(int j=2;j<n;i++){
            if(ans[j].size()>=n)continue;
            if(i%j==0){
                ans.push_back(i);
                ip=true;
                break;
            }
        }
        if(!ip)
    }

}
1 5 8
2 4 6 8 
3 6 9