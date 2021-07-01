class Solution {
public:
    void DFS(vector<vector<char>>& grid, vector<vector<int>>& used, int i, int j, int& x, int &y)
    {
        if(i < 0 || j < 0 || i >= x || j >= y || grid[i][j] == '0' || used[i][j] == 1)
        {
            return;
        }

        used[i][j] = 1;

        DFS(grid,used,i-1,j,x,y);
        DFS(grid,used,i,j+1,x,y);
        DFS(grid,used,i+1,j,x,y);
        DFS(grid,used,i,j-1,x,y);

    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0)
        {
            return 0;
        }

        int x = grid.size();
        int y = grid[0].size();
        
        vector<vector<int>> used(x,vector<int>(y,0));
        
        int count = 0;

        for(int i = 0; i < x; i++)
        {
            for(int j = 0; j < y; j++)
            {
                if(grid[i][j] == '1' && used[i][j] == 0)//已经被之前的走过了，则就不在走了
                {
                    count++;
                    DFS(grid,used,i,j,x,y);
                }
            }
        }
        return count;
    }
};