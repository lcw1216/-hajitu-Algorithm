#include<iostream>
using namespace std;
int main() {
    string ans [] = {
        "5484660609", // 双引号中替换为 A 题的答案
        "947293", // 双引号中替换为 B 题的答案
    };
    char T;
    cin >> T;
    cout << ans[T - 'A'] << endl;
    return 0;
}
//素数筛和简单dp
// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// int main(){
//     string s;
//     for(ll i=1;i<=2023;i++){
//         string t = to_string(i);
//         s+=t;
//     }
//调了半天原来是特么溢出了
//     // s = "202320232023";
//     ll len = s.length();
//     // cout<<len<<endl;
//     vector<ll> dp3(len,0),dp2(len,0),dp0(len,0),dpf(len,0);
//     dp3[len-1]=1;
//     for(ll i=len-2;i>=0;i--){
//         dp3[i]=dp3[i+1];dp2[i]=dp2[i+1];dp0[i]=dp0[i+1];dpf[i]=dpf[i+1];
//         if(s[i]=='3')dp3[i]++;
//         else if(s[i]=='2'){dp2[i]+=dp3[i];dpf[i]+=dp0[i];}
//         else if(s[i]=='0')dp0[i]+=dp2[i];
//     }
//     // for(int i=len-1;i>=0;i--)
//     //     cout<<dp3[i]<<' '<<dp2[i]<<' '<<dp0[i]<<' '<<dpf[i]<<' '<<s[i]<<endl;
//     cout<<dpf[0]<<endl;
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// vector<ll> t_sss(ll up){
//     vector<bool> bl(up,true);
//     vector<ll> sss;
//     for(ll i=2;i<up;i++){
//         if(bl[i]){
//             sss.push_back(i);
//             for(ll j=i*i;j<up;j+=i)bl[j]=false;
//         }
//     }
//     return sss;
// }
// //p*q的平方，对于所有相乘符合范围的,ans++;
// int main(){
//     ll a = 2333,b = 23333333333333;
//     ll up = sqrt(b)+10;
//     vector<ll> nums = t_sss(up);//质数表已成
//     ll ans = 0,len = nums.size();
//     for(ll i=0;i<len;i++){
//         for(ll j=i+1;j<len;j++){
//             ll tmp = nums[i]*nums[j];
//             if(tmp<sqrt(a))continue;
//             else if(tmp>sqrt(b))break;
//             ans++;
//         }
//     }
//     cout<<ans<<endl;
//     return 0;
// }
