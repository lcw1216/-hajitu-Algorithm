#include<bits/stdc++.h>
using namespace std;
//find
//reverse
//unique
//erase
//sort
//nth_element
//binary_search
bool sort_way(int a,int b){return a<b;}
int main(){
    int n,tar;cin>>n>>tar;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    auto it = find(nums.begin(),nums.end(),tar);//find: 顺序查找
    int pos = it-nums.begin();
    reverse(nums.begin(),nums.end());//reverse: 反转数组
    //unique: 移除相邻重复元素
    //ps: 不改变容器大小，只是把不重复的元素向前移动，所以要使用erase或者pop_back()，最好在之前sort一遍
    auto last = unique(nums.begin(),nums.end());
    nums.erase(last,nums.end()); //erase: 删除这一部分的元素
    nums.erase(nums.begin()+2, nums.begin()+3);// 删除中间一部分，前闭后开
    sort(nums.begin(),nums.end(),sort_way);//stable_sort: 可以保证相等元素的相对顺序，但用处较少，一般使用普通sort
    it = nums.begin()+3;//第四个位置
    nth_element(nums.begin(),it,nums.end(),sort_way);//nth_element: 不做排序，只找到第n小的数,时间复杂度位O(n)
    cout<<*it<<endl;
    //binary_search要求必须按照规则排序，否则会报错
    bool bs = binary_search(nums.begin(),nums.end(),tar,sort_way);//binary_search: 不返回迭代器，只返回有没有找到

    for(auto num:nums)cout<<num<<' ';
}