#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll curt = 789456,ct = 0;
    ll pret = 654321,tmd = 876543;
    for(ll i=0;i<901234;i++){
        if((500000-((curt-pret)/tmd))>=0)ct+=(500000-((curt-pret)/tmd));
        curt += 567890;
    }
    cout<<ct<<endl;
    return 0;
}