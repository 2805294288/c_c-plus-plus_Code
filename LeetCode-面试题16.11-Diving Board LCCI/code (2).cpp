class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> nums;
        long sum  = 0;
        
        if(k==0)
        {
            return nums;
        }
        
        if(shorter == longer)
        {
            sum = shorter*k;
            nums.push_back(sum);
            return nums;
        }

        int i = k;
        int j = 0;
        
        for(i=k; i>=0; i--,j++)
        {
            sum = shorter*(i) + longer*(j);
            nums.push_back(sum);
        }

        return nums;
    }
};