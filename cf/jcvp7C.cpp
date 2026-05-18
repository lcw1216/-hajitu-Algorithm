#include<bits/stdc++.h>
using namespace std;
struct ps{int l,r,id;};
bool sort_way(const ps&a,const ps&b){return a.l<b.l;}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    vector<ps>pl;
    for(int i=0;i<n;i++){
        ps tmp;cin>>tmp.l>>tmp.r;
        tmp.id = i+1;
        pl.push_back(tmp);
    }
    sort(pl.begin(),pl.end(),sort_way);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;
    vector<int> res;
    int pt=0,cur=0;
    while(true){
        while(pt<n&&pl[pt].l<=cur){minheap.emplace(pl[pt].r,pl[pt].id);pt++;}
        while(!minheap.empty()&&minheap.top().first<cur)minheap.pop();
        if(minheap.empty())break;
        int id = minheap.top().second;
        minheap.pop();
        res.push_back(id);
        cur++;
    }
    cout<<res.size()<<endl;
    for(int i=0;i<(int)res.size();i++) cout<<res[i]<<' ';
    return 0;
}