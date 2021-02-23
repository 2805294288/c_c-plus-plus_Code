class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // 先对 nums 升序排序
        int countZero = 0; // 用于计算 0 的个数

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                countZero++;
                continue;
            }

            int j = i + 1;

            if (j < nums.size()) {
                if (nums[j] == nums[i]) {
                    // 如果相邻两个元素相等，就不是顺子
                    return false;
                }

                int temp = nums[j] - nums[i];

                while (temp > 1) {
                    if (countZero == 0) {
                        // 0 如果不够用了，false
                        return false;
                    }

                    countZero--; // 相邻两个数的差距用 0 来弥补
                    temp--; // 差距减小 1
                }
            }
        }

        return true;
    }
};
