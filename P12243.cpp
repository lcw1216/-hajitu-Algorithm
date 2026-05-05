#include<bits/stdc++.h>
using namespace std;
bool check(int num){
    for(int i=1;i*i<=num;i++){
        if(num%i==0){
            int j = num/i;
            vector<int> cts(10,0),ctn(10,0);
            string si = to_string(i);
            string sj = to_string(j);
            string sn = to_string(num);
            for(int k=0;k<(int)si.length();k++)cts[(int)(si[k]-'0')]++;
            for(int k=0;k<(int)sj.length();k++)cts[(int)(sj[k]-'0')]++;
            for(int k=0;k<(int)sn.length();k++)ctn[(int)(sn[k]-'0')]++;
            bool out = true;
            for(int k=0;k<10;k++)if(cts[k]!=ctn[k])out=false;
            if(out)return true;
        }
    }
    return false;
}
int main(){
    // int ans = 0;
    // for(int num=500001;num<=1000000;num++){
    //     if(check(num)){ans++;cout<<num<<' ';}
    // }
    // cout<<endl;
    // cout<<ans<<endl;
    cout<<590<<endl;
    return 0;
}
//506+84=590