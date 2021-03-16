class Solution {
public:
    bool judgeCircle(string moves) {
        int Rcount = 0;
        int Lcount = 0;
        int Ucount = 0;
        int Dcount = 0;

        for(auto x:moves)
        {
            if(x=='R')
            {
                Rcount++;
            }
            else if(x=='L')
            {
                Lcount++;
            }
            else if(x=='U')
            {
                Ucount++;
            }
            else if(x=='D')
            {
                Dcount++;
            }
        }

        if(Rcount == Lcount && Ucount == Dcount)
        {
            return true;
        }
        else
        {
            return false;
        } 
    }
};