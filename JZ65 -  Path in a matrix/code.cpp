class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param matrix char字符型vector<vector<>> 
     * @param word string字符串 
     * @return bool布尔型
     */
    void Func(int& flag,vector<vector<bool>>& used, int& x, int& y, int i, int j,string st,vector<vector<char> >& matrix, string& word)
    {
        if(st == word)
        {
             flag = 1;
             return;
        }
        
        if(used[i][j] == false || i < 0 || j < 0 || i >= x || j >= y || st[st.size()-1] != word[st.size()-1])
        {
            return;
        }
        
            used[i][j] = false;
            
            Func(flag,used,x,y,i+1,j,st + matrix[i][j],matrix,word);
            Func(flag,used,x,y,i,j+1,st + matrix[i][j],matrix,word);
            Func(flag,used,x,y,i-1,j,st + matrix[i][j],matrix,word);
            Func(flag,used,x,y,i,j-1,st + matrix[i][j],matrix,word);
            
            used[i][j] = true;
    }
    
    bool hasPath(vector<vector<char> >& matrix, string word) {
        int x = matrix.size();
        int y = matrix[0].size();
        for(int i = 0; i < x; i++)
        {
            for(int j = 0; j < y; j++)
            {
                if(matrix[i][j] == word[0])
                {
                    string st;
                    vector<vector<bool>> used(x,vector<bool> (y,true));
                    int flag = 0;
                    Func(flag,used,x,y,i,j,st,matrix,word);
                    if(flag == 1)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};