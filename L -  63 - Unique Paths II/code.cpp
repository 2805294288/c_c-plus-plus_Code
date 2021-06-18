class Solution {
public:
 //先确定dp数组 二维数组
 //确定递推公式以及下标含义 当前位置i的值等于上面和左边路径个数综合
 //如果当前位置有障碍物则当前位置的方法为0.没有路径可以经过
 //dp数组如何初始化
 //确定遍历顺序
 //举例推导dp数组
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> ret(m+1,vector<int>(n+1,0));
        ret[0][1] = 1;
        for(int i = 1; i < m+1; i++)
        {
            for(int j = 1; j < n+1; j++)
            {
                if(obstacleGrid[i-1][j-1] != 1 )
                {
                    ret[i][j] = ret[i-1][j] + ret[i][j-1];                    
                }
                else
                {
                    ret[i][j] = 0;
                }
            }
        }
        return ret[m][n];
    }
};