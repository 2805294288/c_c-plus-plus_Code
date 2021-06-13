#include<bits/stdc++.h>

using namespace std;
void Func(vector<vector<int>> &v,vector<int>& path,int index, int& n,int& m,int sum)
{
    if(sum > m)//剪枝 如果sum>m,则已经没有进去的必要了。
    {
        return;
    }
    
     if(sum == m)//当 sum == m 时说明满足条件则入进去
     {
         v.push_back(path);
         return;
     }
    
    for(int i = index; i <= n; i++)//每次从index开始
    {
        path.push_back(i);
        Func(v,path,i+1,n,m,sum+i);//进入递归 进入的时候，index 从 当前的 i+1 的位置开始
        path.pop_back(); //并将数组里面的元素删除掉
    }
}

int main()
{
    int n = 0;
    int m = 0;
    while(cin>>n>>m)
    {
        vector<vector<int>> v;
        vector<int> path;
        int sum = 0;
        Func(v,path,1,n,m,sum);//经典回溯题
        for(auto& ve:v)
        {
            for(auto& i:ve)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}