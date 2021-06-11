#include<bits/stdc++.h>

using namespace std;

void Find(int m, int n, vector<vector<int>>& v, vector<vector<double>>& ret)
{
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(!(i == 1 &&  j == 1))
            {
                if(v[i][j] == 1)
                {
                    ret[i][j] = 0;
                    continue;
                }
                ret[i][j] = ret[i-1][j] * (j == n ? 1:0.5) + ret[i][j-1] *(i == m ? 1:0.5);
            }
        }
    }
}

int main()
{
    int m = 0;
    int n = 0;
    while(cin>>m>>n)
    {
        vector<vector<int>> v(m+1, vector<int>(n+1,0));
        int k =0;
        cin>>k;  
        int x = 0;
        int y = 0;
        
        while(k--)
        {
            cin>>x>>y;
            v[x][y] = 1;
        }
        
        vector<vector<double>> ret(m+1, vector<double>(n+1,0));
        ret[1][1] = 1.0;
        Find(m,n,v,ret);
        cout << fixed << setprecision(2) << ret[m][n] << endl;
    }
    return 0;
}