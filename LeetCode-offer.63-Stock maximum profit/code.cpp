//2.对数组进行一遍遍历
//遍历的时候从前往后先保留最小的
//如果遇到比最小的大的就算利润，保留利润里面最大的。            
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int D_value = 0;
        int res = 0;

        if(size <  2)//如果个数小于两个利润为零
        {
            return res;
        }

        int min = prices[0];//默认初始min为第一个
        for(auto x: prices)
        {
            if(x < min)//遍历时保留最小的
            {
                min = x;
            }
            else if(x > min)//如果遇到比最小的大的就算利润，保留利润里面最大的。
            {
                D_value = x - min;
                if(D_value > res)//保留最大利润
                
                {
                    res = D_value;
                }
            }
        }
        return res;
    }
};