 //先采用计数的方法对deck中相同元素进行统计
//然后从2开始到统计到里面最小的个数
//求新数组统计所有个数的公约数

class Solution {
public: 
    bool hasGroupsSizeX(vector<int>& deck) {
        int size = deck.size();
        vector<int> nums(size,0);

        sort(deck.begin(),deck.end());
        int min = deck[0];

        for(int i=0; i<size; i++)
        {
            nums[deck[i]-min]++;
        }

        int maxcount = 0;
        for(int i=0; i<size; i++)
        {
            if(nums[i]>maxcount)
            {
                maxcount = nums[i];
            }
        }

        int mincount = maxcount;
        for(int i=0; i<size; i++)
        {
            if(nums[i]<mincount && nums[i]>0)
            {
                mincount = nums[i];
            }
        }
        if(mincount == 1)
        {
            return false;
        }

        int number = 0;
        int state = 0;
        for(int number=2; number<=mincount; number++)
        {
            state = 0;
            for(int i=0; i<size; i++)
            {
                if(nums[i]%number != 0)
                {
                    state = 1;
                    break;
                }
            }
            if(state==0)
            {
                return true;
            }
        }
        return false;
    }
};