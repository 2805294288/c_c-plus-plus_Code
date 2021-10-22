class Solution {
public:
    //既然原本数组是非递减的。则某一处旋转以后，是两个非递减的有序区间。
    int minNumberInRotateArray(vector<int> rotateArray) {
        int size =  rotateArray.size();
        int head = 0;
        int tail = size - 1;
        int mid = 0;
        while(head < tail)
        {
            mid = (head + tail) / 2;
            if(rotateArray[mid] < rotateArray[tail])//将中间和结尾作为两个非递减序列的结尾。如果中间的比结尾的大，那么小的就在中间的右边。
            {
                tail = mid;//如果小的话，可能就是本身
            }
            else if(rotateArray[mid] > rotateArray[tail])//中间的的小则在左边
            {
                head = mid + 1;//如果是大于，则肯定不是mid 则可以加1
            }
            else
            {
                tail = tail - 1;//如果是等于，不能确定是在左边还是右边，则后一个减一
            }
        }
        return rotateArray[head];
    }
};