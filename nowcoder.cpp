#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    int len = s.length();
    stack<char> st;
    for(int i=0;i<len-1;i++){
        if(s[i]=='I'||s[i]=='C')st.push(s[i]);
        else if(s[i]=='P'){
            bool pc = false;
            while(st.top()=='I'){
                if(!pc){pc=true;st.pop();}
                else {st.pop();st.push('C');}
            }
            if(st.empty())continue;
        }
    }
    
}