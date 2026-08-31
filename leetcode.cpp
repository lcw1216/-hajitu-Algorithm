#include <bits/stdc++.h>
using namespace std;
using ll = long long;


    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
       vector<pair<int,int>> st;
       int n = nums.size();
       for(int i=0;i<n;i++) st.push_back({nums[i],i});
       sort(st.begin(),st.end());
    //    for(int i=0;i<n;i++)cout<<st[i].first<<' ';
    //    cout<<endl;
       vector<pair<int,int>> pos;
       int l = 0;
       for(int i=1;i<n;i++){
        if(st[i].first>st[i-1].first+limit){
            pos.push_back({l,i-1});
            l = i;
        }
        if(i==n-1)pos.push_back({l,i});
       }
       for(int i=0;i<(int)pos.size();i++){
        int lt = pos[i].first,rt = pos[i].second;
        // cout<<lt<<' '<<rt<<endl;
        vector<int> tmp;
        for(int j=lt;j<=rt;j++)tmp.push_back(st[j].second);
        sort(tmp.begin(),tmp.end());
        for(int j=lt;j<=rt;j++)st[j].second=tmp[j-lt];
       }
       for(int i=0;i<n;i++){
        int p = st[i].second;
        nums[p] = st[i].first;
       }
       return nums;
    }



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,limit;cin>>n>>limit;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int> ans = lexicographicallySmallestArray(a,limit);
    for(int i=0;i<n;i++)cout<<ans[i]<<' ';
    return 0;
}