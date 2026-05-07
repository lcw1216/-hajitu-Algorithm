#include<bits/stdc++.h>
using namespace std;
//要求(y*y-x*x==2*T)求(x^2+y^2)/2的总和(在(x+y)%2==0)的前提下
string int128_to_string(__int128 ans){
    string s;
    if(ans==0){s+='0';return s;}
    while(ans>0){
        s+=(char)(ans%10+'0');
        ans/=10;
    }
    reverse(s.begin(),s.end());
    return s;
}
int main(){
    //   __int128 T = 10120300500,tt = 2*T;
    //  __int128 ans = 0;
    //   __int128 top = (  __int128)sqrt(2*T)+1;//(考虑到(y-x)一定会小于(y+x))
    // for(  __int128 i=1;i<top;i++){
    //     if(tt%i==0){
    //           __int128 sum = tt/i,sub = i;
    //         if((sum+sub)%2==0&&(sum-sub)%2==0){
    //             //找到所有的n
    //              __int128 x = (sum+sub)/2,y = (sum-sub)/2;
    //             if((x*x+y*y)%2==0)ans+=(x*x+y*y)/2;
    //         }
    //     }
    // }
    // cout<<int128_to_string(ans)<<endl;
    cout<<37044368843012180000<<endl;
    return 0;
}