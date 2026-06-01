#include<bits/stdc++.h>
using namespace std;
int binary_search(vector<int> nums,int tar){
    int l=0,r=nums.size();
    while(l<r){
        int mid = (l+r)/2;
        if(nums[mid]==tar)return mid;
        else if(nums[mid]<tar)l=mid+1;
        else r=mid;
    }
    return -1;
}
int main(){
    vector<int> nums(10);
    for(int i=0;i<10;i++)nums[i]=i;
    int pos = binary_search(nums,5);
    cout<<pos<<endl;
    return 0;
}