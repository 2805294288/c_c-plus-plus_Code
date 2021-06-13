class Solution {
public:
    void Group(int& k, int& n, int sum, int index)
    {
        if(path.size() == k)
        {
            if(sum == n)
            {
                ret.push_back(path);  
            }
            return;
        }

        for(int i = index; i <= 9; i++)
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
    vector<vector<int>> ret;
    vector<int> path;
};