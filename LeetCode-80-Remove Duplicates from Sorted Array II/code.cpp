//这个题看大神做很巧妙地解决了


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0;//先定义新数组长度为0
        for(int i=0; i<nums.size(); i++)//对原数组进行遍历
        {
            if(len<2 || nums[i] != nums[len-2])//1.当新数组长度小于2则直接入 2.当原数组里面的值与新数组中len-2位置值不同时则入。
            {
                nums[len++]=nums[i];
            }
        }
        return len;
    }
};