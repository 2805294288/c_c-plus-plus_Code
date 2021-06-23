class Solution {
public:
    void Func(vector<int>& nums, vector<int>& used)
    {
        if(part.size() == nums.size())
        {
            ret.push_back(part);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(used[i] == 1)
            {
                continue;
            }
            used[i] = 1;
            part.push_back(nums[i]);
            Func(nums,used);
            part.pop_back();
            used[i] = 0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> used(nums.size(),0);
        Func(nums,used);
        return ret;
    }
private:
    vector<vector<int>> ret;
    vector<int> part;
};