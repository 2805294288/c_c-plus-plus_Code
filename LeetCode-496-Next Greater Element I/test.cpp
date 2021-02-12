class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //暴力法，先在nums2中找到nums1中元素存在的位置。
        //然后从这个位置开始往后遍历找大的。
        vector<int> a(nums1.size(), -1);//申请并初始化。
        int number = 0;
        int state = 0;
        for (int i = 0; i < nums1.size(); i++) {
            number = nums1[i];
            state = 0;
            for (int j = 0; j < nums2.size(); j++) {
                if (nums2[j] == number) {
                    for (int k = j + 1; k < nums2.size(); k++) {
                        if (nums2[k] > number) {
                            a[i] = nums2[k];
                            state = 1;
                            break;
                        }
                    }
                    if (state == 1) {
                        break;
                    }
                }
            }
        }
        return a;
    }
};