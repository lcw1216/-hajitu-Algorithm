#include<bits/stdc++.h>
using namespace std;
int main(){
    int N = INT_MAX;
    int ans = 0,res = 0,dp = 0;
    for(int i=1;i<N;i++){
        int tmp = dp+i;
        ans+=tmp;
        dp = tmp;
        if(ans>20230610){res=i-1;break;}
    }
    cout<<res<<endl;
    return 0;
}