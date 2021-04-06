class Solution {
public:
    int singleNumber(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int len = 0;
        int size = nums.size()-2;
        while(len < size)
        {
            if(nums[len] != nums[len+2])
            {
                return nums[len];
            }
            else
            {
                len += 3;
            }
        }

        return nums[nums.size()-1];    
    }
};