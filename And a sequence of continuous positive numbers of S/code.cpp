class Solution {
public:
    void Func(int& sum, int n, int state)
    {
        if(n > sum)
        {
            return;
        }
        
        if(n == sum && path.size() >= 2)
        {
            int i = 0;
            for(i = 0; i < path.size() - 1; i++)
            {
                if(path[i]+1 != path[i+1])
                {
                    break;
                }
            }
            
            if(i == path.size() - 1)
            {
                ret.push_back(path);
            }
            return;
        }
        
        for(int i = state; i <= sum/2+1 && n <= sum; i++)
        {
            path.push_back(i);
            Func(sum,n+i,i+1);
            path.pop_back();
        }
    }
    vector<vector<int> > FindContinuousSequence(int sum) {
        int n = 0;
        Func(sum,n,1);
        return ret;
    }
private:
    vector<vector<int>> ret;
    vector<int> path;
};