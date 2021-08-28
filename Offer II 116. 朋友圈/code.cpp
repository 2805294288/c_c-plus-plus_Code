class Solution {
public:
    void Set(int x1, int x2)
    {
        int root1 = Find(x1);//�ҵ�ǰ���ĸ��ڵ�
        int root2 = Find(x2);

        if(root1 != root2)//����������㲻ͬ��ʱ������кϲ�
        {
            v1[root1] += v1[root2];
            v1[root2] = root1;
        }
    }

    int Find(int x)
    {
        int index = x;
        while(v1[index] >= 0)//ֻ�е�indexλ�õ�ֵ < 0��ʱ��˵���Ǹ��ڵ㡣
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
                    Set(i,j);//���鼯�ⷨ�����i��j λ��Ϊ1 ���ʾ������������кϲ���
                }
            }
        }

        int count = SetSize();
        return count;
    }
    
private:
    vector<int> v1;
};