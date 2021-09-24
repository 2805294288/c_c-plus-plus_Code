class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> ret;
        if(size > num.size() || size < 1)
        {
            return ret;
        }
        vector<int> Windows;
        for(int j = 0; j <= num.size() - size; j++)
        {
            Windows.clear();
            for(int m = j; m < j + size; m++)
            {
                Windows.push_back(num[m]);
            }
            int max = Windows[0];
            for(auto& n:Windows)
            {
                if(n > max)
                {
                    max = n;
                }
            }
            ret.push_back(max);
        }
        return ret;
    }
};