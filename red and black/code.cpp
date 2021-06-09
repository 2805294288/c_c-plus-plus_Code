#include<bits/stdc++.h>

using namespace std;
int DFS(vector<vector<char>>& v, int x, int y, int m, int n, int& count)
{
    if(x == m || y == n || v[x][y] == '#' || x < 0 || y < 0)
    {
        return 0;
    }
    
    count++;
    v[x][y] = '#';
    
    DFS(v,x-1,y,m,n,count);
    DFS(v,x,y+1,m,n,count);
    DFS(v,x+1,y,m,n,count);
    DFS(v,x,y-1,m,n,count);
    
    return count;
}

int main()
{
    int m = 0;
    int n = 0;
    while(cin>>m>>n)
    {
        getchar();
        int x = 0;
        int y = 0;
        vector<vector<char>> v(m,vector<char>(n));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin>>v[i][j];
                if(v[i][j] == '@')
                {
                    x = i;
                    y = j;
                }
            }
        }
        int count = 0;
        DFS(v,x,y,m,n,count);
        cout << count << endl;
    }
    return 0;
}