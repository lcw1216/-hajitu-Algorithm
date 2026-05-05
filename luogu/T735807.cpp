#include<bits/stdc++.h>
using namespace std;
vector<bool> mouth(13,false);
bool check(int y,int m,int d){
    vector<int> ct(10,0);
    string ys = to_string(y),ms = to_string(m),ds = to_string(d);
    for(int i=0;i<(int)ys.length();i++)ct[(int)(ys[i]-'0')]++;
    for(int i=0;i<(int)ms.length();i++)ct[(int)(ms[i]-'0')]++;
    for(int i=0;i<(int)ds.length();i++)ct[(int)(ds[i]-'0')]++;
    int tar = -1;
    for(int i=0;i<10;i++)if(ct[i]!=0){tar=ct[i];break;}
    for(int i=0;i<10;i++)if(ct[i]!=0&&ct[i]!=tar)return false;
    return true;
}
bool check_luna(int year){
    if(year%400==0)return true;
    else if(year%100==0)return false;
    else if(year%4==0)return true;
    return false;
}
int main(){
    vector<int>mt={1,3,5,7,8,10,12};
    for(int i=0;i<7;i++)mouth[mt[i]]=true;
    int ct = 0;
    for(int j=9;j<=12;j++){
            int start;if(j==9)start=9;else start=1;
            for(int k=start;k<=30;k++)if(check(2239,j,k))ct++;
            if(mouth[j]&&check(2239,j,31))ct++;
        }
    for(int i=2240;i<9876;i++){
        for(int j=1;j<=12;j++){
            if(j==2){for(int k=1;k<=28;k++){if(check(i,j,k))ct++;}
                if(j==2&&check_luna(i))if(check(i,j,29))ct++;}
            else for(int k=1;k<=30;k++)if(check(i,j,k))ct++;
            if(mouth[j]&&check(i,j,31))ct++;
        }
    }
    cout<<ct<<endl;
    return 0;
}