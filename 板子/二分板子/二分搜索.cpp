#include<bits/stdc++.h>
using namespace std;
bool check(){

}
int bs(vector<int> nums,int tar){
    int l,r;
    while(l<r){
        int mid = (l+r+1)/2;
        if(check())l=mid;
        else r=mid-1;
    }
    return l;
}
int main(){
    vector<int> nums(10);
    for(int i=0;i<10;i++)nums[i]=i;
    int pos = bs(nums,5);
    cout<<pos<<endl;
    return 0;
}