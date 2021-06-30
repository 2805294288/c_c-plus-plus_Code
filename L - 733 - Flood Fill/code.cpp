class Solution {
public:
    void DFS(vector<vector<int>>& image,int sr, int sc,int& newColor, int state)
    {
        if(sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] == newColor || image[sr][sc] != state)
        {
            return;
        }
        image[sr][sc] = newColor;
        DFS(image,sr-1,sc,newColor,state);
        DFS(image,sr,sc+1,newColor,state);
        DFS(image,sr+1,sc,newColor,state);
        DFS(image,sr,sc-1,newColor,state); 
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image.size() ==0 || image[sr][sc] == newColor)
        {
            return image;
        }
        int state = image[sr][sc]; 
        DFS(image,sr,sc,newColor,state);
        return image;
    }
};