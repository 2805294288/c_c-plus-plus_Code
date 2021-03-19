class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        int total = 0;

        for(auto x:nums)
        {
            count = 0;
            while(x)
            {
                count++;
                x= x / 10;
            }

            if(count % 2 == 0)
            {
                total++;
            }
        }
        return total;
    }
};