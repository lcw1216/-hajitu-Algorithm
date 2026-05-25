#include<bits/stdc++.h>
using namespace std;
struct node{
    string name;
    int ct,time;
};
bool sw(node a,node b){
    if(a.ct>b.ct)return true;
    else if(b.ct>a.ct)return false;
    else {
        if(a.time<b.time)return true;
        else return false;
    }
    return true;
}
int main(){
    int n,m;cin>>n>>m;
    vector<node>st;
    for(int t=0;t<n;t++){
        node nw;
        cin>>nw.name;
        nw.time=0;nw.ct=0;
        for(int i=0;i<m;i++){
            int tp;cin>>tp;
            if(tp!=0)nw.ct++;
            nw.time+=tp;
        }
        st.push_back(nw);
    }
    sort(st.begin(),st.end(),sw);
    vector<int> nt(n);
    int ntt = 1;nt[0]=1;
    for(int i=1;i<n;i++){
        if(st[i].ct!=st[i-1].ct||st[i].time!=st[i-1].time){
            ntt=i+1;
        }
        nt[i]=ntt;
    }
    for(int i=0;i<n;i++){
        cout<<nt[i]<<' '<<st[i].name<<' '<<st[i].ct<<' '<<st[i].time<<endl;
    }
    return 0;
}