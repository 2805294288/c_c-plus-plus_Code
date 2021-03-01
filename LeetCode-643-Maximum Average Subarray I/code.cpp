//经典滑动窗口做题法。
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        int maxsum = 0;
        int size = nums.size();
        for (int i = 0; i < k; i++)//先将前k个加起来。
        {
            sum += nums[i];
        }
        maxsum = sum;
        if (k == size)//如果k与size相同时，则直接返回平均值。
        {
            return (double)maxsum / k;
        }
        for (int i = k; i < size; i++)
        {
            sum = sum + nums[i] - nums[i - k];//从第k个位置开始，固定k长度的窗口，加第i个，减去第i-k个。
            maxsum = max(maxsum, sum);
        }
        return (double)maxsum / k;
    }
};