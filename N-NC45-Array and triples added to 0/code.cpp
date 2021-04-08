class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(),num.end());
        int number  = 0;
        int i = 0;
        for(i=0; i<num.size(); i++)
        {
            if(num[i] > 0)
            {
                break;
            }
        }
        vector<vector<int>> ret;
        int state = 0;
        for(int j=0; j<i; j++)
        {
            number = 0 - num[j];
            for(int m=j+1; m<num.size(); m++)
            {
                for(int n=m+1; n<num.size(); n++)
                {
                    if(num[m] + num[n] == number)
                    {
                        vector<int> ret1;
                        ret1.push_back(num[j]);
                        ret1.push_back(num[m]);
                        ret1.push_back(num[n]);
                        state = 0;
                        for(auto x:ret)
                        {
                            if(ret1 == x)
                            {
                                state = 1;
                                break;
                            }
                        }
                        if(state == 0)
                        {
                        ret.push_back(ret1);
                        }
                    }
                }
            }
        }
        return ret;
    }
};

