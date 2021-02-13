class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> arr;//先创建一个vector容器arr；
        for (int i = 0; i < n; i++) {
            arr.push_back(nums[i]);//分别进行尾插第i个和第i+n个。
            arr.push_back(nums[i + n]);
        }
        return arr;
    }
};