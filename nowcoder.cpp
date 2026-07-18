#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;cin>>T;
    while(T--){
        int ax,ay,bx,by,cx,cy,dx,dy;
        cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy;
        bool ans = (ay-by)*(cx-dx)==(cy-dy)*(ax-bx);
        if(ans)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}