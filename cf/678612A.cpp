#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int ct_num(vector<int> nums,int n){
    int ct = 0,len = nums.size();
    bool inn = false;
    for(int i=0;i<len;i++){
        if(nums[i]==n&&!inn){inn=true;ct++;}
        if(nums[i]<n)inn=false;
    }
    return ct;
}
int main(){
    int n;cin>>n;
    vector<int> nums(n);
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){cin>>nums[i];mp[nums[i]]++;}
    vector<int> tp;
    for(const auto& pair:mp){tp.push_back(pair.first);}
    sort(tp.begin(),tp.end());
    int tol_ct = 1;
    for(int i=1;i<tp.size();i++) tol_ct+=ct_num(nums,tp[i]);
    cout<<tol_ct<<endl;
    return 0;
}