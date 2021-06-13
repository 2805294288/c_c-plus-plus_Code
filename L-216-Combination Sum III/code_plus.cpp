class Solution {
public:
    void Group(int& k, int& n, int sum, int index)
    {
        if(sum > n)//这里是和剪枝，size还没有达到K个 但是 sum已经比n大，则也不需要进去了。
        {
            return;
        }
        if(path.size() == k)
        {
            if(sum == n)
            {
                ret.push_back(path);  
            }
            return;
        }

        for(int i = index; i <= 9-( k - path.size()) + 1; i++)//剪枝，这里是个数剪枝。假如要k个数，则倒数第K个往后，就不需要去了。
        {
            sum += i;
            path.push_back(i);
            Group(k,n,sum,i+1);
            sum -= i;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int sum = 0;
        Group(k,n,sum,1);
        return ret;
    }
private:
    vector<vector<int>> ret;//将vector写成成员函数，就可以在类里面使用。当成全局的。
    vector<int> path;
};