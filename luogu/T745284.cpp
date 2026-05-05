#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>>nums(n+1);
    for(int i=1;i<=n;i++){
        int len,tp;cin>>len;
        for(int j=0;j<len;j++){cin>>tp;nums[i].push_back(tp);}
    }
    vector<bool> bl(n+1,false);
    while(m--){
        int l;cin>>l;
        vector<int> ck(l),gt(l);
        for(int i=0;i<l;i++)cin>>ck[i];
        for(int i=0;i<l;i++)cin>>gt[i];
        bool ot = false;
        for(int i=0;i<l;i++){
            if(bl[ck[i]]){ot=true;break;}
            for(int j=0;j<nums[ck[i]].size();j++){
                if(!bl[nums[ck[i]][j]]){ot = true;break;}
            }
            if(ot)break;
        }
        if(ot){cout<<"Error"<<endl;continue;}
        for(int i=0;i<l;i++){
            if(gt[i]>=60){bl[ck[i]]=true;cout<<'P';}
            else cout<<'F';
        }
        cout<<endl;
    }
    return 0;
}