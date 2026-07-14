#include<bits/stdc++.h>
using namespace std;
vector<int> to_b(vector<int> w,vector<int> v,int W){
    int N = w.size();
    vector<int> b(W+1,0);
    for(int i=0;i<N;i++){
        for(int j=W;j>=w[i];j--) b[j] = max(b[j],b[j-w[i]]+v[i]);
    }
    return b;
}
//背包板子
int main(){
    int N,W;cin>>N>>W;
    vector<int> w(N),v(N);
    for(int i=0;i<N;i++)cin>>w[i]>>v[i];
    vector<int> b = to_b(w,v,W);
    cout<<b.back()<<endl;
    return 0;
}