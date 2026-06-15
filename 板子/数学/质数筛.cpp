#include<bits/stdc++.h>
using namespace std;
const int TOP = 1e6+1;
vector<int> ss(){
    vector<int> ans;
    vector<bool> bl(TOP,true);
    for(int i=2;i<TOP;i++){
        if(bl[i]){
            ans.push_back(i);
            if(i>TOP/i)continue;
            for(int j=i*i;j<TOP;j+=i)bl[j]=false;
        }
    }
    return ans;
}
int main(){
    int n;cin>>n;
    vector<int> nums = ss();
    int len = nums.size();
    for(int i=0;i<len;i++)cout<<nums[i]<<' ';
    return 0;
}