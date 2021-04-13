class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int PushSize = 0;
        int PopSize = 0;
        stack<int> st;
        
        while(PushSize < pushV.size())
        {
            while(PushSize < pushV.size() && pushV[PushSize] != popV[PopSize])
            {
                st.push(pushV[PushSize]);
                PushSize++;
            }
            
            if(pushV[PushSize] == popV[PopSize])
            {
                PushSize++;
                PopSize++;
            }
            
            while(!st.empty() && st.top() == popV[PopSize])
            {
                st.pop();
                PopSize++;
            }
        }
        
        if(st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};