class Solution {
public:
    void DFS(vector<vector<int>>& used, int i, int j,int& x, int& y, vector<vector<char>>& board)
    {
        if(i < 0 || j < 0 || i >= x || j >= y || board[i][j] == 'X' || used[i][j] == 1)
        {
            return;
        }

        used[i][j] = 1;

        DFS(used,i-1,j,x,y,board);
        DFS(used,i,j+1,x,y,board);
        DFS(used,i+1,j,x,y,board);
        DFS(used,i,j-1,x,y,board);
    }

    void solve(vector<vector<char>>& board) {
        int x = board.size();
        int y = board[0].size();
         
        vector<vector<int>> used(x,vector<int>(y,0));

        for(int j = 0; j < y; j++)
        {
            if(board[0][j] == 'O')
            DFS(used,0,j,x,y,board);
            if(board[x-1][j] == 'O')
            DFS(used,x-1,j,x,y,board);
        }

        for(int i = 0; i < x; i++)
        {
            if(board[i][0] == 'O')
            DFS(used,i,0,x,y,board);
            if(board[i][y-1] == 'O')
            DFS(used,i,y-1,x,y,board);
        }

        for(int i = 0; i < x; i++)
        {
            for(int j = 0; j < y; j++)
            {
                if(used[i][j] == 1)
                {
                    board[i][j] = 'O';
                }
                else
                {
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};