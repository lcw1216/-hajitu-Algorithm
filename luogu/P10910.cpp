#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    string s,sum;
    cin>>s>>sum;
    deque<char> l,r;
    for(int i=0;i<n;i++)l.push_back(s[i]);
    sort(sum.begin(),sum.end());
    for(int i=0;i<m;i++)r.push_back(sum[i]);
    string res;
    while((!l.empty()&&!r.empty())){
        if(l.front()<=r.front()){res.push_back(l.front());l.pop_front();}
        //这边存在一个细节，l没有排序后面可能会出现更小的所以相等时先输出l
        else {res.push_back(r.front());r.pop_front();}
    }
    while(!l.empty()){res.push_back(l.front());l.pop_front();}
    while(!r.empty()){res.push_back(r.front());r.pop_front();}
    cout<<res<<endl;
    return 0;
}