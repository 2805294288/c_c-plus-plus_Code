//第一种方法，把0到n的数字加一遍，减去数组里面的数字，剩下的就是少的。
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int Size = nums.size();
        int sum_1 = 0;
        for (int i = 0; i <= Size; i++) {
            sum_1 += i;
        }
        for (int i = 0; i < Size; i++) {
            sum_1 -= nums[i];
        }
        return sum_1;
    }
};