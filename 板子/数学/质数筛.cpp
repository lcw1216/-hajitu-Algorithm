#include<bits/stdc++.h>
using namespace std;
vector<int> sss(int top){
    vector<bool> bl(top+1);
    vector<int> res;
    if(top<2)return res;
    for(int i=2;i<=top;i++){
        if(!bl[i]){
            res.push_back(i);
            for(int j=i*i;j<=top;j+=i) bl[j]=false;
        }
    }
    return res;
}
int main(){
    int n;cin>>n;
    vector<int> nums = sss(n);
    int len = nums.size();
    for(int i=0;i<len;i++)cout<<nums[i]<<' ';
    return 0;
}