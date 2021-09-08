class Solution {
public:
    string generateTheString(int n) {
        string ret;
        if(n % 2 == 0)
        {
            ret.resize(n-1,'a');
            ret += 'b';
            return ret;
        }
        else
        {
            ret.resize(n,'a');
            return ret;
        }
    }
};