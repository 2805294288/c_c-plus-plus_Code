class Solution {
public:
    /**
     * find median in two sorted array
     * @param arr1 int整型vector the array1
     * @param arr2 int整型vector the array2
     * @return int整型
     */
     
    // 题解：此题我用了一个巧妙解法，因为两个数组等长，所及只可能是偶数情况。只需要遍历一个数组长度即可。
    // 因为是有序，且空间复杂度为O（1）所以额外的数组空间，所以就可以将两个数组同时遍历，记录第N小的数字。
    int findMedianinTwoSortedAray(vector<int>& arr1, vector<int>& arr2) {
        int size = arr1.size();
        int number = 0;
        int i = 0;
        int j = 0;
        while(size--)
        {
            if(arr1[i] < arr2[j])
            {
                number = arr1[i];
                i++;
                
            }
            else
            {
                number = arr2[j];
                j++;
            }
        }
        return number;
    }
};