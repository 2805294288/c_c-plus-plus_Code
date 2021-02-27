class Solution {
public:
    int thirdMax(vector<int>& nums) {
        //先找最小的。
        int min = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < min) {
                min = nums[i];
            }
        }
        //找最大的
        int Firstmax = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > Firstmax) {
                Firstmax = nums[i];
            }
        }
        //找第二大的
        int Secendmax = min;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]<Firstmax && nums[i]>Secendmax) {
                Secendmax = nums[i];
            }
        }
        //找第三大的
        int ThirdMax = min;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]<Secendmax && nums[i]>ThirdMax) {
                ThirdMax = nums[i];
            }
        }
        if (ThirdMax == Secendmax || ThirdMax == Firstmax || Firstmax == Secendmax)
            return Firstmax;
        else
            return ThirdMax;
    }
};