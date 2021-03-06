class Solution {
public:
    int minCount(vector<int>& coins) {
        int size=coins.size();//先求出里面的元素个数
        int number = 0;
        int count =  0;//用来记录次数

        for(int i=0; i<size; i++)
        {
            number = coins[i];//number为数组里面的每个数     
            while(number>0)//大于零的时候执行循环
            {
                count++;
                number -= 2;
            }
        }

        return count;
    }
};