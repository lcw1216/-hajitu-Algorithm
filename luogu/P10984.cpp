//已知数码管状态 ,,可能本该亮的灯处于熄灭状态
//将18个数每个进行10次匹配，将每个数的可能数总数相乘
#include<bits/stdc++.h>
using namespace std;
vector<string> ex= {
    "1111110", // 0
    "0110000", // 1
    "1101101", // 2
    "1111001", // 3
    "0110011", // 4
    "1011011", // 5
    "1011111", // 6
    "1110000", // 7
    "1111111", // 8
    "1111011"  // 9
};
vector<string> nums = {
    "0000011", "1001011", "0000001", "0100001", "0101011",
    "0110110", "1111111", "0010110", "0101001", "0010110",
    "1011100", "0100110", "1010000", "0010011", "0001111",
    "0101101", "0110101", "1101010"
};
//判断逻辑，在nums中没有ex中有的不影响，在ex中没有的nums有做判断
int to_sum(string s){
    int ans = 0;
    for(int i=0;i<10;i++){
        bool add = true;
        for(int j=0;j<7;j++)
            if(ex[i][j]=='0'&&s[j]=='1') add = false;
        if(add)ans++;
    }
    return ans;
}
int main(){
    // int ans = 1;
    // for(int i=0;i<nums.size();i++){
    //      ans*=to_sum(nums[i]);
    //      cout<<to_sum(nums[i])<<endl;
    // }
    // cout<<ans<<endl;
    cout<<254016000<<endl;
    return 0;
}