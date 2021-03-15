class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int size = arr.size();
        //对数组进行一遍遍历并判断
        //时间复杂度O（n）
        if(size < 3)//山脉的条件是个数必须大于等于3个
        {
            return false;
        }
        //先从前往后找后面一个大于前一个的位置。
        int index = 0;
        int state_1 = 0;//证明数组不是降序数组
        for(int i=0; i<size-1; i++)
        {
            if(arr[i]>arr[i+1])
            {
                index=i;
                break;
            }
            else if(arr[i+1]==arr[i])//遇到相等的直接返回false
            {
                return false;
            }
            state_1=1;
        }

        int state_2 = 0;//证明数组不是一个升序数组
        for(int i=index; i<size-1; i++)
        {
            if(arr[i] <= arr[i+1])
            {
                return false;
            }
            state_2 = 1;
        }

        if(state_1 == 1 && state_2 ==1)//里面既有升序也有降序且符合条件
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
};