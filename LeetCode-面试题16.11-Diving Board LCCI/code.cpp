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

        int shortercount = k;
        int longercount = 0;
        

        while(k>=0)
        {
            sum = 0;

                for(int i=0; i<shortercount; i++)
                {
                    sum +=  shorter;
                }
            
                for(int i=0; i<longercount; i++)
                {
                    sum += longer;
                }
            
    
            nums.push_back(sum);
            shortercount--;
            longercount++;
            k--;
        }

        return nums;
    }
};