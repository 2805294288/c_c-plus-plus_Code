class Solution {
public:
    static bool com(const vector<int>& v1, const vector<int>& v2)//自定义数组里面的比较函数，比较两个数组里面第二个，按照升序排序
    {
        return v1[1] < v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() < 2)
        {
            return 0;
        }

        sort(intervals.begin(),intervals.end(),com);
        int count = 1;//默认第一个是1，从1开始
        int end = intervals[0][1];//初始end为第一个的数组的第二个结尾
        for(int i = 1; i < intervals.size(); i++)
        {
            if(end <= intervals[i][0])//只有不重叠的时候才将end更新，且计算需要几个数组
            {
                end = intervals[i][1];
                count++;
            }
            //如果存在重叠的则不更新，继续保持结尾里面小的，为了让后面可以放更多的数组
        }
        return intervals.size() - count;
    }
};