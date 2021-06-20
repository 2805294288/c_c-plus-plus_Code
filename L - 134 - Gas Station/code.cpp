class Solution {
public:
//贪心算法
//从某一个位置开始往后走，看是否可以环绕一周
//首先保证加的油要比消耗的油多，判断是否可以走完一圈的标准就是看加的油和差值总和是否大于零
//先假设从0位置开始走，如果往后走的和小于零则起点肯定不是在i以及i之前因为出现了断层，所以只可能是i+1的位置开始的。
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int Dif = 0;
        int sum = 0;
        int index = 0;
        int p_sum = 0;
        for(int i = 0; i < gas.size(); i++)
        {
            Dif = gas[i] - cost[i];
            p_sum += Dif;
            sum += Dif;

            if(p_sum < 0)
            {
                index = i + 1;
                p_sum = 0;
            }
        }
        if(sum < 0)
        {
            return -1;
        }
        else
        {
            return index;
        }
    }
};