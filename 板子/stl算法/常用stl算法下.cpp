#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){return a<b;}
//merge
//lower_bound
//upper_bound
//next_permutation
//partial_sum
int main(){
    vector<int> v1 = {1,3,5};
    vector<int> v2 = {2,4,6};
    vector<int> v3(v1.size()+v2.size());
    //merge添加的排序规则要和v1v2一样
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin(),cmp);//merge:两个已排序序列有序合并到第三个序列的插入迭代器上
    auto it1 = lower_bound(v1.begin(),v1.end(),3);//lower_bound: 使用二分查找搜索第一个不小于x的值
    auto it2 = upper_bound(v1.begin(),v1.end(),3);//upper_bound: 使用二分查找搜索第一个大于x的值
    //返回迭代器
    int pos1 = it1-v1.begin(),pos2 = it2-v1.begin();
    cout<<pos1<<' '<<pos2<<endl;
    vector<int> v = v1;
    do{
        for(int n:v)cout<<n<<' ';
        cout<<'\n';
        //上一个排列使用prev_permutation
    }while(next_permutation(v.begin(),v.end()));//next_permutation:将当前排列更改为全排列中的下一个排列
    // for(auto n:v3)cout<<n<<' ';
    vector<int> input = {1,2,3,4,5};
    vector<int> res(input.size());
    partial_sum(input.begin(),input.end(),res.begin());//partial_sum: 统计前缀和
    for(int i=0;i<(int)res.size();i++)cout<<res[i]<<' ';
    return 0;
}