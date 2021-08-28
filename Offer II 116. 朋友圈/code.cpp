class Solution {
public:
    void Set(int x1, int x2)
    {
        int root1 = Find(x1);//找当前结点的根节点
        int root2 = Find(x2);

        if(root1 != root2)//当两个跟结点不同的时候则进行合并
        {
            v1[root1] += v1[root2];
            v1[root2] = root1;
        }
    }

    int Find(int x)
    {
        int index = x;
        while(v1[index] >= 0)//只有当index位置的值 < 0的时候，说明是根节点。
        {
            index = v1[index];
        }
        return index;
    }

    int SetSize()
    {
        int count = 0;
        for(auto& n: v1)
        {
            if(n < 0)
            {
                count++;
            }
        }
        return count;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        v1.resize(n,-1);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(isConnected[i][j] == 1)
                {
                    Set(i,j);//并查集解法，如果i，j 位置为1 则表示是朋友免责进行合并。
                }
            }
        }

        int count = SetSize();
        return count;
    }
    
private:
    vector<int> v1;
};