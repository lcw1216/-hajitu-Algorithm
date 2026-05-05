#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<vector<int>> nums(n+1);
    vector<int> tar(2*n+1);
    int pos = 0;
    for(int i=1;i<=2*n;i++){
        cin>>tar[i];
        nums[tar[i]].push_back(i);
    }
    for(int i=1;i<=2*n;i++){
        if(i==nums[tar[i]][0])cout<<nums[tar[i]][1]<<' ';
        else cout<<nums[tar[i]][0]<<' ';
    }
    return 0;
}