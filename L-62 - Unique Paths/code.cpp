class Solution {
public:
//动态规划的做法
//动规5部曲
//1.先确定用几维数组（二维）
//2.确定动态规划方程
//3.确定每个位置代表的含义（当前位置代表到当前位置一共有多少种路径，因为是从上面和左边来的，所以计算上面的路径个数+左边的路径个数）
//4.遍历方式 从前往后遍历
//5.打印对应位置应该的值是多少
//初始化的时候，由于最上面和最左边的方式都只是只有一种。
    int uniquePaths(int m, int n) {
        vector<vector<int>> ret(m,vector<int>(n,1));
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                ret[i][j] = ret[i-1][j] + ret[i][j-1];
            }
        }
        return ret[m-1][n-1];
    }
};