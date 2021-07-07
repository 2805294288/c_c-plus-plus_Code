class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto& n:nums)
        {
            sum += n;
        }
        if(sum % 2 != 0 || nums.size() < 2)
        {
            return false;
        }

        int target = sum / 2;
        vector<vector<bool>> ret(nums.size(),vector<bool>(target+1,false));
        
        if (nums[0] <= target) {
            ret[0][nums[0]] = true;
        }

        for(int i = 1; i < nums.size(); i++)
        {
            for(int j = 0; j <= target; j++)
            {
                ret[i][j] = ret[i-1][j];

                if(j >= nums[i])
                {
                    ret[i][j] = ret[i-1][j] || ret[i-1][j-nums[i]];
                }
            }
        }
        return ret[nums.size()-1][target];
    }
};