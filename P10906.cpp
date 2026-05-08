#include<bits/stdc++.h>
using namespace std;
int main(){
    string ts = "kfdhtshmrw4nxg#f44ehlbn33ccto#mwfn2waebry#3qd1ubwyhcyuavuajb#vyecsycuzsmwp31ipzah#catatja3kaqbcss2th";
    int tlen = ts.length(),ans = 0;
    for(int len=8;len<=16;len++){
        for(int pos=0;pos<=tlen-len;pos++){
            bool f=false,n=false;
            for(int i=pos;i<pos+len;i++){
                if(ts[i]>='0'&&ts[i]<='9')n=true;
                else if(ts[i]<'a'||ts[i]>'z')f=true;
            }
            if(n&&f)ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}