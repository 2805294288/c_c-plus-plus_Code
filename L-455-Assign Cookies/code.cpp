class Solution {
public:
    //经典的贪心算法题目
    //有胃口大小和饼干大小
    //由局部到全部，最大的饼干给胃口最大孩子，这样就能保证满足最多孩子分配到
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int index = s.size()-1;//饼干从最后一个开始
        int count = 0;
        sort(g.begin(),g.end());//先将胃口和饼干大小由小到大排序
        sort(s.begin(),s.end());//然后从前往后遍历
        for(int i=g.size()-1; i>=0; i--)
        {
            if(index >=0 && s[index] >= g[i]) //index>=0是因为如果孩子多饼干少且一直是满足的，可能会减到小于0；越界
            {
                count++;//满足饼干比胃口大在计数
                index--;//满足一种情况以后，饼干减小一个
            }
        }
        return count;
    }
};