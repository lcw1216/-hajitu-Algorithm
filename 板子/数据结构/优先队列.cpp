#include<bits/stdc++.h>
using namespace std;
//结构体自定义
struct student{
    int id;
    int score;
};
struct cmp{
    bool operator()(const student& a,const student& b){
        return a.score>b.score;
    }
};
int main(){
    priority_queue<int>bpq;//最大堆，每次入队自动将最大值放在队头
    priority_queue<int,vector<int>,greater<int>> mpq;//最小堆，和最大堆相反
    for(int i=1;i<=10;i++){
        bpq.push(i);
        mpq.push(i);
    }
    while(!bpq.empty()){cout<<bpq.top()<<' ';bpq.pop();}
    cout<<endl;
    while(!mpq.empty()){cout<<mpq.top()<<' ';mpq.pop();}
    return 0;
}