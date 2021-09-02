class Solution {
public:
    int balancedStringSplit(string s) {
        int Lcount=0;
        int Rcount=0;
        int count = 0;
        for(auto ch:s)
        {
            if(ch == 'R')
            {
                Rcount++;
            }
            if(ch == 'L')
            {
                Lcount++;
            }
            if(Rcount == Lcount)
            {
                count ++;
            }
        }
        return count;
    }
};