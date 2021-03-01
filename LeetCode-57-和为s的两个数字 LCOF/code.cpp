class Solution {
public: //最开始想到用暴力办法，结果超时。后面想到用用双指针办法。
    vector<int> twoSum(vector<int>& nums, int target) {
        int point = nums.size();
        vector<int> nums_2(2, 0);
        for (int i = 0; i < nums.size(); i++)//既然是有序，那么结果肯定在nums里面有比target大的数字位置之前。
        {
            if (nums[i] >= target)
            {
                point = i;
                break;
            }
        }
        int head = 0, tail = point - 1;//创建前后双指针。
        while (head < tail)
        {
            if (nums[head] + nums[tail] < target)//如果前后加起来比target小head++；           
                head++;
            else if (nums[head] + nums[tail] > target)//如果前后加起来比target大tail--；
                tail--;
            else
            {
                nums_2[0] = nums[head];
                nums_2[1] = nums[tail];
                break;
            }
        }
        return nums_2;
    }
};