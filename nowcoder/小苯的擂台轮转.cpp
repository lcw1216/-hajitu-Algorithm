#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;cin>>T;
    while(T--){
        int n,k;cin>>n>>k;
        deque<int>dq;int tp;
        for(int i=0;i<n;i++){cin>>tp;dq.push_back(tp);}
        while(k--){
            int l = dq.front();dq.pop_front();
            int r = dq.front();dq.pop_front();
            dq.push_front(max(l,r));
            dq.push_back(min(l,r));
        }
        while(!dq.empty()){cout<<dq.front()<<' ';dq.pop_front();}
        cout<<endl;
    }
    return 0;
}