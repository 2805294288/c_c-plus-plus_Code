class Solution {
public:
    //贪心算法例题
    //首先要保证是搬动序列，即后一个减当前值与当前值减去前一个相乘是一个负数。
    int wiggleMaxLength(vector<int>& nums) {
        int preDiff = 0;//保存前一个是负数或者正数
        int curDiff = 0;//保存当前值与后一个差值是正数或者负数
        int ret = 1;//初始化结果为1是因为如果数组里面只有一个数字则也算一种，并且减到最后，后一个数字算是搬动序列中的一员。

        for(int i=0; i<nums.size()-1; i++)
        {
            curDiff = nums[i+1] - nums[i];
            if(preDiff >=0 && curDiff < 0 || preDiff <= 0 && curDiff > 0)//preDiff=0是为了满足初始preDiff=0的情况。
            {
                ret ++;
                preDiff = curDiff;//当满足情况以后将preDiff进行更新
            }
        }
        return ret;
    }
};