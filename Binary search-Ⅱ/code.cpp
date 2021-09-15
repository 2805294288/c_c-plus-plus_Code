class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 如果目标值存在返回下标，否则返回 -1
     * @param nums int整型vector 
     * @param target int整型 
     * @return int整型
     */
    int search(vector<int>& nums, int target) {
        if(nums.size() <= 0)
        {
            return -1;
        }
        
        int head = 0;
        int tail = nums.size() - 1;
        while(head <= tail)
        {
            int mid = (head + tail) / 2;
            if(nums[mid] >= target)
            {
                tail = mid - 1;
            }
            else
            {
                head = mid + 1;
            }
        }
        if(nums[head] == target)
        {
            return head;
        }
        return -1;
    }
};