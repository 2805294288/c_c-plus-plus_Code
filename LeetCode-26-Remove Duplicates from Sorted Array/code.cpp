class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        int slow = 0;
        int count = 1;
        int fast = 1;

        while(fast < nums.size())
        {
            if(nums[fast] != nums[slow])
            {
                nums[count] = nums[fast];
                slow++;
                count++;
                fast++;
            }
            else
            {
                fast++;
            }
        }

        return count;
    }
};