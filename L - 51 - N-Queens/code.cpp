class Solution {
public:
    bool Judge(vector<string>& board,int& n,int row,int L)
    {
        for(int i = 0; i < row; i++)//判断当前数列往上是否有‘Q’；因为往下的还没有走。
        {
            if(board[i][L] == 'Q')
            {
                return false;
            }
        }

        for(int i = row - 1, j = L - 1; i >= 0 && j >= 0; j--,i--)//判断当前45°往上是否有有‘Q’；因为往下的还没有走。
        {
            if(board[i][j] == 'Q')
            {
                return false;
            }
        }

        for(int i = row - 1, j = L + 1; i >= 0 && j < n; i--, j++)//判断当前135°往上是否有‘Q’；因为往下的还没有走。
        {
            if(board[i][j] == 'Q')
            {
                return false;
            }
        }

        return true;
    }
    void Func(vector<string>& board, int& n, int row)
    {
        if(row >= n)//当row到了第n行的时候说明已经走完了棋盘，且都满足了条件。
        {
            ret.push_back(board);
            return;
        }

        for(int i = 0; i < n; i++)//这里的i表示当前行row的第几列
        {
            if(Judge(board,n,row,i))//判断当前行当前列的位置是否满足n皇后条件是的话继续往下一层走，否则选取这一行的下一个位置。
            {
                board[row][i] = 'Q';//如果当前行用了则board棋盘当前位置放上‘Q’；
                Func(board,n,row + 1);走向下一层
                board[row][i] = '.';//走完以后将当前位置从新置为‘.’；选取下一个位置
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));//创建棋盘，一个vector开n行，每一行里面放长度为n个的字符串初始化为'.'；
        Func(board,n,0);//board表示棋盘，n代表几乘几，0表示从第0层开始
        return ret;
    }
private:
    vector<vector<string>> ret;//二维数组保存结果
};