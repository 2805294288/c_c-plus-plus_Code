class Solution {
public:
    void Group(int n,int k,int index)
    {
        if(path.size() == k)
        {
            ret.push_back(path);
            return;
        }

        for(int i = index; i<=n - (k-path.size()) + 1; i++)//剪枝发，去掉不必要的步骤
        {
            path.push_back(i);
            Group(n,k,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        Group(n,k,1);
        return ret;
    }
private:
    vector<vector<int>> ret;
    vector<int> path;
};