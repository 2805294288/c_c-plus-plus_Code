class Solution {
public:
    string removeKdigits(string num, int k) {
        string ret;

        for(auto& c:num)//取当前字符，如果当前字符得之前还有比我大的都删除
        {
           while(k && !ret.empty() && ret.back() > c)//删除K个数字，且保证不为空，且最后一个比当前字符大。
           {
               ret.pop_back();//如果满足前一个比后一个大则删除后一个
               k--;
           } 
           ret.push_back(c);
        }

        while(k--)//k还没结束，有可能是升序，则删除后面几个
        {
            ret.pop_back();
        }

        while(!ret.empty() && ret[0] == '0')//删除前面为O的
        {
            ret.erase(ret.begin());
        }
        
        if(ret.empty())
        {
            ret = "0";
        }

        return ret;
    }
};