class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> q;
        
        int x = grid.size();
        int y = grid[0].size();

        for(int i = 0; i < x; i++)
        {
            for(int j = 0; j < y; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push(make_pair(i,j));
                }
            }
        }

        int count = 0;

        while(!q.empty())
        {
            int size = q.size();
            int flag = 0;

            while(size--)
            {
                auto cur = q.front();
                q.pop();

                if(cur.first-1 >= 0 && grid[cur.first-1][cur.second] == 1)
                {
                    grid[cur.first-1][cur.second] = 2;
                    flag = 1;
                    q.push(make_pair(cur.first-1,cur.second));
                }
                if(cur.second+1 < y && grid[cur.first][cur.second+1] == 1)
                {
                    grid[cur.first][cur.second+1] = 2;
                    flag = 1;
                    q.push(make_pair(cur.first,cur.second+1));
                }
                if(cur.first+1 < x  && grid[cur.first+1][cur.second] == 1)
                {
                    grid[cur.first+1][cur.second] = 2;
                    flag = 1;
                    q.push(make_pair(cur.first+1,cur.second));
                }
                if(cur.second-1 >= 0  && grid[cur.first][cur.second-1] == 1)
                {
                    grid[cur.first][cur.second-1] = 2;
                    flag = 1;
                    q.push(make_pair(cur.first,cur.second-1));

                }

            }
            if(flag == 1)
            {
                count++;
            }
        }

        for(int i = 0; i < x; i++)
        {
            for(int j = 0; j < y; j++)
            {
                if(grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return count;
    }
};







