
//看似是个简单题其实有几个很特殊的测试案例。
//最易想到的是如果nums[i]>nums[i+1]的个数大于一个，则是错误的，但特殊测试案例如下。
//1.[3,4,2,3]  4>2，且只有一个。但是结果是false。加判定条件，nums[i]<nums[i-1]。保证是递增。
//2.[-1,4,2,3]  4>2,2>1,上面的思路返回false，但是结果是true。
//3.[5,7,1,8] 

//又以上特殊案例得，加判定条件：
//if(nums[i+1]<nums[i-1]){
            //     nums[i+1]=nums[i];
            // }
            // else{
            //     nums[i]=nums[i+1];
            // }  
//得正确答案。
bool checkPossibility(int* nums, int numsSize) {
    int cout = 0;
    if (numsSize < 3) {
        return true;
    }
    for (int i = 1; i < numsSize - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            cout++;
            if (nums[i + 1] < nums[i - 1]) {
                nums[i + 1] = nums[i];
            }
            else {
                nums[i] = nums[i + 1];
            }
        }
        if (nums[i] < nums[i - 1]) {
            cout++;
        }
        if (cout > 1) {
            return false;
        }
    }
    return true;
}