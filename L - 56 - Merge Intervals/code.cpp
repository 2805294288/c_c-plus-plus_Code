class Solution {
public:
    static bool com(const vector<int>& a, const vector<int>& b)
    {
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        if(intervals.size() < 2)
        {
            return intervals;
        }
        sort(intervals.begin(),intervals.end(),com); 
        
        int state = 0;
        for(int i = 1; i < intervals.size(); i++)
        {
            int start = intervals[i-1][0];
            int end = intervals[i-1][1];
            while(i < intervals.size() && intervals[i][0] <= end)
            {
                end = max (end, intervals[i][1]);
                if(i == intervals.size() - 1)
                {
                    state = 1;
                }
                i++;
            }

            ret.push_back({start,end});
        }
        if(state == 0)
        {
            ret.push_back({intervals[intervals.size()-1][0],intervals[intervals.size()-1][1]});
        }
        return ret;
    }
};






