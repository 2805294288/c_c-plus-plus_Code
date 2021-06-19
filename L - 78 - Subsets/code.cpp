class Solution {
public:
    void Func(vector<int>& nums, int state)
    {
        ret.push_back(path);

        if(state >= nums.size())
        {
            return;
        }

        for(int i = state; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            Func(nums,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        Func(nums,0);
        return ret;
    }
private:
    vector<vector<int>> ret;
    vector<int> path;
};