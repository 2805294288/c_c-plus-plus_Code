class Solution {
public:
    bool Judge(string& s)
    {
        int head = 0;
        int tail = s.size() - 1;
        while(head < tail)
        {
            if(s[head] != s[tail])
            {
                return false;
            }
            head++;
            tail--;
        }
        return true;
    }

    void Func(string& s, int state)
    {
        if(state == s.size())
        {
            ret.push_back(path);
            return;
        }
        
        for(int i = state; i < s.size(); i++)
        {
            string s1 = s.substr(state,i-state+1);
            if(Judge(s1))
            {
                path.push_back(s1);
                Func(s,i+1);
                path.pop_back();
            }
            else
            {
                continue;
            }
        }
    }

    vector<vector<string>> partition(string s) {
        Func(s,0);
        return ret;
    }
private:
    vector<vector<string>> ret;
    vector<string> path;
};