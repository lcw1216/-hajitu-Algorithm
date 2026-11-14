#include<bits/stdc++.h>
using namespace std;
int n;
vector<bool> bl;
vector<vector<int>> res;
vector<int> tmp;
void dfs(){
    if(tmp.size()==n){
        res.push_back(tmp);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(bl[i]){ 
            bl[i]=false; tmp.push_back(i);
            dfs();
            tmp.pop_back(); bl[i]=true;
        }
    }
    return ;
}
void np_dfs(vector<int> a){
    while(next_permutation(a.begin(), a.end())){
        for(int i=0;i<(int)a.size();i++)cout<<a[i]<<' ';
        cout<<endl;
    }
    return ;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    // cin>>n;
    // bl.resize(n+1,true);
    // dfs();
    // int len = res.size();
    // for(int i=0;i<len;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<res[i][j]<<' ';
    //     }
    //     cout<<"\n";
    // }
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)nums[i]=i;
    np_dfs(nums);
    return 0;
}