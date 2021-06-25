class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        vector<int> ret(index+1,1);
        int p1 = 0;
        int p2 = 0;
        int p3 = 0;
        int ret1 = 0,ret2 = 0, ret3 = 0;
        for(int i = 1; i < ret.size(); i++)
        {
            ret1 = ret[p1] * 2;
            ret2 = ret[p2] * 3;
            ret3 = ret[p3] * 5;
            
            ret[i] = min(min(ret1,ret2),ret3);
            
            if(ret[i] == ret1)
                p1++;
            if(ret[i] == ret2)
                p2++;
            if(ret[i] == ret3)//不使用else if主要是为了有重复的则都进行++；避免只加一个
                p3++;
        }
        return ret[index-1];
    }
};